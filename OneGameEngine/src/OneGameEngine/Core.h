#pragma once

#ifdef OGE_PLATFORM_WINDOWS
	#ifdef OGE_BUILD_DLL
		#define OGE_API __declspec(dllexport)
	#else
		#define OGE_API __declspec(dllimport)
	#endif
#else
	#error OneGameEngine only supports Windows!
#endif // OGE_PLATFORM_WINDOWS

