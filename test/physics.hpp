#pragma once

#include <components/reference.hpp>
#include "vector.hpp"
#include <components/table.hpp>

struct physics_object
{
	components::reference<vectorf32> real_position;
	components::reference<vectoru32> grid_position;
	components::reference<vectorf32> velocity;
};

void physics_step(components::table<physics_object>& physics_objects);