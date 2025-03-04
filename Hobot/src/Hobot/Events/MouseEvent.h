#pragma once

#include"Event.h"

namespace Hobot {
  class _HOBOT_API MouseMovedEvent : public Event {
  private:
    float _x;
    float _y;
  public:
    MouseMovedEvent(float x, float y)
      : _x(x), _y(y) { }

    // All ctors for efficiency
    inline MouseMovedEvent(MouseMovedEvent&&) = default;
    inline MouseMovedEvent(const MouseMovedEvent&) = default;

    inline float GetX() const { return _x; }
    inline float GetY() const { return _y; }

    std::string ToString() const override {
      std::stringstream ss;
      ss << "MouseMovedEvent: " << '(' << _x << ',' << _y << ')';
      return ss.str();
    }

    ~MouseMovedEvent() override = default;

    EVENT_CLASS_TYPE(MouseMoved)
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
  };

  class _HOBOT_API MouseScrolledEvent : public Event {
  private:
    float _xDelta;
    float _yDelta;
  public:
    MouseScrolledEvent(float xDelta, float yDelta)
      : _xDelta(xDelta), _yDelta(yDelta) {
    }

    // All ctors for efficiency
    inline MouseScrolledEvent(MouseScrolledEvent&&) = default;
    inline MouseScrolledEvent(const MouseScrolledEvent&) = default;

    inline float GetXDelta() const { return _xDelta; }
    inline float GetYDelta() const { return _yDelta; }

    std::string ToString() const override {
      std::stringstream ss;
      ss << "MouseScrolledEvent: " << '(' << _xDelta << ',' << _yDelta << ')';
      return ss.str();
    }

    ~MouseScrolledEvent() override = default;

    EVENT_CLASS_TYPE(MouseScrolled)
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
  };

  class _HOBOT_API MouseButtonEvent : public Event {
  protected:
    int _button;
    ~MouseButtonEvent() override = default;

    MouseButtonEvent(int button)
      : _button(button) { }
  public:
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)
  };

  class _HOBOT_API MouseButtonPressedEvent : public MouseButtonEvent {
  public:
    ~MouseButtonPressedEvent() override = default;

    MouseButtonPressedEvent(int button)
      : MouseButtonEvent(button) { }

    // All ctors for efficiency
    inline MouseButtonPressedEvent(MouseButtonPressedEvent&&) = default;
    inline MouseButtonPressedEvent(const MouseButtonPressedEvent&) = default;

    std::string ToString() const override {
      std::stringstream ss;
      ss << "MouseButtonPressedEvent: " << _button;
      return ss.str();
    }

    EVENT_CLASS_TYPE(MouseButtonPressed)
  };

  class _HOBOT_API MouseButtonReleasedEvent : public MouseButtonEvent {
  public:
    ~MouseButtonReleasedEvent() override = default;

    MouseButtonReleasedEvent(int button)
      : MouseButtonEvent(button) {
    }

    // All ctors for efficiency
    inline MouseButtonReleasedEvent(MouseButtonReleasedEvent&&) = default;
    inline MouseButtonReleasedEvent(const MouseButtonReleasedEvent&) = default;

    std::string ToString() const override {
      std::stringstream ss;
      ss << "MouseButtonReleasedEvent: " << _button;
      return ss.str();
    }

    EVENT_CLASS_TYPE(MouseButtonReleased)
  };
}