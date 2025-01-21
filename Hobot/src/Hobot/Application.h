#pragma once

#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include"Core.h"

namespace Hobot {
  class HOBOT_API Application {
  public:
    Application();
    virtual ~Application();

    void Run();
  };

  //To be defined in a client
  Application* CreateApplication();
}

#endif // _APPLICATION_H_