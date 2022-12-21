#pragma once

#include "event.hpp"

#include <sstream>

namespace Ribbon
{
    class RIB_API KeyEvent : public Event
    {
    public:
        inline uint_fast32_t GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategory::Keyboard, EventCategory::Input)
    protected:
        KeyEvent(uint_fast32_t keycode)
            : m_KeyCode(keycode) {}
        
        uint_fast32_t m_KeyCode;
    };

    class RIB_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(uint_fast32_t keycode, uint_fast32_t repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {}
        
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        uint_fast32_t m_RepeatCount;
    };
    
    class RIB_API KeyReleasedEvent : KeyEvent
    {
    public:
        KeyReleasedEvent(uint_fast32_t keycode)
            : KeyEvent(keycode) {}
        
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
} // namespace Ribbon

