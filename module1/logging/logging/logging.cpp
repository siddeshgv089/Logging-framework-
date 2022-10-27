// logging.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Logger.h"

int main()
{
    Logger::set_log_level(LogLevel::TRACE);
    Logger::InfoLog("infolog %d", 1);
    Logger::DebugLog("debuglog message %d", 2);
    Logger::CriticalLog("Logging a critical message");

    return 0;
}

