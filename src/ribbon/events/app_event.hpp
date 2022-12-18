#pragma once

#include "event.hpp"
#include <sstream>

namespace Ribbon
{
    class RIB_API WindowClosedEvent : public Event
    {
    public:
        WindowClosedEvent() {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowClosedEvent: ";
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowClosed)
        EVENT_CLASS_CATEGORY(EventCategory::App)
    };

    class RIB_API WindowMovedEvent : public Event
    {
    public:
        WindowMovedEvent(float x, float y)
            : m_WindowX(x), m_WindowY(y) {}
        
        inline float GetX() const { return m_WindowX; }
        inline float GetY() const { return m_WindowY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowMovedEvent: " << GetX() << ", " << GetY();
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowMoved)
        EVENT_CLASS_CATEGORY(EventCategory::App)
    private:
        float m_WindowX, m_WindowY;
    };

    class RIB_API WindowResizedEvent : public Event
    {
    public:
        WindowResizedEvent(float width, float height)
            : m_Width(width), m_Height(height) {}

        inline float GetWidth() const { return m_Width; }
        inline float GetHeight() const { return m_Height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizedEvent: " << GetWidth() << ", " << GetHeight();
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResized)
        EVENT_CLASS_CATEGORY(EventCategory::App)
    private:
        float m_Width, m_Height;
    };

    class RIB_API WindowSelectedEvent : public Event
    {
    public:
        WindowSelectedEvent() {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowSelectedEvent: ";
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowSelected)
        EVENT_CLASS_CATEGORY(EventCategory::App)
    };

    class RIB_API WindowUnselectedEvent : public Event
    {
    public:
        WindowUnselectedEvent() {}
        
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowUnselectedEvent: ";
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowUnselected)
        EVENT_CLASS_CATEGORY(EventCategory::App)
    };

    class RIB_API AppTickedEvent : public Event
    {
    public:
        AppTickedEvent() {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "AppTickedEvent: ";
            return ss.str();
        }

        EVENT_CLASS_TYPE(AppTicked)
        EVENT_CLASS_CATEGORY(EventCategory::App)
    };

    class RIB_API AppUpdatedEvent : public Event
    {
    public:
        AppUpdatedEvent() {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "AppUpdatedEvent: ";
            return ss.str();
        }

        EVENT_CLASS_TYPE(AppUpdated)
        EVENT_CLASS_CATEGORY(EventCategory::App)
    };

    class RIB_API AppRenderedEvent : public Event
    {
    public:
        AppRenderedEvent() {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "AppRenderedEvent: ";
            return ss.str();
        }

        EVENT_CLASS_TYPE(AppRendered)
        EVENT_CLASS_CATEGORY(EventCategory::App)
    };
} // namespace Ribbon

