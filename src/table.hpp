#pragma once

#include <cstdint>
#include <tuple>
#include <list>

namespace tables
{

template <typename... columns>
class row_t
{
    std::tuple<columns...> data;
public:
    row_t(std::tuple<columns...>&& data) :
        data(data)
    {}

    template <uint8_t index>
    auto& get()
    {
        return std::get<index>(data);
    }
};

template <typename... columns>
class row_reference_t
{
    row_t<columns...>& row;  
public:
    row_reference_t(row_t<columns...>& row) :
        row(row)
    {}
    row_t<columns...>& operator*() { return row; }
    row_t<columns...>* operator->() { return &row; }
};

template <typename... columns>
class table_t
{
    std::list<row_t<columns...>> rows;
public:
    class iterator
    {
        typename std::list<row_t<columns...>>::iterator iter;
    public:
        iterator(typename std::list<row_t<columns...>>::iterator iter) :
            iter(iter)
        {}

        row_reference_t<columns...> operator*()
        {
            return { *iter };
        }
        
        bool operator !=(iterator const& other)
        {
            return iter != other.iter;
        }

        void operator ++()
        {
            iter++;
        }
    };

    row_reference_t<columns...> add_row(row_t<columns...>&& new_row)
    {
        rows.push_back(new_row);
        return { rows.back() };
    }
    
    iterator begin()
    {
        return { rows.begin() };
    }

    iterator end()
    {
        return { rows.end() };
    }

};

}