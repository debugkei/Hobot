#pragma once

#include"htpch.h"

#include"Hobot/IWindow.h"
#include"GLFW/glfw3.h"

namespace Hobot{
  //Window class, specific to Windows Platform
  class WindowsWindow : public IWindow{
    private:
    struct WindowData{
      std::string Title;
      unsigned int Width, Height;
      bool VSync;

      IWindow::EventCallbackFunc EventCallback;
    };

    GLFWwindow* _pWindow;
    WindowData _data;
    
    inline void Init(const WindowProps& props) override;
    inline void Shutdown() const override;
    public:
    //Ctor & Dtor
    WindowsWindow(const WindowProps& props);
    virtual ~WindowsWindow();

    //Callbacks
    void OnUpdate() override;

    //Getters
    inline unsigned int GetWidth() const override { return _data.Width; }
    inline unsigned int GetHeight() const override { return _data.Height; }
    inline bool IsVSync() const override;

    //Setters
    inline void SetEventCallback(const typename IWindow::EventCallbackFunc& callback) override { _data.EventCallback = callback; }
    void SetVSync(bool enabled) override;
  };
}