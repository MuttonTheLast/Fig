#include "figpch.h"
#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>
namespace Fig
{
	std::shared_ptr<spdlog::logger> Log::s_MainLogger;
	std::shared_ptr<spdlog::logger> Log::s_AppLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_MainLogger = spdlog::stdout_color_mt("FIG");
		s_MainLogger->set_level(spdlog::level::trace);
		s_AppLogger = spdlog::stdout_color_mt("APP");
		s_AppLogger->set_level(spdlog::level::trace);
	}

}