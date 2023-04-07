#pragma once
#include "common.hpp"
#include "window.hpp"
#include "events/app_event.hpp"
#include "layers/layer_stack.hpp"

namespace Ribbon
{
#define INHERIT_EVENT(EVENT_NAME) public Events::EngineRetranslator<Events::EVENT_NAME>
    class RIB_API App : INHERIT_EVENT(WindowClosedEvent), INHERIT_EVENT(WindowMovedEvent),
        INHERIT_EVENT(WindowResizedEvent), INHERIT_EVENT(WindowSelectedEvent),
        INHERIT_EVENT(WindowUnselectedEvent), INHERIT_EVENT(KeyPressedEvent),
        INHERIT_EVENT(KeyReleasedEvent), INHERIT_EVENT(MouseButtonPressedEvent),
        INHERIT_EVENT(MouseButtonReleasedEvent), INHERIT_EVENT(MouseMovedEvent),
        INHERIT_EVENT(MouseScrolledEvent)
#undef INHERITANCE_EVENT_NAME
    {
    public:
        App();
        virtual ~App();
        void Run();

        void PushLayer(Layers::Layer* layer);
        void PushOverlay(Layers::Layer* overlay);

        void static SubscribeToAllEvents(App& app, Layers::Layer& layer)
        {
            app.Subscribe((Events::Listener<Events::WindowClosedEvent>&)layer);
            app.Subscribe((Events::Listener<Events::WindowResizedEvent>&)layer);
            app.Subscribe((Events::Listener<Events::WindowMovedEvent>&)layer);
            app.Subscribe((Events::Listener<Events::WindowSelectedEvent>&)layer);
            app.Subscribe((Events::Listener<Events::WindowUnselectedEvent>&)layer);
            app.Subscribe((Events::Listener<Events::KeyPressedEvent>&)layer);
            app.Subscribe((Events::Listener<Events::KeyReleasedEvent>&)layer);
            app.Subscribe((Events::Listener<Events::MouseButtonPressedEvent>&)layer);
            app.Subscribe((Events::Listener<Events::MouseButtonReleasedEvent>&)layer);
            app.Subscribe((Events::Listener<Events::MouseMovedEvent>&)layer);
            app.Subscribe((Events::Listener<Events::MouseScrolledEvent>&)layer);
        }

        void static UnsubscribeFromAllEvents(App& app, Layers::Layer& layer)
        {
            app.Unsubscribe((Events::Listener<Events::WindowClosedEvent>&)layer);
            app.Unsubscribe((Events::Listener<Events::WindowResizedEvent>&)layer);
            app.Unsubscribe((Events::Listener<Events::WindowMovedEvent>&)layer);
            app.Unsubscribe((Events::Listener<Events::WindowSelectedEvent>&)layer);
            app.Unsubscribe((Events::Listener<Events::WindowUnselectedEvent>&)layer);
            app.Unsubscribe((Events::Listener<Events::KeyPressedEvent>&)layer);
            app.Unsubscribe((Events::Listener<Events::KeyReleasedEvent>&)layer);
            app.Unsubscribe((Events::Listener<Events::MouseButtonPressedEvent>&)layer);
            app.Unsubscribe((Events::Listener<Events::MouseButtonReleasedEvent>&)layer);
            app.Unsubscribe((Events::Listener<Events::MouseMovedEvent>&)layer);
            app.Unsubscribe((Events::Listener<Events::MouseScrolledEvent>&)layer);
        }

    private:
#define USING_EVENT_API(EVENT_NAME)\
using Events::EngineRetranslator<Events::EVENT_NAME>::Notify;\
using Events::EngineRetranslator<Events::EVENT_NAME>::Subscribe;\
using Events::EngineRetranslator<Events::EVENT_NAME>::Unsubscribe;

        USING_EVENT_API(WindowClosedEvent)
        USING_EVENT_API(WindowResizedEvent)
        USING_EVENT_API(WindowMovedEvent)
        USING_EVENT_API(WindowSelectedEvent)
        USING_EVENT_API(WindowUnselectedEvent)
        USING_EVENT_API(KeyPressedEvent)
        USING_EVENT_API(KeyReleasedEvent)
        USING_EVENT_API(MouseButtonPressedEvent)
        USING_EVENT_API(MouseButtonReleasedEvent)
        USING_EVENT_API(MouseMovedEvent)
        USING_EVENT_API(MouseScrolledEvent)

#undef USING_EVENT_API

        // Event Handling
        virtual void OnEvent(Events::WindowClosedEvent& e) override;
        virtual void OnEvent(Events::MouseMovedEvent& e) override;
        virtual void HandleEvent(Events::WindowClosedEvent& e) override { e.Handled = true; };
        virtual void HandleEvent(Events::WindowResizedEvent& e) override { e.Handled = true; };
        virtual void HandleEvent(Events::WindowMovedEvent& e) override { e.Handled = true; };
        virtual void HandleEvent(Events::WindowSelectedEvent& e) override { e.Handled = true; };
        virtual void HandleEvent(Events::WindowUnselectedEvent& e) override { e.Handled = true; };
        virtual void HandleEvent(Events::KeyPressedEvent& e) override { e.Handled = true; };
        virtual void HandleEvent(Events::KeyReleasedEvent& e) override { e.Handled = true; };
        virtual void HandleEvent(Events::MouseButtonPressedEvent& e) override { e.Handled = true; };
        virtual void HandleEvent(Events::MouseButtonReleasedEvent& e) override { e.Handled = true; };
        virtual void HandleEvent(Events::MouseMovedEvent& e) override { e.Handled = true; };
        virtual void HandleEvent(Events::MouseScrolledEvent& e) override { e.Handled = true; };
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;

        Layers::LayerStack m_LayerStack;
    };

    // Should be defined in CLIENT
    App* CreateApp();
} // namespace Ribbon
