#pragma once

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include<memory>
#include<string>

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
#define HOBOT_CORE_CWInfo(...)    Hobot::Logger::LogToConsole("Hobot Info", "\033[0m", __VA_ARGS__)
//Log warning to console, yellow color applied
#define HOBOT_CORE_CWWarning(...) Hobot::Logger::LogToConsole("Hobot Warning", "\033[33m", __VA_ARGS__)
//Log error to console, red color applied
#define HOBOT_CORE_CWError(...)   Hobot::Logger::LogToConsole("Hobot Error", "\033[31m", __VA_ARGS__)
//Log success to console, green color applied
#define HOBOT_CORE_CWSuccess(...) Hobot::Logger::LogToConsole("Hobot Success", "\033[32m", __VA_ARGS__)

//Logging from client

//Log info to console, default text color applied
#define HOBOT_CWInfo(...)         Hobot::Logger::LogToConsole("App Info", "\033[0m", __VA_ARGS__)
//Log warning to console, yellow color applied
#define HOBOT_CWWarning(...)      Hobot::Logger::LogToConsole("App Warning", "\033[33m", __VA_ARGS__)
//Log error to console, red color applied
#define HOBOT_CWError(...)        Hobot::Logger::LogToConsole("App Error", "\033[31m", __VA_ARGS__)
//Log success to console, green color applied
#define HOBOT_CWSuccess(...)      Hobot::Logger::LogToConsole("App Success", "\033[32m", __VA_ARGS__)

#endif // _LOGGER_H_