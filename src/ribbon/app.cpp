#include "app.hpp"
#include "events/event.hpp"
#include "events/app_event.hpp"
#include "log.hpp"

namespace Ribbon
{
    App::App()
    {
    }
    
    App::~App()
    {
    }
    
    void App::Run()
    {
        WindowResizedEvent e(1280, 720);
        RIB_TRACE << e;
        RIB_TRACE << e.IsInCategory(Ribbon::EventCategoryType().set(static_cast<int>(Ribbon::EventCategory::App)));
        RIB_TRACE << e.IsInCategory(Ribbon::EventCategoryType().set(static_cast<int>(Ribbon::EventCategory::Keyboard)));
    }
} // namespace Ribbon
