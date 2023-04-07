#pragma once
#include "common.hpp"
#include "layer.hpp"

namespace Ribbon
{
namespace Layers
{
    class RIB_API LayerStack
    {
    public:
        using LayerStackContainer = std::vector<Layer*>;
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PopLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopOverlay(Layer* overlay);

        LayerStackContainer::iterator begin() { return m_Layers.begin(); }
        LayerStackContainer::iterator end() { return m_Layers.end(); }
    private:
        LayerStackContainer m_Layers;
        uint_fast32_t m_LayerInsertIndex;
    };
} // namespace Layers
} // namespace Ribbon

