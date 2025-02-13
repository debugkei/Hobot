#pragma once

#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include"Core.h"

namespace Hobot {
  class _HOBOT_API_ Application {
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

#endif // _APPLICATION_H_