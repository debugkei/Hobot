#pragma once

//Define dll export/import universal API
#ifdef _HOBOT_PLATFORM_WINDOWS_
  #ifdef _HOBOT_BUILD_DLL_
    #define _HOBOT_API_ __declspec(dllexport)
  #else
    #define _HOBOT_API_ __declspec(dllimport)
  #endif
#elif defined(_HOBOT_PLATFORM_LINUX_) && defined(_HOBOT_BUILD_DLL_)
  #define _HOBOT_API_ __attribute__((visibility("default")))
#else
  //So that vs code doesnt cry that its not defined, it gets defined when make is called
  #define _HOBOT_API_
#endif

#define BIT(i) 1 << i