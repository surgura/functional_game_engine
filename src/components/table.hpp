#pragma once

#include "collection.hpp"
#include <list>

namespace components
{

template <typename component_value>
class table : public collection<component_value>
{
    struct row;
    class reference_impl : public reference<component_value>::impl
    {
        typename std::list<row>::iterator container_iter;
    public:
        reference_impl(typename std::list<row>::iterator container_iter) :
            container_iter(container_iter)
        {}

        component_value& operator*() override
        {
            return container_iter->value;
        }

        component_value* operator->() override
        {
            return &container_iter->value;
        }
    };

    struct row
    {
        component_value value;
        reference_impl this_ref;
    };

    std::list<row> rows;
public:
    class iterator
    {
        typename std::list<row>::iterator iter;
    public:
        iterator(typename std::list<row>::iterator iter) :
            iter(iter)
        {}

        reference<component_value> operator*()
        {
            return { iter->this_ref };
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
    
    reference<component_value> add(component_value&& item) override
    {
        rows.push_front({ item, { rows.end() } });
        rows.back().this_ref = { rows.begin() };
        return { rows.back().this_ref };
    }

    void remove(reference<component_value>& contained_component)
    {
        // TODO
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