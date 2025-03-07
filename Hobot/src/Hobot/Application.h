#pragma once

#include"Core.h"

#include"Events/Event.h"
#include"IWindow.h"
#include"Hobot/Events/ApplicationEvent.h"
#include"LayerStack.h"

namespace Hobot {
  class _HOBOT_API Application {
    private:
    LayerStack _layerStack;
    bool _isRunning;
    inline bool OnWindowClose();

    //Here all dispatching happens
    inline void OnEvent(const Event& e);

    public:
    inline Application();
    inline virtual ~Application();

    inline void PushLayer(Layer* layer);
    inline void PushOverlay(Layer* overlay); 

    inline void Run();
  };

  //To be defined in a client
  Application* CreateApplication();
}