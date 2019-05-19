#pragma once

#include <components/table.hpp>
#include "vector.hpp"
#include "texture.hpp"
#include "physics.hpp"
#include "draw.hpp"

void create_asteroid(
    components::table<vectoru32>& grid_position_table,
    components::table<vectorf32>& real_position_table,
    components::table<vectorf32>& velocity_table,
    components::table<texture>& texture_table,
    components::table<physics_object>& physics_objects,
    components::table<draw_object>& draw_objects);