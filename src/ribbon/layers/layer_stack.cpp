#include "layer_stack.hpp"

namespace Ribbon
{
namespace Layers
{
    LayerStack::LayerStack()
        : m_LayerInsertIndex(0U) {}
    
    LayerStack::~LayerStack()
    {
        for (Layer* layer: m_Layers)
            delete layer;
    }
    
    void LayerStack::PushLayer(Layer* layer)
    {
        auto it = begin();
        std::advance(it, m_LayerInsertIndex++);
        m_Layers.emplace(it, layer);
    }

    void LayerStack::PopLayer(Layer* layer)
    {
        auto it = std::find(begin(), end(), layer);
        if (it != end())
        {
            m_Layers.erase(it);
            m_LayerInsertIndex--;
        }
    }

    void LayerStack::PushOverlay(Layer* overlay)
    {
        m_Layers.emplace_back(overlay);
    }
    
    void LayerStack::PopOverlay(Layer* overlay)
    {
        auto it = std::find(begin(), end(), overlay);
        if (it != end())
        {
            m_Layers.erase(it);
        }
    }


} // namespace Layers
} // namespace Ribbon
