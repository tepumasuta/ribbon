#include "app.hpp"

#include <GLFW/glfw3.h>

namespace Ribbon
{
    App::App()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());

        m_WindowClosedSubscriptionPtr = m_Window->GetWindowClosedEvent().Subscribe(*this);
    }
    
    App::~App()
    {
        m_Window->GetWindowClosedEvent().Unsubscribe(m_WindowClosedSubscriptionPtr);
    }

    void App::Run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }

    void App::OnEvent(Events::WindowClosedEvent& e)
    {
        m_Running = false;
        Notify(&e);
        e.Handled = true;
    }
} // namespace Ribbon
