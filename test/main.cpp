#include <components/table.hpp>
#include "vector.hpp"
#include "texture.hpp"
#include "physics.hpp"
#include "draw.hpp"
#include <thread>
#include "player_control.hpp"
#include "input.hpp"

#include <iostream>

int main()
{
	input_state input;

	components::table<vector> position_table;
	components::table<vector> velocity_table;
	components::table<texture> texture_table;
	components::table<physics_object> physics_objects;
	components::table<draw_object> draw_objects;

	// create the player
	auto position = position_table.add({ 1, 5 });
	auto velocity = velocity_table.add({ 0, 0 });
	auto texture = texture_table.add({ 'P' });
	physics_objects.add({ position, velocity });
	draw_objects.add({ position, texture });
	player_control_object player{velocity};

	while(true)
	{
		read_input(input);
		if (input.escape_pressed) {
			break;
		}
		control_player(player, input);
		physics_step(physics_objects);
		draw(draw_objects);
		std::this_thread::sleep_for(std::chrono::milliseconds(33));
	}
	return 0;
}
