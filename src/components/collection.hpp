#pragma once

#include "component.hpp"
#include "reference.hpp"

namespace components
{

template <typename component_value>
class collection
{
public:
    virtual reference<component_value> add(component_value&& item) = 0;
    virtual void remove(reference<component_value>& contained_component) = 0;
};

}