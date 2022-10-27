// logging.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Logger.h"
#include<thread>

void setlog()
{
    const char* debug_msg = "debug msg";
    const char* critical = "critical";

    Logger::getInstance().LogMsg(INFO,"Info message %d",1);
    Logger::getInstance().LogMsg(DEBUG, "Debugging messsage %s", debug_msg);
    Logger::getInstance().LogMsg(CRITICAL, "patient with name %s admitted to hospital", critical);
    Logger::getInstance().LogMsg(ERROR, "Error occurred while executing function , please check if the installation path of the binary and retry the operation");

}



int main()
{

   /* Logger::set_log_level(LogLevel::TRACE);
    Logger::InfoLog("infolog %d", 1);
    Logger::DebugLog("debuglog message %d", 2);
    Logger::CriticalLog("Logging a critical message");
    */


    Logger::getInstance().EnableLogging(".log.txt");


    std::thread threads[5];

    for (int i = 0; i < 5; i++) {

        threads[i] = std::thread(&setlog);
    }

    for (int i = 0; i < 5; i++) {

        threads[i].join();
    }

    Logger::getInstance().DisableLogging();

    return 0;
}

