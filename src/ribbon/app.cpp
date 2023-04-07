#include "app.hpp"

#include <GLFW/glfw3.h>

namespace Ribbon
{
    App::App()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        
        m_Window->GetWindowClosedEvent().Subscribe(*this);
        m_Window->GetWindowMovedEvent().Subscribe(*this);
        m_Window->GetWindowResizedEvent().Subscribe(*this);
        m_Window->GetWindowSelectedEvent().Subscribe(*this);
        m_Window->GetWindowUnselectedEvent().Subscribe(*this);
        m_Window->GetKeyPressedEvent().Subscribe(*this);
        m_Window->GetKeyReleasedEvent().Subscribe(*this);
        m_Window->GetMouseButtonPressedEvent().Subscribe(*this);
        m_Window->GetMouseButtonReleasedEvent().Subscribe(*this);
        m_Window->GetMouseMovedEvent().Subscribe(*this);
        m_Window->GetMouseScrolledEvent().Subscribe(*this);
    }
    
    App::~App()
    {
        m_Window->GetWindowClosedEvent().Unsubscribe(*this);
        m_Window->GetWindowMovedEvent().Unsubscribe(*this);
        m_Window->GetWindowResizedEvent().Unsubscribe(*this);
        m_Window->GetWindowSelectedEvent().Unsubscribe(*this);
        m_Window->GetWindowUnselectedEvent().Unsubscribe(*this);
        m_Window->GetKeyPressedEvent().Unsubscribe(*this);
        m_Window->GetKeyReleasedEvent().Unsubscribe(*this);
        m_Window->GetMouseButtonPressedEvent().Unsubscribe(*this);
        m_Window->GetMouseButtonReleasedEvent().Unsubscribe(*this);
        m_Window->GetMouseMovedEvent().Unsubscribe(*this);
        m_Window->GetMouseScrolledEvent().Unsubscribe(*this);
    }

    void App::Run()
    {
        while (m_Running)
        {
            for (auto* layer: m_LayerStack)
                layer->OnUpdate();

            m_Window->OnUpdate();
        }
    }
    
    void App::PushLayer(Layers::Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }
    
    void App::PushOverlay(Layers::Layer* overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }

    // Event handling

    void App::OnEvent(Events::WindowClosedEvent& e)
    {
        m_Running = false;
        Notify(&e);
        e.Handled = true;
    }
    void App::OnEvent(Events::MouseMovedEvent& e)
    {
        Notify(&e);
        e.Handled = true;
    }
} // namespace Ribbon
