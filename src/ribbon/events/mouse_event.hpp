#pragma once

#include "event.hpp"

#include <sstream>

namespace Ribbon
{
    class RIB_API MouseButtonEvent : public Event
    {
    protected:
        MouseButtonEvent(u8 button)
            : m_Button(button) {}

        EVENT_CLASS_CATEGORY(EventCategory::Input, EventCategory::Mouse, EventCategory::MouseButton)
        u8 m_Button;
    };

    class RIB_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(u8 button)
            : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class RIB_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(u8 button)
            : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

    class RIB_API MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(f64 xOffset, f64 yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset) {}
        
        inline f64 GetXOffset() const { return m_XOffset; }
        inline f64 GetYOffset() const { return m_YOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategory::Input, EventCategory::Mouse)
    private:
        f64 m_XOffset, m_YOffset;
    };

    class RIB_API MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(f64 x, f64 y)
            : m_MouseX(x), m_MouseY(y) {}

        inline f64 GetX() const { return m_MouseX; }
        inline f64 GetY() const { return m_MouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << GetX() << ", " << GetY();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategory::Input, EventCategory::Mouse)
    private:
        f64 m_MouseX, m_MouseY;
    };
        // MouseMove, MouseScroll,
} // namespace Ribbon

