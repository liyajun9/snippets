#ifndef SVR_TEMPLATE_BOAPP_H
#define SVR_TEMPLATE_BOAPP_H
#include <Ice/Ice.h>
#include <Ice/Service.h>
#include <IceUtil/IceUtil.h>
#include "ThreadGmqProcessor.h"


class BoApp : public Ice::Service
{
public:
    BoApp();
    ~BoApp();

private:
    virtual bool start(int argc, char** argv, int& status);
    virtual void interrupt();

private:
    bool Init();
    bool InitLog();
    bool ParseConfigFile();

private:
    Ice::CommunicatorPtr    m_ic;
    Ice::PropertiesPtr 		m_props;
    Ice::ObjectAdapterPtr   m_adapter;

    ThreadGmqProcessorPtr   m_threadGmqProcessor;
};


#endif //SVR_TEMPLATE_BOAPP_H
