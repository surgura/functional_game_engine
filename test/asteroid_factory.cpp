#include "asteroid_factory.hpp"
#include <iostream>

void create_asteroid(
    components::table<vectoru32>& grid_position_table,
    components::table<vectorf32>& real_position_table,
    components::table<vectorf32>& velocity_table,
    components::table<texture>& texture_table,
    components::table<physics_object>& physics_objects,
    components::table<draw_object>& draw_objects)
{
    auto& grid_position = grid_position_table.add({ 18, 3 });
	auto& real_position = real_position_table.add({ (f32)grid_position->x, (f32)grid_position->y });
	auto& velocity = velocity_table.add({ -0.1_f32, 0 });
	auto& tex = texture_table.add({ 'O' });
	physics_objects.add({ real_position, grid_position, velocity });
	draw_objects.add({ grid_position, tex });
}