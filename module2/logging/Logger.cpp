#include "Logger.h"


std::string Logger::getLogLevel(LogLevel level) {

	std::string level_msg = "";

	switch (level)
	{
	case LogLevel::INFO:
	{

		level_msg = "[INFO]:";
		break;

	}
	case LogLevel::TRACE:
	{
		level_msg = "[TRACE]:";
		break;
	}
	case LogLevel::DEBUG:
	{
		level_msg = "[DEBUG]:";
		break;
	}
	case LogLevel::WARN:
	{
		level_msg = "[WARN]:";
		break;
	}
	case LogLevel::CRITICAL:
	{
		level_msg = "[CRITICAL]:";
		break;
	}
	case LogLevel::ERROR:
	{
		level_msg = "[ERROR]:";
		break;
	}
	}
	return level_msg;
}


void Logger::SetLogLevel(LogLevel level) {

	m_level = level;
}


void Logger::EnableLogging(const char* file_path) {

	m_file_path = file_path;


	if (!_access(file_path, 0)) {
		printf("Log file exists\n");
	}
	else
	{
		printf("Log file dont exists , create a new one");
	}

	file_output = fopen(file_path,"w+");

	if (!file_output) {
		printf("Error trying to open the log file , exit the operation \n");
	}
	else
	{
		printf("File logging is enabled at path = %s\n",file_path);
	}

}
void Logger::DisableLogging()
{
	if (!file_output) {

		printf("File at path = %s, was not opened to close it\n",m_file_path.c_str());
		
	}
	else
	{
		fclose(file_output);
		printf("File closed successfully.\n");
	}




}



LogLevel Logger::m_level = LogLevel::INFO;
std::mutex Logger::mutex;
FILE* Logger::file_output = nullptr;
std::string Logger::m_file_path = "";