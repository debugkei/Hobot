#pragma once

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include<htpch.h>

#include"Core.h"

namespace Hobot {
  class HOBOT_API Logger {
  private:
    ~Logger();
    Logger();
  public:
    template<class...TArgs>
    static void LogToConsole(const std::string& preinfo, const std::string& color, TArgs&&...);
  };
}

//Logging from engine

//Log info to console, default text color applied
#define CORE_LOG_INFO(...)    Hobot::Logger::LogToConsole("Hobot Info", "\033[0m", __VA_ARGS__)
//Log warning to console, yellow color applied
#define CORE_LOG_WARNING(...) Hobot::Logger::LogToConsole("Hobot Warning", "\033[33m", __VA_ARGS__)
//Log error to console, red color applied
#define CORE_LOG_ERROR(...)   Hobot::Logger::LogToConsole("Hobot Error", "\033[31m", __VA_ARGS__)
//Log success to console, green color applied
#define CORE_LOG_SUCCESS(...) Hobot::Logger::LogToConsole("Hobot Success", "\033[32m", __VA_ARGS__)

//Logging from client

//Log info to console, default text color applied
#define LOG_INFO(...)         Hobot::Logger::LogToConsole("App Info", "\033[0m", __VA_ARGS__)
//Log warning to console, yellow color applied
#define LOG_WARNING(...)      Hobot::Logger::LogToConsole("App Warning", "\033[33m", __VA_ARGS__)
//Log error to console, red color applied
#define LOG_ERROR(...)        Hobot::Logger::LogToConsole("App Error", "\033[31m", __VA_ARGS__)
//Log success to console, green color applied
#define LOG_SUCCESS(...)      Hobot::Logger::LogToConsole("App Success", "\033[32m", __VA_ARGS__)

#endif // _LOGGER_H_