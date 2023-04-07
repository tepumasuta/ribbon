#pragma once
#include "common.hpp"
#include "pch/ribpch.hpp"
#include "events/app_event.hpp"
#include "events/key_event.hpp"
#include "events/mouse_event.hpp"

namespace Ribbon
{
namespace Layers
{
    class RIB_API Layer : Events::EngineRetranslator<Events::WindowClosedEvent>,
        Events::EngineRetranslator<Events::WindowMovedEvent>, Events::EngineRetranslator<Events::WindowResizedEvent>,
        Events::EngineRetranslator<Events::WindowSelectedEvent>, Events::EngineRetranslator<Events::WindowUnselectedEvent>,
        Events::EngineRetranslator<Events::KeyPressedEvent>, Events::EngineRetranslator<Events::KeyReleasedEvent>,
        Events::EngineRetranslator<Events::MouseButtonPressedEvent>, Events::EngineRetranslator<Events::MouseButtonReleasedEvent>,
        Events::EngineRetranslator<Events::MouseMovedEvent>, Events::EngineRetranslator<Events::MouseScrolledEvent>
    {
    public:
        friend std::ostream& operator<<(std::ostream& out, const Layer& layer);
    protected:
        virtual void OnEvent(Events::WindowClosedEvent& e) override { (void)e; };
        virtual void OnEvent(Events::WindowMovedEvent& e) override { (void)e; };
        virtual void OnEvent(Events::WindowResizedEvent& e) override { (void)e; };
        virtual void OnEvent(Events::WindowSelectedEvent& e) override { (void)e; };
        virtual void OnEvent(Events::WindowUnselectedEvent& e) override { (void)e; };
        virtual void OnEvent(Events::KeyPressedEvent& e) override { (void)e; };
        virtual void OnEvent(Events::KeyReleasedEvent& e) override { (void)e; };
        virtual void OnEvent(Events::MouseButtonPressedEvent& e) override { (void)e; };
        virtual void OnEvent(Events::MouseButtonReleasedEvent& e) override { (void)e; };
        virtual void OnEvent(Events::MouseMovedEvent& e) override { (void)e; };
        virtual void OnEvent(Events::MouseScrolledEvent& e) override { (void)e; };
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnUpdate() {}
        virtual void OnAttach() {}
        virtual void OnDetach() {}
    protected:
        std::string m_DebugName;
    };
    extern std::ostream& operator<<(std::ostream& out, const Layer& layer);
} // namespace Layers
} // namespace Ribbon

