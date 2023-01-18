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

#ifdef RE_ENABLE_ASSERTS
	#define RE_ASSERT(x, ...) { if(!(x)){ RE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RE_CORE_ASSERT(x, ...) { if(!(x)){ RE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RE_ASSERT(x, ...)
	#define RE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)