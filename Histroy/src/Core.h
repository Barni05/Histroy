#pragma once
#include <iostream>
#include <plog/Log.h>
#include "Engine/Events/Event.h"
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

#define HS_INFO_DEF(msg) HS_SET_LOG_DIR(plog::warning, "F:\\DEV\\Projektek\\Histroy Engine\\Histroy\\Logs\\Logs.txt", 10000, 1);\
							HS_INFO(msg);	
#define HS_DEBUG_DEF(msg) HS_SET_LOG_DIR(plog::warning, "F:\\DEV\\Projektek\\Histroy Engine\\Histroy\\Logs\\Logs.txt", 10000, 1);\
							HS_DEBUG(msg);	
#define HS_WARNING_DEF(msg) HS_SET_LOG_DIR(plog::warning, "F:\\DEV\\Projektek\\Histroy Engine\\Histroy\\Logs\\Logs.txt", 10000, 1);\
							HS_WARNING(msg);	
#define HS_ERROR_DEF(msg) HS_SET_LOG_DIR(plog::warning, "F:\\DEV\\Projektek\\Histroy Engine\\Histroy\\Logs\\Logs.txt", 10000, 1);\
							HS_ERROR(msg);	
#define HS_FATAL_DEF(msg) HS_SET_LOG_DIR(plog::warning, "F:\\DEV\\Projektek\\Histroy Engine\\Histroy\\Logs\\Logs.txt", 10000, 1);\
							HS_FATAL(msg);	
#define BOTTOM_VIEWPORT_DISTANCE 540
