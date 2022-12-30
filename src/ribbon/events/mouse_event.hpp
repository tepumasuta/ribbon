#pragma once

#include "event.hpp"

namespace Ribbon
{
namespace Events
{
    template<class E>
    class RIB_API MouseButtonEvent : public EngineEvent<E>
    {
    protected:
        constexpr MouseButtonEvent(uint_fast8_t button)
            : m_Button(button) {}

        EVENT_CATEGORY(EngineEnum::Input, EngineEnum::Mouse, EngineEnum::MouseButton)
        uint_fast8_t m_Button;
    };

    class RIB_API MouseButtonPressedEvent : public MouseButtonEvent<MouseButtonPressedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const MouseButtonPressedEvent& e);
    public:
        constexpr MouseButtonPressedEvent(uint_fast8_t button)
            : MouseButtonEvent(button) {}
        
        EVENT_HAPPEN()
    };

    std::ostream& operator<<(std::ostream& out, const MouseButtonPressedEvent& e)
    {
        return out << "MouseButtonPressedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    class RIB_API MouseButtonReleasedEvent : public MouseButtonEvent<MouseButtonReleasedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const MouseButtonReleasedEvent& e);
    public:
        constexpr MouseButtonReleasedEvent(uint_fast8_t button)
            : MouseButtonEvent(button) {}
        
        EVENT_HAPPEN()
    };

    std::ostream& operator<<(std::ostream& out, const MouseButtonReleasedEvent& e)
    {
        return out << "MouseButtonReleasedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    class RIB_API MouseScrolledEvent : public EngineEvent<MouseScrolledEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const MouseScrolledEvent& e);
    public:
        constexpr MouseScrolledEvent(double xOffset, double YOffset)
            : m_XOffset(xOffset), m_YOffset(YOffset) {}

        constexpr inline double GetXOffset() const { return m_XOffset; }
        constexpr inline double GetYOffset() const { return m_YOffset; }

        EVENT_CATEGORY(EngineEnum::Input, EngineEnum::Mouse)
        EVENT_HAPPEN()
    private:
        double m_XOffset, m_YOffset;
    };
    
    std::ostream& operator<<(std::ostream& out, const MouseScrolledEvent& e)
    {
        return out << "MouseScrolledEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    class RIB_API MouseMovedEvent : public EngineEvent<MouseMovedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const MouseMovedEvent& e);
    public:
        constexpr MouseMovedEvent(double xOffset, double YOffset)
            : m_MouseX(xOffset), m_MouseY(YOffset) {}

        constexpr inline double GetX() const { return m_MouseX; }
        constexpr inline double GetY() const { return m_MouseY; }

        EVENT_CATEGORY(EngineEnum::Input, EngineEnum::Mouse)
        EVENT_HAPPEN()
    private:
        double m_MouseX, m_MouseY;
    };
    
    std::ostream& operator<<(std::ostream& out, const MouseMovedEvent& e)
    {
        return out << "MouseMovedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }
} // namespace Events
} // namespace Ribbon

