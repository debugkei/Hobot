#include"htpch.h"

#include"Application.h"

#include"Hobot/Events/Event.h"
#include"Hobot/IWindow.h"

namespace Hobot {
  static std::unique_ptr<IWindow> _pWindow;
  Application::Application()
  : _isRunning{ true } {
    _pWindow = std::unique_ptr<IWindow>{ IWindow::Create() };
  }

  Application::~Application() {

  }

  void Application::Run() {
    while (_isRunning){
      _pWindow->OnUpdate();
    }
  }
}