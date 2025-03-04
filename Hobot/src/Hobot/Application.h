#pragma once

#include"Core.h"
#include"Events/Event.h"

namespace Hobot {
  class _HOBOT_API Application {
    private:
    bool _isRunning;
    inline bool OnWindowClose();
    public:
    inline Application();
    inline virtual ~Application();

    //Here all dispatching happens
    inline void OnEvent(const Event& e);

    inline void Run() const;
  };

  //To be defined in a client
  Application* CreateApplication();
}