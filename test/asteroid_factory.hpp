#pragma once

#include <components/table.hpp>
#include "vector.hpp"
#include "texture.hpp"
#include "physics.hpp"
#include "draw.hpp"

void create_asteroid(
    components::table<vector>& position_table,
    components::table<vector>& velocity_table,
    components::table<texture>& texture_table,
    components::table<physics_object>& physics_objects,
    components::table<draw_object>& draw_objects);