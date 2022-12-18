#pragma once

#include "event.hpp"

#include <sstream>

namespace Ribbon
{
    class RIB_API KeyEvent : public Event
    {
    public:
        inline u64 GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategory::Keyboard, EventCategory::Input)
    protected:
        KeyEvent(u64 keycode)
            : m_KeyCode(keycode) {}
        
        u64 m_KeyCode;
    };

    class RIB_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(u64 keycode, u64 repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {}
        
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        u64 m_RepeatCount;
    };
    
    class RIB_API KeyReleasedEvent : KeyEvent
    {
    public:
        KeyReleasedEvent(u64 keycode)
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

