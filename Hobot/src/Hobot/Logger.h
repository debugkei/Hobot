#pragma once

#include"Core.h"
#include"htpch.h"

namespace Hobot {
  //INFO: Get timestamp for linux isnt thread safe

  //This function gets current timestamp
  static auto GetTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    
#ifdef _HOBOT_PLATFORM_WINDOWS_
    tm time;
    localtime_s(&time, &in_time_t);
    ss << std::put_time(&time, "[%Y-%m-%d, %H:%M:%S]");
#else
    ss <<  std::put_time(std::localtime(&in_time_t), "[%Y-%m-%d, %H:%M:%S]");
#endif // _HOBOT_PLATFORM_WINDOWS_
    return ss.str();
  }

  //The logger class, has static methods to log
  class _HOBOT_API_ Logger final {
  private:
    ~Logger() = default;
    Logger() = default;
  public:
    //Logs to console in the format: [timestamp] preinfo: args, in color specified
    template<class...TArgs>
    static void LogToConsole(const std::string& preinfo, const std::string& color, TArgs&&...args){
      std::cout << color << GetTimestamp() << ' ' << preinfo << ": ";
      ((std::cout << std::forward<TArgs>(args)), ...);
      std::cout << "\033[0m" << std::endl;
    }
  };
}

//Logging from engine

//Log info to console, default text color applied
#define CORE_LOG_INFO(...)    Hobot::Logger::LogToConsole("Hobot Info", "\033[0m", __VA_ARGS__, "\n{ ", __FILE__, " }")
//Log warning to console, yellow color applied
#define CORE_LOG_WARNING(...) Hobot::Logger::LogToConsole("Hobot Warning", "\033[33m", __VA_ARGS__, "\n{ ", __FILE__, " }")
//Log error to console, red color applied
#define CORE_LOG_ERROR(...)   Hobot::Logger::LogToConsole("Hobot Error", "\033[31m", __VA_ARGS__, "\n{ ", __FILE__, " }")
//Log success to console, green color applied
#define CORE_LOG_SUCCESS(...) Hobot::Logger::LogToConsole("Hobot Success", "\033[32m", __VA_ARGS__, "\n{ ", __FILE__, " }")

#ifdef _HOBOT_ENABLE_ASSERT_
//Assert Log to console, if value passed is false, then prints out, only in Debug, blue color applied
#define CORE_LOG_ASSERT(cond,...) if (!cond) Hobot::Logger::LogToConsole("Hobot Assertion failed", "\033[34m", __VA_ARGS__, "\n{ ", __FILE__, " }")
#else
//Assert when not _HOBOT_ENABLE_ASSERT_
#define CORE_LOG_ASSERT(...)
#endif // _HOBOT_ENABLE_ASSERT_


//Logging from client

//Log info to console, default text color applied
#define LOG_INFO(...)         Hobot::Logger::LogToConsole("App Info", "\033[0m", __VA_ARGS__, "\n{ ", __FILE__, " }")
//Log warning to console, yellow color applied
#define LOG_WARNING(...)      Hobot::Logger::LogToConsole("App Warning", "\033[33m", __VA_ARGS__, "\n{ ", __FILE__, " }")
//Log error to console, red color applied
#define LOG_ERROR(...)        Hobot::Logger::LogToConsole("App Error", "\033[31m", __VA_ARGS__, "\n{ ", __FILE__, " }")
//Log success to console, green color applied
#define LOG_SUCCESS(...)      Hobot::Logger::LogToConsole("App Success", "\033[32m", __VA_ARGS__, "\n{ ", __FILE__, " }")

#ifdef _HOBOT_ENABLE_ASSERT_
//Assert Log to console, if value passed is false, then prints out, only in Debug, blue color applied
#define LOG_ASSERT(cond,...) if (!cond) Hobot::Logger::LogToConsole("App Assertion failed", "\033[34m", __VA_ARGS__, "\n{ ", __FILE__, " }")
#else
//Assert when not _HOBOT_ENABLE_ASSERT_
#define LOG_ASSERT(...)
#endif // _HOBOT_ENABLE_ASSERT_