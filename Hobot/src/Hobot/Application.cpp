#include"htpch.h"

#include"Application.h"

#include"Hobot/Events/Event.h"
#include"Hobot/IWindow.h"
#include"Events/ApplicationEvent.h"

namespace Hobot {
  static std::unique_ptr<IWindow> _pWindow;
  inline _HOBOT_API Application::Application()
  : _isRunning{ true } {
    _pWindow = std::unique_ptr<IWindow>{ IWindow::Create() };
    _pWindow->SetEventCallback([this](const Event& e) { OnEvent(e); });
  }

  inline _HOBOT_API Application::~Application() {

  }

  inline void Application::OnEvent(const Event& e){
    //Register events
    EventDispatcher(e).Dispatch<WindowCloseEvent>([this](const Event& e){ return OnWindowClose(); });

    //Log
    LOG_INFO(e);
  }

  inline _HOBOT_API void Application::Run() const {
    while (_isRunning){
      _pWindow->OnUpdate();
    }
  }

  inline bool Application::OnWindowClose(){
    _isRunning = false;
    _pWindow->Shutdown();
    return true;
  }
}