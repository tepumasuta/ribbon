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

    using EnginePrintableCategory = Categories::PrintableCategory<
        EngineEnum,
        uint_fast8_t,
        static_cast<std::size_t>(EngineEnum::SIZE)
    >;

    constexpr EnginePrintableCategory EngineCategoryToPrintable(EngineCategory&& category)
    {
        return EnginePrintableCategory(
            category, Enumerations::PrintableEnumeration<
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
        virtual void Subscribe(Listener<E>& listener) final
        {
            m_Listeners.emplace_back(&listener);
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
    protected:
        constexpr Event() {}
        virtual void Notify(E* ptr)
        {
            std::size_t newSize = 0;
            for (std::size_t i = 0; i < m_Listeners.size(); i++)
            {
                const auto& link = m_Listeners[i];
                if (link)
                {
                    m_Listeners[newSize++] = link;
                    link->OnEvent(*ptr);
                }
            }
            m_Listeners.resize(newSize);
        }
        virtual std::vector<Listener<E>*>& GetListeners(E* ptr) final { (void)ptr; return m_Listeners; }
    protected:
        std::vector<Listener<E>*> m_Listeners;
    };

    template<class E>
    class RIB_API Retranslator : public Event<E>, public Listener<E>
    {
    public:
        virtual void Happen() final { RIB_ASSERT(false, "Happen function shouldn't be callable on Retranslators"); };
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
    public:
        bool Handled = false;
    };

    template<typename E>
    class RIB_API EngineRetranslator : public Retranslator<E>
    {
    public:
        virtual void OnEvent(E& event) override { Notify(&event); }
    protected:
        virtual void Notify(E* eventPtr) override
        {
            std::size_t newSize = 0;
            for (std::size_t i = 0; i < this->m_Listeners.size(); i++)
            {
                const auto& link = this->m_Listeners[i];
                if (link)
                {
                    this->m_Listeners[newSize++] = link;
                    if (!eventPtr->Handled)
                        link->OnEvent(*eventPtr);
                }
            }
            this->m_Listeners.resize(newSize);

            if (!eventPtr->Handled)
                HandleEvent(*eventPtr);
        }
        virtual void HandleEvent(E& eventPtr) { (void)eventPtr; }
    };
} // namespace event
} // namespace Ribbon

#define EVENT_CATEGORY(...) constexpr EngineCategory GetCategory() const override { return GetStaticCategory(); }\
constexpr static inline EngineCategory GetStaticCategory()\
{\
    return EngineCategory(__VA_ARGS__);\
}
#define EVENT_HAPPEN() void Happen() override { Notify(this); }
