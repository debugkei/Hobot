#pragma once

#include"Event.h"

namespace Hobot {
  class _HOBOT_API WindowResizeEvent : public Event {
  private:
    std::size_t _width;
    std::size_t _height;
  public:
    WindowResizeEvent(std::size_t width, std::size_t height)
      : _width(width), _height(height) { }

    ~WindowResizeEvent() override = default;

    //Both ctors for efficiency
    WindowResizeEvent(WindowResizeEvent&&) = default;
    WindowResizeEvent(const WindowResizeEvent&) = default;

    inline std::size_t GetWidth() const { return _width; }
    inline std::size_t GetHeight() const { return _height; }

    std::string ToString() const override {
      std::stringstream ss;
      ss << "WindowResizeEvent: " << _width << 'x' << _height;
      return ss.str();
    }

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(WindowResize)
  };

  class _HOBOT_API WindowCloseEvent : public Event {
  public:
    ~WindowCloseEvent() override = default;

    // All ctors for efficiency
    inline WindowCloseEvent() = default;
    inline WindowCloseEvent(WindowCloseEvent&&) = default;
    inline WindowCloseEvent(const WindowCloseEvent&) = default;

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(WindowClose)
  };

  class _HOBOT_API WindowMovedEvent : public Event {
  private:
    float _x;
    float _y;
  public:
    WindowMovedEvent(float x, float y)
    : _x(x), _y(y) { }

    ~WindowMovedEvent() override = default;

    // All ctors for efficiency
    inline WindowMovedEvent(WindowMovedEvent&&) = default;
    inline WindowMovedEvent(const WindowMovedEvent&) = default;

    std::string ToString() const override {
      std::stringstream ss;
      ss << "WindowMovedEvent: " << '(' << _x << ',' << _y << ')';
      return ss.str();
    }

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(WindowMoved)
  };

  class _HOBOT_API WindowFocusEvent : public Event {
  public:
    ~WindowFocusEvent() override = default;

    // All ctors for efficiency
    inline WindowFocusEvent() = default;
    inline WindowFocusEvent(WindowFocusEvent&&) = default;
    inline WindowFocusEvent(const WindowFocusEvent&) = default;

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(WindowFocus)
  };

  class _HOBOT_API WindowLostFocusEvent : public Event {
  public:
    ~WindowLostFocusEvent() override = default;

    // All ctors for efficiency
    inline WindowLostFocusEvent() = default;
    inline WindowLostFocusEvent(WindowLostFocusEvent&&) = default;
    inline WindowLostFocusEvent(const WindowLostFocusEvent&) = default;

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(WindowLostFocus)
  };

  class _HOBOT_API AppTickEvent : public Event {
  public:
    ~AppTickEvent() override = default;

    // All ctors for efficiency
    inline AppTickEvent() = default;
    inline AppTickEvent(AppTickEvent&&) = default;
    inline AppTickEvent(const AppTickEvent&) = default;

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(AppTick)
  };

  class _HOBOT_API AppUpdateEvent : public Event {
  public:
    ~AppUpdateEvent() override = default;

    // All ctors for efficiency
    inline AppUpdateEvent() = default;
    inline AppUpdateEvent(AppUpdateEvent&&) = default;
    inline AppUpdateEvent(const AppUpdateEvent&) = default;

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(AppUpdate)
  };

  class _HOBOT_API AppRenderEvent : public Event {
  public:
    ~AppRenderEvent() override = default;

    // All ctors for efficiency
    inline AppRenderEvent() = default;
    inline AppRenderEvent(AppRenderEvent&&) = default;
    inline AppRenderEvent(const AppRenderEvent&) = default;

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(AppRender)
  };
}