#pragma once

#include"Event.h"

#include<sstream>

namespace Hobot {
  class HOBOT_API MouseMovedEvent : public Event {
  private:
    float _x;
    float _y;
  public:
    MouseMovedEvent(float x, float y)
      : _x(x), _y(y) { }

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

  class HOBOT_API MouseScrolledEvent : public Event {
  private:
    float _xDelta;
    float _yDelta;
  public:
    MouseScrolledEvent(float xDelta, float yDelta)
      : _xDelta(xDelta), _yDelta(yDelta) {
    }

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

  class HOBOT_API MouseButtonEvent : public Event {
  protected:
    int _button;
    ~MouseButtonEvent() override = default;

    MouseButtonEvent(int button)
      : _button(button) { }
  public:
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)
  };

  class HOBOT_API MouseButtonPressedEvent : public MouseButtonEvent {
  public:
    ~MouseButtonPressedEvent() override = default;

    MouseButtonPressedEvent(int button)
      : MouseButtonEvent(button) { }

    std::string ToString() const override {
      std::stringstream ss;
      ss << "MouseButtonPressedEvent: " << _button;
    }

    EVENT_CLASS_TYPE(MouseButtonPressed)
  };

  class HOBOT_API MouseButtonReleasedEvent : public MouseButtonEvent {
  public:
    ~MouseButtonReleasedEvent() override = default;

    MouseButtonReleasedEvent(int button)
      : MouseButtonEvent(button) {
    }

    std::string ToString() const override {
      std::stringstream ss;
      ss << "MouseButtonReleasedEvent: " << _button;
    }

    EVENT_CLASS_TYPE(MouseButtonReleased)
  };
}