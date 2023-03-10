#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Leviathan {


	class Log
	{
	public:
		
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

//CORE LOG MACROS
#define LE_CORE_FATAL(...)	::Leviathan::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define LE_CORE_ERROR(...)	::Leviathan::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LE_CORE_WARN(...)	::Leviathan::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LE_CORE_INFO(...)	::Leviathan::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LE_CORE_TRACE(...)	::Leviathan::Log::GetCoreLogger()->trace(__VA_ARGS__)

//CLIENT LOG MACROS
#define LE_FATAL(...)		::Leviathan::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define LE_ERROR(...)		::Leviathan::Log::GetClientLogger()->error(__VA_ARGS__)
#define LE_WARN(...)		::Leviathan::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LE_INFO(...)		::Leviathan::Log::GetClientLogger()->info(__VA_ARGS__)
#define LE_TRACE(...)		::Leviathan::Log::GetClientLogger()->trace(__VA_ARGS__)
