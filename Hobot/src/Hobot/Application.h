#pragma once

#include"Core.h"

namespace Hobot {
  class _HOBOT_API Application {
    private:
    bool _isRunning;
    public:
    Application();
    virtual ~Application();

    void Run();
  };

  //To be defined in a client
  Application* CreateApplication();
}