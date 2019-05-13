#include "physics.hpp"

void physics_step(components::table<physics_object>& physics_objects)
{
	for (auto& row : physics_objects)
	{
		vector& position = *row->position;
		vector& velocity = *row->velocity;

		position.x += velocity.x;
		position.y += velocity.y;
	}
}