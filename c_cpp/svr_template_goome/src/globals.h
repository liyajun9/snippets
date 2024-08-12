#ifndef SVR_TEMPLATE_GLOBALS_H
#define SVR_TEMPLATE_GLOBALS_H

#include <gmapp.h>
#include "typedef.h"
#include "Log.h"
#include "TraceThread.h"

extern log4cxx::LoggerPtr g_logger;
extern AppConfig g_conf;
extern CGMApp* g_pTracer;

#endif //SVR_TEMPLATE_GLOBALS_H

