#pragma once
#include <iostream>
#include <plog/Log.h>
#ifndef HS_PLATFORM_WINDOWS
	#error Histroy is Windows only!
#endif // !HS_PLATFORM_WINDOWS

#define HS_ASSERT(statement, cond) if(statement == cond) {__debugbreak();}

#define HS_SET_LOG_DIR(severity, dir, size, files) plog::init(severity, dir, size, files)
#define HS_INFO(msg) PLOG_INFO << msg
#define HS_DEBUG(msg) PLOG_DEBUG << msg
#define HS_WARNING(msg) PLOG_WARNING << msg
#define HS_ERROR(msg) PLOG_ERROR << msg
#define HS_FATAL(msg) PLOG_FATAL << msg