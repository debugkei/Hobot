#pragma once

#include"Event.h"

namespace Hobot {
  class _HOBOT_API KeyEvent : public Event {
  protected:
    int _keyCode;

    ~KeyEvent() override = default;

    KeyEvent(int keyCode)
      : _keyCode(keyCode) { }
  public:
    int GetKeyCode() const {
      return _keyCode;
    }

    EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
  };

  class _HOBOT_API KeyPressedEvent : public KeyEvent {
  private:
    int _repeatCount;
  public:
    KeyPressedEvent(int keyCode, int repeatCount)
      : KeyEvent(keyCode), _repeatCount(repeatCount) { }

    ~KeyPressedEvent() override = default;

    // All ctors for efficiency
    inline KeyPressedEvent(KeyPressedEvent&&) = default;
    inline KeyPressedEvent(const KeyPressedEvent&) = default;

    inline int GetRepeatCount() const { return _repeatCount; }

    std::string ToString() const override {
      std::stringstream ss;
      ss << "KeyPressedEvent: " << _keyCode << " (" << _repeatCount << " repeats)";
      return ss.str();
    }

    EVENT_CLASS_TYPE(KeyPressed)
  };

  class _HOBOT_API KeyReleasedEvent : public KeyEvent {
  public:
    KeyReleasedEvent(int keyCode)
      : KeyEvent(keyCode) { }

    ~KeyReleasedEvent() override = default;

    // All ctors for efficiency
    inline KeyReleasedEvent(KeyReleasedEvent&&) = default;
    inline KeyReleasedEvent(const KeyReleasedEvent&) = default;

    std::string ToString() const override {
      std::stringstream ss;
      ss << "KeyReleasedEvent: " << _keyCode;
      return ss.str();
    }

    EVENT_CLASS_TYPE(KeyReleased)
  };
}