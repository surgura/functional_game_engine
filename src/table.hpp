#pragma once

#include <cstdint>
#include <tuple>

namespace tables
{

template <typename... columns>
using row = std::tuple<columns...>;

template <typename... columns>
class row_reference
{
public:
    row<columns...>& operator*();
};

template <typename... columns>
class table
{
public:
    class iterator
    {
    public:
        row<columns...>& operator*();
        bool operator !=(iterator const& other);
        void operator ++();
    };

    row_reference<columns...> add_row(row<columns...>&& new_row);
    
    iterator begin();
    iterator end();
};

}