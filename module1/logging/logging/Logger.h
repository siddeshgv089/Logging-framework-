#pragma once

#include<stdio.h>

enum LogLevel {
	INFO,
	TRACE,
	DEBUG,
	WARN,
	CRITICAL,
	ERROR
};

class Logger
{

private :
	static LogLevel m_level;

public:

	static void set_log_level(LogLevel level) {

		m_level = level;
	}

	template <typename... Args>
	static void InfoLog(const char* message, Args... args)
	{
		if (m_level <= LogLevel::INFO) {

			printf("[INFO]:\t");
			printf(message, args...);
			printf("\n");
		}
	}
	
	template <typename... Args>
	static void TraceLog(const char* message, Args... args)
	{
		if (m_level <= LogLevel::TRACE) {

			printf("[TRACE]:\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template <typename... Args>
	static void DebugLog(const char* message, Args... args)
	{
		if (m_level <= LogLevel::DEBUG) {

			printf("[DEBUG]:\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template <typename... Args>
	static void WarnLog(const char* message, Args... args)
	{
		if (m_level <= LogLevel::WARN) {

			printf("[WARN]:\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template <typename... Args>
	static void CriticalLog(const char* message, Args... args)
	{
		if (m_level <= LogLevel::CRITICAL) {

			printf("[CRITICAL]:\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template <typename... Args>
	static void ErrorLog(const char* message, Args... args)
	{
		if (m_level <= LogLevel::ERROR) {

			printf("[ERROR]:\t");
			printf(message, args...);
			printf("\n");
		}
	}


};

