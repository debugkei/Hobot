#pragma once

#include "Hobot/Core.h"
#include "Layer.h"

#include <vector>

namespace Hobot {
  class _HOBOT_API LayerStack final {
    private:
    using TContainer = std::vector<Layer*>;
    TContainer _layers;
    TContainer::iterator _layerInsert;

    public:
    inline LayerStack();
    inline LayerStack(LayerStack&&);
    inline LayerStack(const LayerStack&);
    inline ~LayerStack();

    inline void PushLayer(Layer* layer);
    inline void PushOverlay(Layer* overlay);
    inline void PopLayer(Layer* layer, bool doDelete = false);
    inline void PopOverlay(Layer* overlay, bool doDelete = false);

    TContainer::iterator begin() { return _layers.begin(); }
    TContainer::const_iterator cbegin() const { return _layers.cbegin(); }
    TContainer::const_iterator end() { return _layers.end(); }
    TContainer::const_iterator cend() const { return _layers.cend(); }
  };
}  // namespace Hobot