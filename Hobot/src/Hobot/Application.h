#pragma once

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