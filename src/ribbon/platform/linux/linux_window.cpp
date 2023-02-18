#include "pch/ribpch.hpp"
#include "linux_window.hpp"

namespace Ribbon
{
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char* description)
	{
        RIB_ENGINE_ERROR << "GLFW Error #" << error << ": " << description;
	}

    Window* Window::Create(const WindowProps& props)
    {
        return new LinuxWindow(props);
    }

    LinuxWindow::LinuxWindow(const WindowProps& props) : m_Data(m_EventData) { Init(props); }
    LinuxWindow::~LinuxWindow() { Shutdown(); }

    void LinuxWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        RIB_INFO << "Creating window `" << props.Title << "` (" << props.Width << ", " << props.Height << ")";
        
        if (!s_GLFWInitialized)
        {
            // TODO: glfwTerminate on system shutdown
            
            int succsess = glfwInit();
            RIB_ENGINE_ASSERT(succsess, "Couldn't initialize GLFW!");

            glfwSetErrorCallback(GLFWErrorCallback);

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        // Set GLFW Callbacks
        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            
            Events::WindowClosedEvent& event = data.EventData.WindowClosedEvent;
            event.Handled = false;
            event.Happen();
        });
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            Events::WindowResizedEvent& event = data.EventData.WindowResizedEvent;
            event.Width = width;
            event.Height = height;
            event.Handled = false;
            
            data.Width = width;
            data.Height = height;
            
            event.Happen();
        });
        glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            if (focused == GLFW_TRUE)
            {
                Events::WindowSelectedEvent& event = data.EventData.WindowSelectedEvent;
                event.Handled = false;
                event.Happen();
            }
            else
            {
                Events::WindowUnselectedEvent& event = data.EventData.WindowUnselectedEvent;
                event.Handled = false;
                event.Happen();
            }
        });
        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int modes)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            // TODO: Convert glfw key to Ribbon keycode

            switch (action)
            {
                case GLFW_PRESS:
                {
                    Events::KeyPressedEvent& event = data.EventData.KeyPressedEvent;
                    event.KeyCode = key;
                    event.RepeatCount = 0;
                    event.Handled = false;
                    event.Happen();
                    break;
                }
                case GLFW_RELEASE:
                {
                    Events::KeyReleasedEvent& event = data.EventData.KeyReleasedEvent;
                    event.KeyCode = key;
                    event.Handled = false;
                    event.Happen();
                    break;
                }
                case GLFW_REPEAT:
                {
                    Events::KeyPressedEvent& event = data.EventData.KeyPressedEvent;
                    event.KeyCode = key;
                    event.RepeatCount++;
                    event.Handled = false;
                    event.Happen();
                    break;
                }
            }
        });
        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            // TODO: Convert glfw button to Ribbon button

            switch (action)
            {
                case GLFW_PRESS:
                {
                    Events::MouseButtonPressedEvent& event = data.EventData.MouseButtonPressedEvent;
                    event.Button = button;
                    event.Handled = false;
                    event.Happen();
                    break;
                }
                case GLFW_RELEASE:
                {
                    Events::MouseButtonReleasedEvent& event = data.EventData.MouseButtonReleasedEvent;
                    event.Button = button;
                    event.Handled = false;
                    event.Happen();
                    break;
                }
            }
        });
        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            Events::MouseScrolledEvent& event = data.EventData.MouseScrolledEvent;
            event.XOffset = xoffset;
            event.YOffset = yoffset;
            event.Handled = false;
            event.Happen();
        });
        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            Events::MouseMovedEvent& event = data.EventData.MouseMovedEvent;
            event.MouseX = xpos;
            event.MouseY = ypos;
            event.Handled = false;
            event.Happen();
        });
        glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xpos, int ypos)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            Events::WindowMovedEvent& event = data.EventData.WindowMovedEvent;
            event.WindowX = xpos;
            event.WindowY = ypos;
            event.Handled = false;
            event.Happen();
        });
    }

    void LinuxWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }
    
    void LinuxWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void LinuxWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool LinuxWindow::IsVSync() const { return m_Data.VSync; }
} // namespace Ribbon
