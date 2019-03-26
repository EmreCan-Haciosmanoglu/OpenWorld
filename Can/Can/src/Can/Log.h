#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Can
{
	class CAN_API Log
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

//Core log macros
#define CAN_CORE_TRACE(...) ::Can::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CAN_CORE_INFO(...)  ::Can::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CAN_CORE_WARN(...)  ::Can::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CAN_CORE_ERROR(...) ::Can::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CAN_CORE_FATAL(...) ::Can::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define CAN_TRACE(...)      ::Can::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CAN_INFO(...)       ::Can::Log::GetClientLogger()->info(__VA_ARGS__)
#define CAN_WARN(...)       ::Can::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CAN_ERROR(...)      ::Can::Log::GetClientLogger()->error(__VA_ARGS__)
#define CAN_FATAL(...)      ::Can::Log::GetClientLogger()->fatal(__VA_ARGS__)