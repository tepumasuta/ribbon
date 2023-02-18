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
        constexpr explicit MouseButtonEvent() {}
        constexpr MouseButtonEvent(uint_fast8_t button)
            : Button(button) {}

        EVENT_CATEGORY(EngineEnum::Input, EngineEnum::Mouse, EngineEnum::MouseButton)
    public:
        uint_fast8_t Button;
    };

    class RIB_API MouseButtonPressedEvent : public MouseButtonEvent<MouseButtonPressedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const MouseButtonPressedEvent& e);
    public:
        constexpr MouseButtonPressedEvent() : MouseButtonEvent() {}
        constexpr MouseButtonPressedEvent(uint_fast8_t button)
            : MouseButtonEvent(button) {}
        
        EVENT_HAPPEN()
    };

    extern std::ostream& operator<<(std::ostream& out, const MouseButtonPressedEvent& e);

    class RIB_API MouseButtonReleasedEvent : public MouseButtonEvent<MouseButtonReleasedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const MouseButtonReleasedEvent& e);
    public:
        constexpr MouseButtonReleasedEvent() : MouseButtonEvent() {}
        constexpr MouseButtonReleasedEvent(uint_fast8_t button)
            : MouseButtonEvent(button) {}
        
        EVENT_HAPPEN()
    };

    extern std::ostream& operator<<(std::ostream& out, const MouseButtonReleasedEvent& e);

    class RIB_API MouseScrolledEvent : public EngineEvent<MouseScrolledEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const MouseScrolledEvent& e);
    public:
        constexpr MouseScrolledEvent() {}
        constexpr MouseScrolledEvent(double xOffset, double YOffset)
            : XOffset(xOffset), YOffset(YOffset) {}

        EVENT_CATEGORY(EngineEnum::Input, EngineEnum::Mouse)
        EVENT_HAPPEN()
    public:
        double XOffset, YOffset;
    };
    
    extern std::ostream& operator<<(std::ostream& out, const MouseScrolledEvent& e);

    class RIB_API MouseMovedEvent : public EngineEvent<MouseMovedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const MouseMovedEvent& e);
    public:
        constexpr MouseMovedEvent() {}
        constexpr MouseMovedEvent(double xOffset, double YOffset)
            : MouseX(xOffset), MouseY(YOffset) {}

        EVENT_CATEGORY(EngineEnum::Input, EngineEnum::Mouse)
        EVENT_HAPPEN()
    public:
        double MouseX, MouseY;
    };
    
    extern std::ostream& operator<<(std::ostream& out, const MouseMovedEvent& e);
} // namespace Events
} // namespace Ribbon

