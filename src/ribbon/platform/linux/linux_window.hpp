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

            Window::WindowEventData& EventData;

            WindowData(Window::WindowEventData& eventData) : EventData(eventData) {}
        };

        WindowData m_Data;
    };
} // namespace Ribbon

