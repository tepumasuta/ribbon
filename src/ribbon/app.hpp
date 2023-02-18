#pragma once
#include "common.hpp"
#include "window.hpp"
#include "events/app_event.hpp"

namespace Ribbon
{
    class RIB_API App : Events::Retranslator<Events::WindowClosedEvent>
    {
    public:
        App();
        virtual ~App();
        void Run();
        void OnEvent(Events::WindowClosedEvent& e) override;
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        Listener<Events::WindowClosedEvent>* m_WindowClosedSubscriptionPtr;
    };

    // Should be defined in CLIENT
    App* CreateApp();
} // namespace Ribbon
