#include "player_control.hpp"

void control_player(player_control_object& player, input_state const& input)
{
	player.velocity->x = 0;
	player.velocity->y = 0;

	if (input.up_pressed) {
		player.velocity->y += 1;
	}
	if (input.down_pressed) {
		player.velocity->y -= 1;
	}
	if (input.right_pressed) {
		player.velocity->x += 1;
	}
	if (input.left_pressed) {
		player.velocity->x -= 1;
	}
}