#include"htpch.h"

#include"WindowsWindow.h"

#include"Hobot/IWindow.h"
#include"Hobot/Events/ApplicationEvent.h"
#include"Hobot/Events/MouseEvent.h"
#include"Hobot/Events/KeyEvent.h"

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

    _pWindow = glfwCreateWindow(_data.Width, _data.Height, _data.Title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(_pWindow);
    glfwSetWindowUserPointer(_pWindow, &_data);
    SetVSync(true);

    //Set callbacks
  
    glfwSetWindowSizeCallback(_pWindow, [](GLFWwindow* pWindow, int width, int height){
      //Get the data from SetWindowUserPointer
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);
      data.Width = width;
      data.Height = height;

      //Dispatch
      data.EventCallback(WindowResizeEvent(width, height));
    });

    glfwSetWindowCloseCallback(_pWindow, [](GLFWwindow* pWindow) {
      // Get the data from SetWindowUserPointer
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

      // Dispatch
      data.EventCallback(WindowCloseEvent());
    });

    glfwSetKeyCallback(_pWindow, [](GLFWwindow* pWindow, int key, int scancode, int action, int mods) {
      // Get the data from SetWindowUserPointer
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

      //TODO: key has to be converted into Hobot key
      //TODO: add repeat count, glfw already handles the right timing tho
      switch(action){
        case GLFW_PRESS:
          // Dispatch
          data.EventCallback(KeyPressedEvent(key, 0));
          break;
        case GLFW_RELEASE:
          // Dispatch
          data.EventCallback(KeyReleasedEvent(key));
          break;
        case GLFW_REPEAT:
          // Dispatch
          data.EventCallback(KeyPressedEvent(key, 1));
          break;
      }
    });

    glfwSetMouseButtonCallback(_pWindow, [](GLFWwindow* pWindow, int button, int action, int mods) {
      // Get the data from SetWindowUserPointer
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

      //TODO: key has to be converted into Hobot key
      switch(action){
        case GLFW_PRESS:
          // Dispatch
          data.EventCallback(MouseButtonPressedEvent(button));
          break;
        case GLFW_RELEASE:
          // Dispatch
          data.EventCallback(MouseButtonReleasedEvent(button));
          break;
      }
    });

    glfwSetScrollCallback(_pWindow, [](GLFWwindow* pWindow, double x, double y) {
      // Get the data from SetWindowUserPointer
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

      // Dispatch
      data.EventCallback(MouseScrolledEvent(x, y));
    });

    glfwSetCursorPosCallback(_pWindow, [](GLFWwindow* pWindow, double x, double y) {
      // Get the data from SetWindowUserPointer
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

      // Dispatch
      data.EventCallback(MouseMovedEvent(x, y));
    });
    
    //For now just log an error
    glfwSetErrorCallback([](int error, const char* description){
      CORE_LOG_ERROR("GLFW error (", error, ") ", description);
    });
  }

  inline void WindowsWindow::Shutdown() const{
    glfwDestroyWindow(_pWindow);
  }

  inline void WindowsWindow::OnUpdate(){
    glfwPollEvents();
    glfwSwapBuffers(_pWindow);
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