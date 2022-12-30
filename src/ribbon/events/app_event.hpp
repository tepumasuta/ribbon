#pragma once

#include "event.hpp"

namespace Ribbon
{
namespace Events
{
    class RIB_API WindowClosedEvent : public EngineEvent<WindowClosedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const WindowClosedEvent& e);
    public:
        constexpr WindowClosedEvent() {}

        EVENT_CATEGORY(EngineEnum::App)
        EVENT_HAPPEN()
    };

    std::ostream& operator<<(std::ostream& out, const WindowClosedEvent& e)
    {
        return out << "WindowClosedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    class RIB_API WindowMovedEvent : public EngineEvent<WindowMovedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const WindowMovedEvent& e);
    public:
        constexpr WindowMovedEvent(double x, double y)
            : m_WindowX(x), m_WindowY(y) {}

        EVENT_CATEGORY(EngineEnum::App)
        EVENT_HAPPEN()

        constexpr inline double GetX() const { return m_WindowX; }
        constexpr inline double GetY() const { return m_WindowY; }
    private:
        double m_WindowX, m_WindowY;
    };

    std::ostream& operator<<(std::ostream& out, const WindowMovedEvent& e)
    {
        return out << "WindowMovedEvent{"
            << "X: " << e.GetX() << ", Y: " << e.GetY() << ", "
            << EngineCategoryToPrintable(e.GetCategory())
            << "}";
    }

    class RIB_API WindowResizedEvent : public EngineEvent<WindowResizedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const WindowResizedEvent& e);
    public:
        constexpr WindowResizedEvent(double width, double height)
            : m_Width(width), m_Height(height) {}

        EVENT_CATEGORY(EngineEnum::App)
        EVENT_HAPPEN()

        constexpr inline double GetWidth() const { return m_Width; }
        constexpr inline double GetHeight() const { return m_Height; }
    private:
        double m_Width, m_Height;
    };

    std::ostream& operator<<(std::ostream& out, const WindowResizedEvent& e)
    {
        return out << "WindowMovedEvent{"
            << "Width: " << e.GetWidth() << ", Height: " << e.GetHeight() << ", "
            << EngineCategoryToPrintable(e.GetCategory())
            << "}";
    }

    class RIB_API WindowSelectedEvent : public EngineEvent<WindowSelectedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const WindowSelectedEvent& e);
    public:
        constexpr WindowSelectedEvent() {}

        EVENT_CATEGORY(EngineEnum::App)
        EVENT_HAPPEN()
    };

    std::ostream& operator<<(std::ostream& out, const WindowSelectedEvent& e)
    {
        return out << "WindowSelectedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    class RIB_API WindowUnselectedEvent : public EngineEvent<WindowUnselectedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const WindowUnselectedEvent& e);
    public:
        constexpr WindowUnselectedEvent() {}

        EVENT_CATEGORY(EngineEnum::App)
        EVENT_HAPPEN()
    };

    std::ostream& operator<<(std::ostream& out, const WindowUnselectedEvent& e)
    {
        return out << "WindowUnselectedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    class RIB_API AppTickedEvent : public EngineEvent<AppTickedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const AppTickedEvent& e);
    public:
        constexpr AppTickedEvent() {}

        EVENT_CATEGORY(EngineEnum::App)
        EVENT_HAPPEN()
    };

    std::ostream& operator<<(std::ostream& out, const AppTickedEvent& e)
    {
        return out << "AppTickedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    class RIB_API AppUpdatedEvent : public EngineEvent<AppUpdatedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const AppUpdatedEvent& e);
    public:
        constexpr AppUpdatedEvent() {}

        EVENT_CATEGORY(EngineEnum::App)
        EVENT_HAPPEN()
    };

    std::ostream& operator<<(std::ostream& out, const AppUpdatedEvent& e)
    {
        return out << "AppUpdatedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    class RIB_API AppRenderedEvent : public EngineEvent<AppRenderedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const AppRenderedEvent& e);
    public:
        constexpr AppRenderedEvent() {}

        EVENT_CATEGORY(EngineEnum::App)
        EVENT_HAPPEN()
    };

    std::ostream& operator<<(std::ostream& out, const AppRenderedEvent& e)
    {
        return out << "AppRenderedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

} // namespace Events
} // namespace Ribbon

