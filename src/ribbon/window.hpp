#pragma once

#include "pch/ribpch.hpp"
#include "common.hpp"
#include "events/app_event.hpp"

namespace Ribbon
{
    struct WindowProps
    {
        std::string Title;
        uint_fast32_t Width, Height;

        WindowProps(const std::string& title = "Ribbon Engine",
                    uint_fast32_t width = 1280, uint_fast32_t height = 720)
            : Title(title), Width(width), Height(height)
        {}
    };

    // Interface for desktop window
    class RIB_API Window
    {
    public:
        using EventCallback = std::function<void()>;

        Window(){};
        virtual ~Window() {};

        virtual void OnUpdate() = 0;

                virtual uint_fast32_t GetHeight() const = 0;
        virtual uint_fast32_t GetWidth() const = 0;

        // Window attributes
        virtual void SetWindowClosedEventCallback(const EventCallback& fn) = 0;
        virtual void SetWindowMovedEventCallback(const EventCallback& fn) = 0;
        virtual void SetWindowResizedEventCallback(const EventCallback& fn) = 0;
        virtual void SetWindowSelectedEventCallback(const EventCallback& fn) = 0;
        virtual void SetWindowUnselectedEventCallback(const EventCallback& fn) = 0;

        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
} // namespace Ribbon
