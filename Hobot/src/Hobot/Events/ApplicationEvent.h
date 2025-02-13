#pragma once

#include"Event.h"

namespace Hobot {
  class _HOBOT_API_ WindowResizeEvent : public Event {
  private:
    std::size_t _width;
    std::size_t _height;
  public:
    WindowResizeEvent(std::size_t width, std::size_t height)
      : _width(width), _height(height) { }

    ~WindowResizeEvent() override = default;

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

  class _HOBOT_API_ WindowCloseEvent : public Event {
  public:
    ~WindowCloseEvent() override = default;

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(WindowClose)
  };

  class _HOBOT_API_ WindowMovedEvent : public Event {
  private:
    float _x;
    float _y;
  public:
    WindowMovedEvent(float x, float y)
    : _x(x), _y(y) { }

    ~WindowMovedEvent() override = default;

    std::string ToString() const override {
      std::stringstream ss;
      ss << "WindowMovedEvent: " << '(' << _x << ',' << _y << ')';
      return ss.str();
    }

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(WindowMoved)
  };

  class _HOBOT_API_ WindowFocusEvent : public Event {
  public:

    ~WindowFocusEvent() override = default;

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(WindowFocus)
  };

  class _HOBOT_API_ WindowLostFocusEvent : public Event {
  public:

    ~WindowLostFocusEvent() override = default;

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(WindowLostFocus)
  };

  class _HOBOT_API_ AppTickEvent : public Event {
  public:

    ~AppTickEvent() override = default;

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(AppTick)
  };

  class _HOBOT_API_ AppUpdateEvent : public Event {
  public:

    ~AppUpdateEvent() override = default;

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(AppUpdate)
  };

  class _HOBOT_API_ AppRenderEvent : public Event {
  public:

    ~AppRenderEvent() override = default;

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
    EVENT_CLASS_TYPE(AppRender)
  };
}