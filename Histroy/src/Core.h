#pragma once
#ifndef HS_PLATFORM_WINDOWS
	#error Histroy is Windows only!
#endif // !HS_PLATFORM_WINDOWS

#define HS_ASSERT(statement, cond) if(statement == cond) {__debugbreak();}