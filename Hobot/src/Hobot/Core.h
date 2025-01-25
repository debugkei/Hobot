#pragma once

//Define dll export/import universal API
#ifdef _HOBOT_PLATFORM_WINDOWS_
  #ifdef _HOBOT_BUILD_DLL_
    #define HOBOT_API __declspec(dllexport)
  #else
    #define HOBOT_API __declspec(dllimport)
  #endif
#else
  #error hobot only support Windows for now
#endif

#define BIT(i) 1 << i

//TODO
  //FIX ?-?-?, timestamp