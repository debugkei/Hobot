#pragma once

#include<htpch.h>

#include"Hobot/Core.h"

namespace Hobot {

  //Events in Hobot are currently blocking, meaning when an event occurs, it immediatly
  //gets dispatched and must be dealt right away with.
  //For the future, a better strategy might be to buffer events and process them during the event stage of update (Frame).

  enum class EventType {
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyPressed, KeyReleased,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
  };

  enum EventCategory {
    None = 0,
    EventCategoryApplication  = BIT(0),
    EventCategoryInput        = BIT(1),
    EventCategoryKeyboard     = BIT(2),
    EventCategoryMouse        = BIT(3),
    EventCategoryMouseButton  = BIT(4)
  };

#define EVENT_CLASS_TYPE(type)\
  static EventType GetStaticType() { return EventType::##type; }\
  virtual EventType GetEventType() const override { return GetStaticType(); }\
  virtual std::string GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

  class HOBOT_API Event {
  protected:
    bool _handled_ = false;
  public:
    virtual EventType GetEventType() const = 0;
    virtual std::string GetName() const = 0;
    virtual int GetCategoryFlags() const = 0;
    virtual std::string ToString() const { return GetName(); }

    bool IsInCategory(EventCategory category) {
      return GetCategoryFlags() & category;
    }
    virtual ~Event() = default;
  };

  class HOBOT_API EventDispatcher {
  private:
    template<class T>
    using EventFc = std::function<bool(T&)>;
    Event& _event;
  public:
    EventDispatcher(Event& event)
      : _event(event) { }

    template<class T>
    bool Dispatch(EventFc<T> func) {
      if (_event.GetEventType() == T::GetStaticType()) {
        _event._handled_ = func(*dynamic_cast<T*>(&_event));
        return true;
      }
      return false;
    }
  };

  inline std::ostream& operator<<(std::ostream& os, const Event& e) {
    return os << e.ToString();
  }
}