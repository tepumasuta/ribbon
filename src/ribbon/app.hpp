#pragma once
#include "common.hpp"

namespace Ribbon
{
    class RIB_API App
    {
    public:
        App();
        virtual ~App();
        void Run();
    };

    // Should be defined in CLIENT
    App* CreateApp();
} // namespace Ribbon

