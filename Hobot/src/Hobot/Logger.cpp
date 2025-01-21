#include<chrono>
#include<string>
#include<iostream>
#include<ctime>

#include "Logger.h"

namespace Hobot {
  //This function gets current timestamp
  static auto GetTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

#ifdef _HOBOT_PLATFORM_WINDOWS_
    tm time;
    localtime_s(&time, &in_time_t);
    return std::put_time(&time, "[%Y-%m-%d, %H:%M:%S]");
#elif
    return std::put_time(std::localtime(&in_time_t), "[%Y-%m-%d, %H:%M:%S]");
#endif // _HOBOT_PLATFORM_WINDOWS_
  }
  Logger::Logger() {

  }

  Logger::~Logger() {

  }

  template<class...TArgs>
  void Logger::LogToConsole(const std::string& name, const std::string& color, TArgs&&...args) {
    std::cout << color << GetTimestamp() << ' ' << name << ": ";
    ((std::cout << std::forward<TArgs>(args)), ...);
    std::cout << std::endl;
  }
}