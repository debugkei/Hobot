#pragma once

#include "Hobot/Core.h"
#include "Hobot/Events/Event.h"

namespace Hobot {
  class _HOBOT_API Layer {
    private:
    std::string _name;

    public:
    inline virtual ~Layer() = default;
    inline Layer(const Layer&) = default;
    inline Layer(Layer&&) = default;
    inline Layer(const std::string& name = "Layer") : _name(name) {}

    inline virtual void OnAttach() {}
    inline virtual void OnDettach() {}
    inline virtual void OnUpdate() {}
    inline virtual void OnEvent(const Event& event) {}

    inline const std::string& GetName() const { return _name; }
  };
}  // namespace Hobot