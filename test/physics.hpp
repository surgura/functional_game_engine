#pragma once

#include <components/reference.hpp>
#include "vector.hpp"
#include <components/table.hpp>

struct physics_object
{
	components::reference<vector> position;
	components::reference<vector> velocity;
};

void physics_step(components::table<physics_object>& physics_objects);