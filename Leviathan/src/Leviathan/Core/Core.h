#pragma once

#include <memory>

/// PLATFORM DETECTION ///////////////////////////////////////
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)

#ifdef _WIN64
	#ifndef RE_PLATFORM_WINDOWS
	#define RE_PLATFORM_WINDOWS
	#endif
#else
   
#endif
#elif __APPLE__
	#include <TargetConditionals.h>
	#if TARGET_IPHONE_SIMULATOR
		#error "Platform Not Supported"// iOS, tvOS, or watchOS Simulator
	#elif TARGET_OS_MACCATALYST
		#error "Platform Not Supported"// Mac's Catalyst (ports iOS API into Mac, like UIKit).
	#elif TARGET_OS_IPHONE
		#error "Platform Not Supported"// iOS, tvOS, or watchOS device
	#elif TARGET_OS_MAC
		#define RE_PLATFORM_MACOS
		// Other kinds of Apple platforms
	#else
		#error "Unknown Apple platform"
	#endif
#elif __ANDROID__
	#error "Platform Not Supported"
	// Below __linux__ check should be enough to handle Android,
	// but something may be unique to Android.
#elif __linux__
	#error "Platform Not Supported"// linux
#elif __unix__ // all unices not caught above
	#error "Platform Not Supported"// Unix
#elif defined(_POSIX_VERSION)
	#error "Platform Not Supported"// POSIX
#else
	#error "Unknown compiler"
#endif

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifdef RE_ENABLE_ASSERTS
	#define RE_ASSERT(x, ...) { if(!(x)){ RE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RE_CORE_ASSERT(x, ...) { if(!(x)){ RE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RE_ASSERT(x, ...)
	#define RE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define RE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Leviathan {

	template<typename T>
	using Unique = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Unique<T> CreateUnique(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}