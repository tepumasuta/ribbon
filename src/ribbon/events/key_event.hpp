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

    std::ostream& operator<<(std::ostream& out, const KeyPressedEvent& e)
    {
        return out
            << "KeyPressedEvent{" << (e.m_Handled ? "Handled" : "Unhandled") << ", "
            << "KeyCode: `" << e.m_KeyCode << "`, " << "Repeats: " << e.m_RepeatCount << ", "
            << EngineCategoryToPrintable(e.GetCategory())
            << "}";
    }

    class RIB_API KeyReleasedEvent : public KeyEvent<KeyReleasedEvent>
    {
        friend std::ostream& operator<<(std::ostream& out, const KeyReleasedEvent& e);
    public:
        constexpr KeyReleasedEvent(uint_fast32_t keycode)
            : KeyEvent(keycode) {}
        
        EVENT_HAPPEN()
    };

    std::ostream& operator<<(std::ostream& out, const KeyReleasedEvent& e)
    {
        return out
            << "KeyReleasedEvent{" << (e.m_Handled ? "Handled" : "Unhandled") << ", "
            << "KeyCode: `" << e.m_KeyCode << "`, "
            << Categories::PrintableCategory<EngineEnum, uint_fast8_t, EngineEnumRepresentations.size()>(
                e.GetCategory(),
                Enumerations::PrintableEnumeration<EngineEnum, EngineEnumRepresentations.size()>(
                    EngineEnum::None,
                    EngineEnumRepresentations
                )
            ) << "}";
    }
} // namespace Events
} // namespace Ribbon

