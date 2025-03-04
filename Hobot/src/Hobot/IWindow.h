#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Hobot {
  // Window Properties, a Data Transfer Object
  struct WindowProps final {
    // Properties
    std::string Title;
    unsigned int Width;
    unsigned int Height;

    // Ctor
    WindowProps(const std::string& title = "Hobot Engine",
                unsigned int width = 1280, unsigned int height = 720)
        : Title(title), Width(width), Height(height) {}
  };

  // Interface that represents a desktop system based Window
  struct _HOBOT_API IWindow {
    public:
    virtual ~IWindow() = default;

    using EventCallbackFunc = std::function<void(const Event&)>;

    virtual inline void Init(const WindowProps& props) = 0;
    virtual inline void Shutdown() const = 0;

    // Callbacks
    virtual void OnUpdate() = 0;

    // Getters
    virtual unsigned int GetWidth() const = 0;
    virtual unsigned int GetHeight() const = 0;
    virtual bool IsVSync() const = 0;

    // Setters
    virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
    virtual void SetVSync(bool enabled) = 0;

    // Create method, has to be implemented per platform
    static IWindow* Create(const WindowProps& props = WindowProps());
  };
}  // namespace Hobot