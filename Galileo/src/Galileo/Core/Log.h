#pragma once
#include"glpch.h"
#include"Core.h"
#include"spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include"spdlog/fmt/ostr.h"
namespace Galileo {
	class GALILEO_API Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


#define GL_CORE_WARN(...)	::Galileo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GL_CORE_ERROR(...)	::Galileo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GL_CORE_INFO(...)	::Galileo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GL_CORE_TRACE(...)	::Galileo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GL_CORE_CRITICAL(...) ::Galileo::Log::GetCoreLogger()->critical(__VA_ARGS__)


#define GL_WARN(...)	::Galileo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GL_ERROR(...)	::Galileo::Log::GetClientLogger()->error(__VA_ARGS__)
#define GL_INFO(...)	::Galileo::Log::GetClientLogger()->info(__VA_ARGS__)
#define GL_TRACE(...)	::Galileo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GL_CRITICAL(...) ::Galileo::Log::GetClientLogger()->critical(__VA_ARGS__)
