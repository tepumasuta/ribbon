#include "layer.hpp"

namespace Ribbon
{
namespace Layers
{
    // layer
    std::ostream& operator<<(std::ostream& out, const Layer& layer)
    {
        return out << "Layer{" << layer.m_DebugName << "}";
    }
} // namespace Layers
} // namespace Ribbon
