#pragma once

#include "event.hpp"

#include <sstream>

namespace Ribbon
{
    class RIB_API MouseButtonEvent : public Event
    {
    protected:
        MouseButtonEvent(uint8_t button)
            : m_Button(button) {}

        EVENT_CLASS_CATEGORY(EventCategory::Input, EventCategory::Mouse, EventCategory::MouseButton)
        uint8_t m_Button;
    };

    class RIB_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(uint8_t button)
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
        MouseButtonReleasedEvent(uint8_t button)
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
        MouseScrolledEvent(double xOffset, double yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset) {}
        
        inline double GetXOffset() const { return m_XOffset; }
        inline double GetYOffset() const { return m_YOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategory::Input, EventCategory::Mouse)
    private:
        double m_XOffset, m_YOffset;
    };

    class RIB_API MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(double x, double y)
            : m_MouseX(x), m_MouseY(y) {}

        inline double GetX() const { return m_MouseX; }
        inline double GetY() const { return m_MouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << GetX() << ", " << GetY();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategory::Input, EventCategory::Mouse)
    private:
        double m_MouseX, m_MouseY;
    };
        // MouseMove, MouseScroll,
} // namespace Ribbon

