#include "physics.hpp"
#include <algorithm>
#include "types.hpp"

void physics_step(components::table<physics_object>& physics_objects)
{
	for (auto& row : physics_objects)
	{
		vectorf32& real_position = *row->real_position;
		vectoru32& grid_position = *row->grid_position;
		vectorf32& velocity = *row->velocity;

		real_position.x += velocity.x;
		real_position.y = std::clamp(real_position.y + velocity.y, 1.0_f32, 5.0_f32);

		grid_position.x = (u32)std::round(real_position.x);
		grid_position.y = (u32)std::round(real_position.y);
	}
}