#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<mutex>
#include<io.h>

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
	static std::string getLogLevel(LogLevel level);
	static std::mutex mutex;

	static FILE* file_output;
	static std::string m_file_path;

public:

	static void SetLogLevel(LogLevel level);
	static void EnableLogging(const char *file_path);
	static void DisableLogging();

	template <typename... Args>
	static void LogMsg(LogLevel level, const char* message, Args... args)
	{
		std::lock_guard<std::mutex> lock(mutex); //This will unlock the mutex as soon the scope is gone.

		if (m_level <= level) {

			printf(getLogLevel(level).c_str());
			printf(message, args...);
			printf("\n");

			fprintf(file_output, getLogLevel(level).c_str());
			fprintf(file_output, message, args...);
			fprintf(file_output,"\n");

		}

	}

	template <typename... Args>
	static void InfoLog(const char* message, Args... args)
	{
		LogMsg(INFO, message, args...);
	}
	
	template <typename... Args>
	static void TraceLog(const char* message, Args... args)
	{
		LogMsg(TRACE, message, args...);
	}

	template <typename... Args>
	static void DebugLog(const char* message, Args... args)
	{
		LogMsg(DEBUG, message, args...);
	}

	template <typename... Args>
	static void WarnLog(const char* message, Args... args)
	{
		LogMsg(WARN, message, args...);
	}

	template <typename... Args>
	static void CriticalLog(const char* message, Args... args)
	{
		LogMsg(CRITICAL, message, args...);
	}

	template <typename... Args>
	static void ErrorLog(const char* message, Args... args)
	{
		LogMsg(ERROR, message, args...);
	}


};

