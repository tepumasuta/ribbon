#pragma once
#include "common.hpp"
#include "window.hpp"
#include "events/app_event.hpp"
#include "layers/layer_stack.hpp"

namespace Ribbon
{
    class RIB_API App : Events::Retranslator<Events::WindowClosedEvent>
    {
    public:
        App();
        virtual ~App();
        void Run();
    private:
        void OnEvent(Events::WindowClosedEvent& e) override;
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        // ListenerPointers
        Events::WindowClosedEvent::ListenerPointer m_WindowClosedSubscriptionPtr;
    };

    // Should be defined in CLIENT
    App* CreateApp();
} // namespace Ribbon
