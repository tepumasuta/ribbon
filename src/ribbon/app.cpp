#include "app.hpp"

#include <GLFW/glfw3.h>
namespace Ribbon
{
    App::App()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }
    
    App::~App() {}
    
    void App::Run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }
} // namespace Ribbon
