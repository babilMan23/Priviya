#pragma once

#include "../Core.h"
#include <spdlog/spdlog.h>

namespace Priviya {
	class Logger {
	public:
		static void Init();

		static PV_REF<spdlog::logger>& GetLogger() { return m_Logger; }
	private:
		static PV_REF<spdlog::logger> m_Logger;
	};
}

#define PV_INFO(...) ::Priviya::Logger::GetLogger()->info(__VA_ARGS__)
#define PV_WARN(...) ::Priviya::Logger::GetLogger()->warn(__VA_ARGS__)
#define PV_ERROR(...) ::Priviya::Logger::GetLogger()->error(__VA_ARGS__)
#define PV_CRITICAL(...) ::Priviya::Logger::GetLogger()->critical(__VA_ARGS__)