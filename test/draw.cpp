#include "draw.hpp"
#include <iostream>
#include <array>
#include <string>
#include <iostream>

void draw(components::table<draw_object>& draw_objects)
{
	std::array<std::array<char, 20>, 20> screen;
	for (auto& row : screen)
	{
	   for (auto& entry : row)
	   {
		  entry = ' ';
	   }
	}
	for (auto& entry : screen[0])
	{
	   entry = '-';
	}
	for (auto& entry : screen[screen.size()-1])
	{
	   entry = '-';
	}
	for (auto& row : draw_objects)
	{
	   vector& position = *row->position;
	   texture& tex = *row->texture;
	   screen[position.y][position.x] = tex.tex;
	   //std::cout << "Drawing: " << tex.tex << " @ " << position.x << " " << position.y << std::endl;

	}

	std::string output;

	for (auto row_iter = screen.rbegin(); row_iter != screen.rend(); row_iter++)
	{
	   for (auto& entry : *row_iter)
	   {
		  output += entry;
	   }
	   output += '\n';
	}
	std::cout << output << std::flush;
}