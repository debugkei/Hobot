#pragma once

//Define dll export/import universal API
#ifdef _HOBOT_PLATFORM_WINDOWS_
  #ifdef _HOBOT_BUILD_DLL_
    #define HOBOT_API __declspec(dllexport)
  #else
    #define HOBOT_API __declspec(dllimport)
  #endif
#else
  //So that vs code doesnt cry that its not defined, it gets defined when make is called
  #define HOBOT_API
#endif

#define BIT(i) 1 << i

//TODO
  //Add to github reminder to download visual c++ on windows
  //*.bat in .gitignore doesnt work