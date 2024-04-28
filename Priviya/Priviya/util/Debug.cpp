#include "Debug.h"
#include "spdlog/sinks/stdout_color_sinks.h"

PV_REF<spdlog::logger> Priviya::Logger::m_Logger;

void Priviya::Logger::Init() {
	spdlog::set_pattern("%^[%T] %n: %v%$");
	m_Logger = spdlog::stdout_color_mt("Priviya");
	m_Logger->set_level(spdlog::level::trace);

	m_Logger->info("Logger initialized");
}
