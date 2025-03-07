#include"htpch.h"

#include"Application.h"

#include"Hobot/Events/Event.h"
#include"Hobot/IWindow.h"
#include"Events/ApplicationEvent.h"
#include"GLFW/glfw3.h"

namespace Hobot {
  static std::unique_ptr<IWindow> _pWindow;
  inline _HOBOT_API Application::Application() : _isRunning{true} {
    _pWindow = std::unique_ptr<IWindow>{IWindow::Create()};
    _pWindow->SetEventCallback([this](const Event& e) { OnEvent(e); });
  }

  inline _HOBOT_API Application::~Application() {}

  inline _HOBOT_API void Application::PushLayer(Layer* layer){
    _layerStack.PushLayer(std::move(layer));
  }

  inline _HOBOT_API void Application::PushOverlay(Layer* overlay){
    _layerStack.PushOverlay(std::move(overlay));
  }

  inline void Application::OnEvent(const Event& e) {
    // Register events
    EventDispatcher(e).Dispatch<WindowCloseEvent>(
        [this](const Event& e) { return OnWindowClose(); });

    for (auto it = _layerStack.end(); it != _layerStack.begin();){
      (*--it)->OnEvent(e);
      if (e.Handled()) break;
    }
  }

  inline _HOBOT_API void Application::Run() {
    while (_isRunning) {
      glClearColor(1, 0, 1, 1);
      glClear(GL_COLOR_BUFFER_BIT);

      for (auto&& layer : _layerStack){
        layer->OnUpdate();
      }

      _pWindow->OnUpdate();
    }
  }

  inline bool Application::OnWindowClose() {
    _isRunning = false;
    _pWindow->Shutdown();
    return true;
  }
}  // namespace Hobot