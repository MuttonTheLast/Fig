#pragma once
#include "../Core.h"
#include "../figpch.h"
#include "spdlog/spdlog.h"

namespace Fig
{
	class FIG_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> GetMainLogger() { return s_MainLogger; }
		inline static std::shared_ptr<spdlog::logger> GetAppLogger() { return s_AppLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_MainLogger;
		static std::shared_ptr<spdlog::logger> s_AppLogger;
	};

}

#if defined(DEBUG_TOOLS) && DEBUG_TOOLS >= 1

// Main logger macros
#define FIG_CORE_ERROR(...)     ::Fig::Log::GetMainLogger()->error(__VA_ARGS__)
#define FIG_CORE_WARN(...)      ::Fig::Log::GetMainLogger()->warn(__VA_ARGS__)
#define FIG_CORE_INFO(...)      ::Fig::Log::GetMainLogger()->info(__VA_ARGS__)
#define FIG_CORE_TRACE(...)     ::Fig::Log::GetMainLogger()->trace(__VA_ARGS__)
#define FIG_CORE_FATAL(...)     ::Fig::Log::GetMainLogger()->fatal(__VA_ARGS__)

// Application logger macros
#define FIG_ERROR(...)          ::Fig::Log::GetAppLogger()->error(__VA_ARGS__)
#define FIG_WARN(...)           ::Fig::Log::GetAppLogger()->warn(__VA_ARGS__)
#define FIG_INFO(...)           ::Fig::Log::GetAppLogger()->info(__VA_ARGS__)
#define FIG_TRACE(...)          ::Fig::Log::GetAppLogger()->trace(__VA_ARGS__)
#define FIG_FATAL(...)          ::Fig::Log::GetAppLogger()->fatal(__VA_ARGS__)

#else

// Empty main logger macros
#define FIG_CORE_ERROR(...)
#define FIG_CORE_WARN(...)
#define FIG_CORE_INFO(...)
#define FIG_CORE_TRACE(...)
#define FIG_CORE_FATAL(...)

// Empty application logger macros
#define FIG_ERROR(...)
#define FIG_WARN(...)
#define FIG_INFO(...)
#define FIG_TRACE(...)
#define FIG_FATAL(...)

#endif
