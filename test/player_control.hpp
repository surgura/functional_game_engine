#pragma once

#include <components/reference.hpp>
#include "vector.hpp"
#include <components/table.hpp>
#include "input.hpp"

struct player_control_object
{
	components::reference<vector> velocity;
};

void control_player(player_control_object& player, input_state const& input);