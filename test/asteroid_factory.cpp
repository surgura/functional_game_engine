#include "asteroid_factory.hpp"
#include <iostream>

void create_asteroid(
    components::table<vector>& position_table,
    components::table<vector>& velocity_table,
    components::table<texture>& texture_table,
    components::table<physics_object>& physics_objects,
    components::table<draw_object>& draw_objects)
{
	auto& position = position_table.add({ 2, 6 });
	auto& velocity = velocity_table.add({ 0, 0 });
	auto& tex = texture_table.add({ 'O' });
	physics_objects.add({ position, velocity });
	draw_objects.add({ position, tex });
}