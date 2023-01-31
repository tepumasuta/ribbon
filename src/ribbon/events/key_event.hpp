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
        constexpr inline uint_fast32_t GetKeyCode() const { return m_KeyCode;  }
        EVENT_CATEGORY(EngineEnum::Keyboard, EngineEnum::Input)
    protected:
        constexpr KeyEvent(uint_fast32_t keycode)
            : m_KeyCode(keycode) {}

        uint_fast32_t m_KeyCode;
    };

    class RIB_API KeyPressedEvent : public KeyEvent<KeyPressedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const KeyPressedEvent& e);
    public:
        constexpr KeyPressedEvent(uint_fast32_t keycode, uint_fast32_t repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {}
        
        EVENT_HAPPEN()
    private:
        uint_fast32_t m_RepeatCount;
    };
    extern std::ostream& operator<<(std::ostream& out, const KeyPressedEvent& e);

    class RIB_API KeyReleasedEvent : public KeyEvent<KeyReleasedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const KeyReleasedEvent& e);
    public:
        constexpr KeyReleasedEvent(uint_fast32_t keycode)
            : KeyEvent(keycode) {}
        
        EVENT_HAPPEN()
    };

    extern std::ostream& operator<<(std::ostream& out, const KeyReleasedEvent& e);
} // namespace Events
} // namespace Ribbon

