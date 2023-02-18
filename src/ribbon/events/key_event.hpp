#pragma once

#include "event.hpp"

namespace Ribbon
{
namespace Events
{
    template<class E>
    class RIB_API KeyEvent : public EngineEvent<E>
    {
    public:
        EVENT_CATEGORY(EngineEnum::Keyboard, EngineEnum::Input)
    protected:
        constexpr explicit KeyEvent() {}
        constexpr KeyEvent(uint_fast32_t keycode)
            : KeyCode(keycode) {}
    public:
        uint_fast32_t KeyCode;
    };

    class RIB_API KeyPressedEvent : public KeyEvent<KeyPressedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const KeyPressedEvent& e);
    public:
        constexpr KeyPressedEvent() : KeyEvent() {}
        constexpr KeyPressedEvent(uint_fast32_t keycode, uint_fast32_t repeatCount)
            : KeyEvent(keycode), RepeatCount(repeatCount) {}
        
        EVENT_HAPPEN()
    public:
        uint_fast32_t RepeatCount;
    };
    extern std::ostream& operator<<(std::ostream& out, const KeyPressedEvent& e);

    class RIB_API KeyReleasedEvent : public KeyEvent<KeyReleasedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const KeyReleasedEvent& e);
    public:
        constexpr KeyReleasedEvent()
            : KeyEvent() {}
        constexpr KeyReleasedEvent(uint_fast32_t keycode)
            : KeyEvent(keycode) {}
        
        EVENT_HAPPEN()
    };

    extern std::ostream& operator<<(std::ostream& out, const KeyReleasedEvent& e);
} // namespace Events
} // namespace Ribbon

