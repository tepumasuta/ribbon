#include "app_event.hpp"
#include "key_event.hpp"
#include "mouse_event.hpp"

namespace Ribbon
{
namespace Events
{
    // event
    using namespace std::string_literals;
    std::array<std::string, 6UL> EngineEnumRepresentations{
        "None"s,
        "App"s,
        "Input"s,
        "Keyboard"s,
        "Mouse"s,
        "MouseButton"s,
    };

    // app_event
    std::ostream& operator<<(std::ostream& out, const WindowClosedEvent& e)
    {
        return out << "WindowClosedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    std::ostream& operator<<(std::ostream& out, const WindowMovedEvent& e)
    {
        return out << "WindowMovedEvent{"
            << "X: " << e.GetX() << ", Y: " << e.GetY() << ", "
            << EngineCategoryToPrintable(e.GetCategory())
            << "}";
    }

    std::ostream& operator<<(std::ostream& out, const WindowResizedEvent& e)
    {
        return out << "WindowMovedEvent{"
            << "Width: " << e.GetWidth() << ", Height: " << e.GetHeight() << ", "
            << EngineCategoryToPrintable(e.GetCategory())
            << "}";
    }

    std::ostream& operator<<(std::ostream& out, const WindowSelectedEvent& e)
    {
        return out << "WindowSelectedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    std::ostream& operator<<(std::ostream& out, const WindowUnselectedEvent& e)
    {
        return out << "WindowUnselectedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    std::ostream& operator<<(std::ostream& out, const AppTickedEvent& e)
    {
        return out << "AppTickedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    std::ostream& operator<<(std::ostream& out, const AppUpdatedEvent& e)
    {
        return out << "AppUpdatedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    std::ostream& operator<<(std::ostream& out, const AppRenderedEvent& e)
    {
        return out << "AppRenderedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    // key_event
    std::ostream& operator<<(std::ostream& out, const KeyPressedEvent& e)
    {
        return out
            << "KeyPressedEvent{" << (e.m_Handled ? "Handled" : "Unhandled") << ", "
            << "KeyCode: `" << e.m_KeyCode << "`, " << "Repeats: " << e.m_RepeatCount << ", "
            << EngineCategoryToPrintable(e.GetCategory())
            << "}";
    }

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

    // mouse_event
    std::ostream& operator<<(std::ostream& out, const MouseButtonPressedEvent& e)
    {
        return out << "MouseButtonPressedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    std::ostream& operator<<(std::ostream& out, const MouseButtonReleasedEvent& e)
    {
        return out << "MouseButtonReleasedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    std::ostream& operator<<(std::ostream& out, const MouseScrolledEvent& e)
    {
        return out << "MouseScrolledEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }

    std::ostream& operator<<(std::ostream& out, const MouseMovedEvent& e)
    {
        return out << "MouseMovedEvent{" << EngineCategoryToPrintable(e.GetCategory()) << "}";
    }
} // namespace Events
} // namespace Ribbon

