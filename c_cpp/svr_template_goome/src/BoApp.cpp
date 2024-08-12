#include <RedisOp.h>
#include <GudOp.h>
#include "BoApp.h"
#include "globals.h"
#include "gmqdirectI.h"

BoApp::BoApp()
{
}

BoApp::~BoApp()
{
}

bool BoApp::start(int argc, char** argv, int& status)
{
    if (!Init())
    {
        return false;
    }

    std::string enpoint = "tcp -h * -p " + ToString(g_conf.listenPort);
    MYLOG_INFO(g_logger, "createAdapter:endpoint(%s)", enpoint.c_str());

    try
    {
        m_adapter = m_ic->createObjectAdapterWithEndpoints(g_conf.strAdapterName, enpoint);

        GMQDirectSendIPtr gmqDirectSendPtr = new GMQDirectSendI();
        m_adapter->add(gmqDirectSendPtr, m_ic->stringToIdentity("GMQDirect"));
        m_adapter->activate();
    }
    catch(const Ice::Exception& ex)
    {
        MYLOG_ERROR(g_logger, "initialize xxx exception: %s", ex.what());
        return false;
    }
    catch(const char* msg)
    {
        MYLOG_ERROR(g_logger, "initialize xxx error msg: %s", msg);
        return false;
    }

    m_threadGmqProcessor = new ThreadGmqProcessor(g_conf.nMsgWarningThreshold);
    m_threadGmqProcessor->start();

    MYLOG_INFO(g_logger, "Start xxx sucessful");
    status = EXIT_SUCCESS;
    return true;
}

bool BoApp::Init()
{
    if (!InitLog())
    {
        return false;
    }
    try
    {
        m_ic    = communicator();
        m_props = m_ic->getProperties();
    }
    catch (const Ice::Exception& ex)
    {
        MYLOG_ERROR(g_logger, "Ice::Exception: %s", ex.what());
        return false;
    }

    if (!ParseConfigFile())
    {
        MYLOG_ERROR(g_logger, "ParseConfigFile failed");
        return false;
    }

    GoomeTrace::initTraceApp(g_conf.strMyGnsName, "", g_conf.listenPort, g_logger);

    RedisOp::SetMyGnsName(g_conf.strMyGnsName);
    RedisOp::SetGpsboxRedisGnsName(g_conf.strRedisGnsName);
    GudOp::SetMyGnsName(g_conf.strMyGnsName);
    GudOp::SetGudGnsName(g_conf.strGudGnsName);

    return true;
}

bool BoApp::InitLog()
{
    g_logger = MYLOG_INIT(LOG4CXX_CFGFILE, NULL, CLog::EINFO);
    setlocale(LC_ALL, "en_US.UTF-8");
    if (NULL == g_logger)
    {
        printf("Init log fail!");
        return false;
    }

    return true;
}

bool BoApp::ParseConfigFile()
{
    Ice::StringSeq strSeq;
    GET_CONF_INT("ListenPort", g_conf.listenPort);
    GET_CONF_STR("MyGnsName", g_conf.strMyGnsName);
    GET_CONF_STR("RedisGnsName", g_conf.strRedisGnsName);
    GET_CONF_STR("GudGnsName", g_conf.strGudGnsName);

    GET_CONF_STR("AdapterName", g_conf.strAdapterName);
    GET_CONF_INT_DEF("MsgWarningThreshold", g_conf.nMsgWarningThreshold, 5000);

    MYLOG_INFO(g_logger, "ListenPort = %d", g_conf.listenPort);
    MYLOG_INFO(g_logger, "MyGnsName = %s", g_conf.strMyGnsName.c_str());
    MYLOG_INFO(g_logger, "RedisGnsName = %s", g_conf.strRedisGnsName.c_str());
    MYLOG_INFO(g_logger, "GudGnsName = %s", g_conf.strGudGnsName.c_str());
    MYLOG_INFO(g_logger, "AdapterName = %s", g_conf.strAdapterName.c_str());
    MYLOG_INFO(g_logger, "MsgWarningThreshold = %d", g_conf.nMsgWarningThreshold);

    return true;
}

void BoApp::interrupt()
{
    if (m_adapter)
    {
        m_adapter->deactivate();
    }

    if (m_threadGmqProcessor)
    {
        m_threadGmqProcessor->stop();
    }

    Ice::Service::interrupt();
    MYLOG_INFO(g_logger, "xxx interrupt");
}

