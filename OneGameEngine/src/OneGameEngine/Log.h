#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace OneGameEngine {

	class OGE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define OGE_CORE_TRACE(...)    ::OneGameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OGE_CORE_INFO(...)     ::OneGameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OGE_CORE_WARN(...)     ::OneGameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OGE_CORE_ERROR(...)    ::OneGameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OGE_CORE_FATAL(...)    ::OneGameEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define OGE_TRACE(...)         ::OneGameEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OGE_INFO(...)          ::OneGameEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define OGE_WARN(...)          ::OneGameEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OGE_ERROR(...)         ::OneGameEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define OGE_FATAL(...)         ::OneGameEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)