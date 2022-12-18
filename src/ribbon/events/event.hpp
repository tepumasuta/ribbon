#pragma once

#include "common.hpp"

#include <typeinfo>
#include <type_traits>
#include <string>
#include <functional>
#include <bitset>
#include <array>

namespace Ribbon
{
    enum class EventCategory : u64
    {
        None = 0, App, Input, Keyboard, Mouse, MouseButton, SIZE
    };
    using EventCategoryType = std::bitset<static_cast<u64>(EventCategory::SIZE)>;

    class RIB_API Event
    {
        friend class EventDispatcher;
    public:
        virtual const char* GetName() const = 0;
        virtual EventCategoryType GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(const EventCategoryType& category)
        {
            return (GetCategoryFlags() & category).any();
        }
    protected:
        bool m_Handled = false;
    };

    template<typename T>
    concept Eventlike = std::is_base_of<T, Event>::value;

#define EVENT_CLASS_TYPE(type) virtual const char* GetName() const override { return #type; }
    
#define EVENT_CLASS_CATEGORY(...) virtual EventCategoryType GetCategoryFlags() const override\
                                  {\
                                      EventCategoryType res;\
                                      for (const auto& type: {__VA_ARGS__}) { res.set(static_cast<u64>(type)); }\
                                      return res;\
                                  }

    class EventDispatcher
    {
        template<Eventlike T>
        using Handler = std::function<bool(T&)>;
    public:
        EventDispatcher(Event& e)
            : m_Event(e) {}
        
        template<Eventlike T>
        bool Dispatch(Handler<T> f)
        {
            if (typeid(m_Event) == typeid(T))
            {
                m_Event.m_Handled = f(dynamic_cast<T&>(m_Event));
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& out, const Event& e)
    {
        return out << e.ToString();
    }
} // namespace Ribbon

