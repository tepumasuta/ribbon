#pragma once

#include "window.hpp"

#include <GLFW/glfw3.h>

namespace Ribbon
{
    class LinuxWindow : public Window
    {
    public:
        LinuxWindow(const WindowProps& props);
        virtual ~LinuxWindow();

        void OnUpdate() override;

        inline uint_fast32_t GetWidth() const override { return m_Data.Width; }
        inline uint_fast32_t GetHeight() const override { return m_Data.Width; }

        // Window attributes
        void SetWindowClosedEventCallback(const EventCallback& fn) override { m_Data.WindowClosed = fn; }
        void SetWindowMovedEventCallback(const EventCallback& fn) override { m_Data.WindowMoved = fn; }
        void SetWindowResizedEventCallback(const EventCallback& fn) override { m_Data.WindowResized = fn; }
        void SetWindowSelectedEventCallback(const EventCallback& fn) override { m_Data.WindowSelected = fn; }
        void SetWindowUnselectedEventCallback(const EventCallback& fn) override { m_Data.WindowUnselected = fn; }

        void SetVSync(bool enabled) override;
        bool IsVSync() const override;
    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            uint_fast32_t Width, Height;
            bool VSync;

            EventCallback WindowClosed;
            EventCallback WindowMoved;
            EventCallback WindowResized;
            EventCallback WindowSelected;
            EventCallback WindowUnselected;
        };

        WindowData m_Data;
    };
} // namespace Ribbon

