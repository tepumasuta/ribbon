#pragma once

#include "common.hpp"
#include "utils/category.hpp"

#include "pch/ribpch.hpp"

namespace Ribbon
{
namespace Events
{
    enum class EngineEnum : uint_fast8_t
    {
        None = 0, App, Input, Keyboard, Mouse, MouseButton, SIZE
    };
    using EngineCategory = Categories::Category<EngineEnum, uint_fast8_t>;
    extern std::array<std::string, 6UL> EngineEnumRepresentations;

    constexpr Categories::PrintableCategory<
        EngineEnum,
        uint_fast8_t,
        static_cast<std::size_t>(EngineEnum::SIZE)
    > EngineCategoryToPrintable(EngineCategory&& category)
    {
        return Categories::PrintableCategory<
            EngineEnum,
            uint_fast8_t,
            static_cast<std::size_t>(EngineEnum::SIZE)
        >(category, Enumerations::PrintableEnumeration<
            EngineEnum,
            static_cast<std::size_t>(EngineEnum::SIZE)
         >(EngineEnum::None, EngineEnumRepresentations));
    }

    template<class E>
    class RIB_API Listener
    {
    public:
        virtual void OnEvent(E& event) = 0;
    };

    template<class E>
    class RIB_API Event
    {
    public:
        virtual void Happen() = 0;
        virtual Listener<E>*& Subscribe(Listener<E>& listener) final
        {
            m_Listeners.emplace_back(&listener);
            return m_Listeners.back();
        }
        virtual void Unsubscribe(const Listener<E>& listener) final
        {
            for (auto& ptr: m_Listeners)
            {
                if (ptr && &listener == ptr)
                {
                    ptr = nullptr;
                    break;
                }
            }
        }
        virtual void Unsubscribe(Listener<E>*& listener) final
        {
            listener = nullptr;
        }
    protected:
        constexpr Event() {}
        virtual void Notify(E* ptr)
        {
            for (std::size_t i = 0, j = 0; i < m_Listeners.size(); i++)
            {
                const auto& link = m_Listeners[i];
                if (link)
                {
                    m_Listeners[j++] = link;
                    link->OnEvent(*ptr);
                }
            }
        }
        std::vector<Listener<E>*> m_Listeners;
    };

    template<class E>
    class RIB_API Retranslator : public Listener<E>, public Event<E>
    {
    public:
        virtual void Happen() final = 0;
    };


    template<class E>
    class RIB_API EngineEvent : public Event<E>
    {
    public:
        constexpr virtual EngineCategory GetCategory() const = 0;
        constexpr bool IsInCategory(const EngineCategory& category) const
        {
            return GetCategory().IsSuperset(category);
        };
    protected:
        constexpr EngineEvent() {}
        bool m_Handled = false;
    };

} // namespace event
} // namespace Ribbon

#define EVENT_CATEGORY(...) constexpr EngineCategory GetCategory() const override { return GetStaticCategory(); }\
constexpr static inline EngineCategory GetStaticCategory()\
{\
    return EngineCategory(__VA_ARGS__);\
}
#define EVENT_HAPPEN() void Happen() override { Notify(this); }
