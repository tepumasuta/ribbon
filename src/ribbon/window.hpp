#pragma once

#include "pch/ribpch.hpp"
#include "common.hpp"
#include "events/app_event.hpp"
#include "events/key_event.hpp"
#include "events/mouse_event.hpp"

namespace Ribbon
{
    struct WindowProps
    {
        std::string Title;
        uint_fast32_t Width, Height;

        WindowProps(const std::string& title = "Ribbon Engine",
                    uint_fast32_t width = 1280, uint_fast32_t height = 720)
            : Title(title), Width(width), Height(height)
        {}
    };

    // Interface for desktop window
    class RIB_API Window
    {
    public:
        Window(){};
        virtual ~Window() {};

        virtual void OnUpdate() = 0;

        virtual uint_fast32_t GetHeight() const = 0;
        virtual uint_fast32_t GetWidth() const = 0;

        // Window attributes
        Events::WindowClosedEvent& GetWindowClosedEvent() { return m_EventData.WindowClosedEvent; }
        Events::WindowMovedEvent& GetWindowMovedEvent() { return m_EventData.WindowMovedEvent; }
        Events::WindowResizedEvent& GetWindowResizedEvent() { return m_EventData.WindowResizedEvent; }
        Events::WindowSelectedEvent& GetWindowSelectedEvent() { return m_EventData.WindowSelectedEvent; }
        Events::WindowUnselectedEvent& GetWindowUnselectedEvent() { return m_EventData.WindowUnselectedEvent; }

        Events::KeyPressedEvent& GetKeyPressedEvent() { return m_EventData.KeyPressedEvent; }
        Events::KeyReleasedEvent& GetKeyReleasedEvent() { return m_EventData.KeyReleasedEvent; }
        
        Events::MouseButtonPressedEvent& GetMouseButtonPressedEvent() { return m_EventData.MouseButtonPressedEvent; }
        Events::MouseButtonReleasedEvent& GetMouseButtonReleasedEvent() { return m_EventData.MouseButtonReleasedEvent; }
        Events::MouseMovedEvent& GetMouseMovedEvent() { return m_EventData.MouseMovedEvent; }
        Events::MouseScrolledEvent& GetMouseScrolledEvent() { return m_EventData.MouseScrolledEvent; }

        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    protected:
        struct WindowEventData
        {
            Events::WindowClosedEvent WindowClosedEvent;
            Events::WindowMovedEvent WindowMovedEvent;
            Events::WindowResizedEvent WindowResizedEvent;
            Events::WindowSelectedEvent WindowSelectedEvent;
            Events::WindowUnselectedEvent WindowUnselectedEvent;

            Events::KeyPressedEvent KeyPressedEvent;
            Events::KeyReleasedEvent KeyReleasedEvent;

            Events::MouseButtonPressedEvent MouseButtonPressedEvent;
            Events::MouseButtonReleasedEvent MouseButtonReleasedEvent;
            Events::MouseMovedEvent MouseMovedEvent;
            Events::MouseScrolledEvent MouseScrolledEvent;
        };
        WindowEventData m_EventData;
    };
} // namespace Ribbon
