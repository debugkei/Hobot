#pragma once

#ifdef _HOBOT_PLATFORM_WINDOWS_
  #ifdef _HOBOT_BUILD_DLL_
    #define HOBOT_API __declspec(dllexport)
  #else
    #define HOBOT_API __declspec(dllimport)
  #endif
#else
  #error hobot only support Windows for now
#endif

namespace Hobot {

}