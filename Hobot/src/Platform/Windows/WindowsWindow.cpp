#include"htpch.h"

#include"WindowsWindow.h"

#include"Hobot/IWindow.h"

namespace Hobot{
  static bool isglfwInit = false;

  IWindow* IWindow::Create(const WindowProps& props){
    return new WindowsWindow(props);
  }

  WindowsWindow::WindowsWindow(const WindowProps& props){
    Init(props);
  }

  WindowsWindow::~WindowsWindow() {
    Shutdown();
  };

  void WindowsWindow::Init(const WindowProps& props){
    _data.Title = props.Title;
    _data.Width = props.Width;
    _data.Height = props.Height;

    CORE_LOG_INFO("Creating window: { ", _data.Title, ' ', _data.Width, 'x', _data.Height, " }");

    if (!isglfwInit){
      int success = glfwInit();

      const char* dest;
      glfwGetError(&dest);

      CORE_LOG_ASSERT(success, "Couldnt initialize glfw. ", dest);

      isglfwInit = true;
    }

    _window = glfwCreateWindow(_data.Width, _data.Height, _data.Title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(_window);
    glfwSetWindowUserPointer(_window, &_data);
    SetVSync(true);
  }

  void WindowsWindow::Shutdown(){
    glfwDestroyWindow(_window);
  }

  void WindowsWindow::OnUpdate(){
    glfwPollEvents();
    glfwSwapBuffers(_window);
  }

  void WindowsWindow::SetVSync(bool enabled){
    if (enabled) glfwSwapInterval(1);
    else glfwSwapInterval(0);

    _data.VSync = enabled;
  }

  bool WindowsWindow::IsVSync() const{
    return _data.VSync;
  }
}