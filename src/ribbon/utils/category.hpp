#pragma once

#include "common.hpp"
#include "enum.hpp"

#include <bitset>

namespace Ribbon
{
namespace Categories
{
    template<typename T> concept enumerate = requires(T x)
    {
        { static_cast<std::size_t>(T::SIZE) };
        { static_cast<std::size_t>(x) };
    };

    template<enumerate T, std::convertible_to<std::size_t> I, std::size_t S>
    struct PrintableCategory;

    template<enumerate T, std::convertible_to<std::size_t> I>
    class Category
    {
        template<enumerate, std::convertible_to<std::size_t>, std::size_t>
        friend class PrintableCategory;
        template<enumerate T1, std::convertible_to<std::size_t> I1, std::size_t S>
        friend std::ostream& operator<<(std::ostream& out, const PrintableCategory<T1, I1, S>& c);
    public:
        constexpr Category() : m_Enabled() {}
        template<class... Cs>
        constexpr Category(Cs... categories) : m_Enabled(Enumerations::ToBits<I, Cs...>(categories...)) {}
        constexpr Category(const std::bitset<static_cast<std::size_t>(T::SIZE)>& bitset) : m_Enabled(bitset) {}
        constexpr Category(const Category<T, I>& category) : m_Enabled(category.m_Enabled) {}

        constexpr Category<T, I> operator|(const Category<T, I>& category) const
        {
            return Category<T, I>().m_Enabled | m_Enabled;
        }
        constexpr Category<T, I> operator&(const Category<T, I>& category) const
        {
            return Category<T, I>().m_Enabled & m_Enabled;
        }

        constexpr Category<T, I>& operator|=(const Category<T, I>& category)
        {
            m_Enabled |= Category<T, I>().m_Enabled;
            return *this;
        }
        constexpr Category<T, I>& operator&=(const Category<T, I>& category)
        {
            m_Enabled &= Category<T, I>().m_Enabled;
            return *this;
        }

        inline constexpr bool IsEmpty() { return m_Enabled.none(); }
        inline constexpr bool IsSuperset(const Category<T, I>& category)
        {
            return (m_Enabled | category.m_Enabled) == m_Enabled;
        }
        inline constexpr bool IsSubset(const Category<T, I>& category)
        {
            return (m_Enabled & category.m_Enabled) == m_Enabled;
        }

        inline static constexpr std::size_t GetSize() { return static_cast<std::size_t>(T::SIZE); }

        constexpr operator std::bitset<static_cast<std::size_t>(T::SIZE)>() const { return m_Enabled; }
    private:
        std::bitset<static_cast<std::size_t>(T::SIZE)> m_Enabled;
    };

    template<enumerate T, std::convertible_to<std::size_t> I, std::size_t S>
    struct PrintableCategory
    {
        friend std::ostream& operator<<<>(std::ostream& out, const PrintableCategory<T, I, S>& c);
        constexpr PrintableCategory(
            const Category<T, I>& category,
            const Enumerations::PrintableEnumeration<T, S>& enumeration
        ) : category(category), converter(enumeration) {}

        const Category<T, I>& category;
        mutable Enumerations::PrintableEnumeration<T, S> converter;
    };

    template<enumerate T, std::convertible_to<std::size_t> I, std::size_t S>
    std::ostream& operator<<(std::ostream& out, const PrintableCategory<T, I, S>& c)
    {
        out << "Category{";
        bool first = true;
        for (std::size_t i = 0; i < c.category.GetSize(); i++)
        {
            if (c.category.m_Enabled.test(static_cast<I>(i)))
            {
                out << (first ? "" : ", ") << c.converter.Set(static_cast<T>(static_cast<I>(i)));
                first = false;
            }
        }
        return out  << "}";
    }
} // namespace Categories
} // namespace Ribbon
