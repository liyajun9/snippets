#ifndef SVR_TEMPLATE_TYPEDEF_H
#define SVR_TEMPLATE_TYPEDEF_H

#define LOG4CXX_CFGFILE  		"../etc/log4cxx.cfg"

typedef struct _AppConfig
{
    std::string strMyGnsName;
    int listenPort;
    std::string strRedisGnsName;
    std::string strGudGnsName;
    std::string strAdapterName;

    int nMsgWarningThreshold;
} AppConfig;

#define GET_CONF_STR(key, val) do \
{ \
    val = m_props->getProperty(key); \
    if (val.empty()) \
    { \
    MYLOG_WARN(g_logger, "empty config: %s", key); \
    return false; \
    } \
} while (0)

#define GET_CONF_STR_DEF(key, val, default) do \
{ \
    val = m_props->getPropertyWithDefault(key, default); \
} while (0)

#define GET_CONF_INT(key, val) do \
{ \
    val = m_props->getPropertyAsInt(key); \
} while (0)

#define GET_CONF_INT_DEF(key, val, default) do \
{ \
    val = m_props->getPropertyAsIntWithDefault(key, default); \
}while(0)

#define GET_CONF_STRSEQ(key, val) do \
{ \
    val = m_props->getPropertyAsList(key); \
} while (0)

#endif //SVR_TEMPLATE_TYPEDEF_H
