#pragma once

#include <components/table.hpp>
#include "vector.hpp"
#include "texture.hpp"

struct draw_object
{
	components::reference<vector> position;
	components::reference<texture> texture;
};

void draw(components::table<draw_object>& draw_objects);