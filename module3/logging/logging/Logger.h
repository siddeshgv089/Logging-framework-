#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>
#include<string>
#include<mutex>
#include <time.h>
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

	LogLevel m_level;
	std::mutex mutex;
	FILE* file_output;
	std::string m_file_path;


public:

	static Logger& getInstance() {

		static Logger logger;
		return logger;
	}

	void SetLogLevel(LogLevel level);
	void EnableLogging(const char *file_path);
	void DisableLogging();
	std::string getLogLevel(LogLevel level);


	template <typename... Args>
	void LogMsg(LogLevel level, const char* message, Args... args)
	{
		std::lock_guard<std::mutex> lock(mutex); //This will unlock the mutex as soon the scope is gone.

		time_t ltime; /* calendar time */
		ltime = time(NULL); /* get current cal time */
		char* datetime = asctime(localtime(&ltime));
		datetime[strlen(datetime) - 1] = '\0';


		if (m_level <= level) {

			printf("[%s]:", datetime);
			printf(getLogLevel(level).c_str());
			printf(message, args...);
			printf("\n");

			fprintf(file_output, "[%s]:", datetime);
			fprintf(file_output, getLogLevel(level).c_str());
			fprintf(file_output, message, args...);
			fprintf(file_output, "\n");


		}

	}

	template <typename... Args>
	void InfoLog(const char* message, Args... args)
	{
		LogMsg(INFO, message, args...);
	}
	
	template <typename... Args>
	void TraceLog(const char* message, Args... args)
	{
		LogMsg(TRACE, message, args...);
	}

	template <typename... Args>
	void DebugLog(const char* message, Args... args)
	{
		LogMsg(DEBUG, message, args...);
	}

	template <typename... Args>
	void WarnLog(const char* message, Args... args)
	{
		LogMsg(WARN, message, args...);
	}

	template <typename... Args>
	void CriticalLog(const char* message, Args... args)
	{
		LogMsg(CRITICAL, message, args...);
	}

	template <typename... Args>
	void ErrorLog(const char* message, Args... args)
	{
		LogMsg(ERROR, message, args...);
	}


	Logger() { m_level = INFO; file_output = nullptr; };
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;


};

