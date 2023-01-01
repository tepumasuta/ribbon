#pragma once

#include "common.hpp"

#include "pch/ribpch.hpp"

namespace Ribbon
{
namespace Enumerations
{
    template<std::convertible_to<std::size_t> I, typename... Ts>
    constexpr I ToBits(Ts... args)
    {
        I result = 0;
        for (auto x: { args... })
            result |= 1 << static_cast<I>(x);
        return result;
    };

    template<typename E, std::size_t S>
    struct PrintableEnumeration
    {
        friend std::ostream& operator<<<>(std::ostream& out, const PrintableEnumeration<E, S>& e);
        
        constexpr PrintableEnumeration(
            const E& enumeration,
            const std::array<std::string, S>& table
        ) : m_Type(enumeration), m_Table(table)
        {}

        PrintableEnumeration<E, S>& Set(const E& enumeration) { m_Type = enumeration; return *this; }

    private:
        E m_Type;
        const std::array<std::string, S>& m_Table;
    };

    template<typename E, std::size_t S>
    std::ostream& operator<<(std::ostream& out, const PrintableEnumeration<E, S>& e)
    {
        return out << e.m_Table[static_cast<std::size_t>(e.m_Type)];
    }
} // namespace Enumerations
} // namespace Ribbon
