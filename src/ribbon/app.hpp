#pragma once
#include "common.hpp"
#include "window.hpp"

namespace Ribbon
{
    class RIB_API App
    {
    public:
        App();
        virtual ~App();
        void Run();
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // Should be defined in CLIENT
    App* CreateApp();
} // namespace Ribbon

