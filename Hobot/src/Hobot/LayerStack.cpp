#include"LayerStack.h"

#include"htpch.h"

namespace Hobot {
  inline _HOBOT_API LayerStack::LayerStack() : _layerInsert(_layers.begin()) {}

  inline _HOBOT_API LayerStack::~LayerStack() {
    for (auto&& layer : _layers) {
      delete layer;
    }
  }

  inline _HOBOT_API void LayerStack::PushLayer(Layer* layer) {
    _layerInsert = _layers.insert(_layerInsert, std::move(layer));
  }

  inline _HOBOT_API void LayerStack::PushOverlay(Layer* overlay) {
    _layers.push_back(std::move(overlay));
  }

  inline _HOBOT_API void LayerStack::PopLayer(Layer* layer, bool doDelete) {
    auto it = std::find(_layers.begin(), _layers.end(), std::move(layer));

    if (it != _layers.end()) {
      if (doDelete) delete *it;
      _layers.erase(it);
      --_layerInsert;
    }
  }

  inline _HOBOT_API void LayerStack::PopOverlay(Layer* overlay, bool doDelete) {
    auto it = std::find(_layers.begin(), _layers.end(), std::move(overlay));

    if (it != _layers.end()) {
      if (doDelete) delete *it;
      _layers.erase(it);
    }
  }
}  // namespace Hobot