#pragma once

#ifdef RE_PLATFORM_WINDOWS
	#ifdef RE_BUILD_DLL
		#define RENGINE_API __declspec(dllexport)
	#else
		#define RENGINE_API __declspec(dllimport)
	#endif
#else
		#error Rengine only supports windows
#endif

#define BIT(x) (1 << x)