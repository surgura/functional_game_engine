#include <components/table.hpp>
#include "vector.hpp"
#include "texture.hpp"
#include "physics.hpp"
#include "draw.hpp"
#include <thread>
#include "player_control.hpp"
#include "input.hpp"
#include "asteroid_factory.hpp"

#include <iostream>

int main()
{
	input_state input;

	components::table<vectorf32> real_position_table;
	components::table<vectoru32> grid_position_table;
	components::table<vectorf32> velocity_table;
	components::table<texture> texture_table;
	components::table<physics_object> physics_objects;
	components::table<draw_object> draw_objects;

	// create the player
	auto& grid_position = grid_position_table.add({ 1, 3 });
	auto& real_position = real_position_table.add({ (f32)grid_position->x, (f32)grid_position->y });
	auto& velocity = velocity_table.add({ 0, 0 });
	auto& texture = texture_table.add({ 'P' });
	physics_objects.add({ real_position, grid_position, velocity });
	draw_objects.add({ grid_position, texture });
	player_control_object player{velocity};

	while(true)
	{
		read_input(input);
		if (input.escape_pressed) {
			break;
		}
		if (input.action_pressed) {
			create_asteroid(grid_position_table, real_position_table, velocity_table, texture_table, physics_objects, draw_objects);
		}
		control_player(player, input);
		physics_step(physics_objects);
		draw(draw_objects);
		std::this_thread::sleep_for(std::chrono::milliseconds(33));
	}
	return 0;
}
