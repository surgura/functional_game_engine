#include <cstdint>
#include <iostream>
#include <string>
#include "components/table.hpp"
#include <thread>

struct vector
{
     std::int32_t x;
     std::int32_t y;
};

struct physics_object
{
     components::reference<vector> position;
     components::reference<vector> velocity;
};
using physics_table = components::table<physics_object>;

void physics_step(physics_table& physics_objects)
{
     for (auto& row : physics_objects)
     {
          vector& position = *row->position;
          vector& velocity = *row->velocity;

          position.x += velocity.x;
          position.y += velocity.y;
     }
}

struct texture
{
     char tex;
};

struct draw_object
{
     components::reference<vector> position;
     components::reference<texture> texture;
};
using draw_table = components::table<draw_object>;

void draw(draw_table& draw_objects)
{
     for (auto& row : draw_objects)
     {
          vector& position = *row->position;
          texture& tex = *row->texture;
          std::cout << "Drawing: " << tex.tex << " @ " << position.x << " " << position.y << std::endl;
     }
}

int main()
{
     components::table<vector> position_table;
     components::table<vector> velocity_table;
     components::table<texture> texture_table;
     physics_table physics_objects;
     draw_table draw_objects;

     // create the player
     auto position = position_table.add({ 1, 1 });
     auto velocity = velocity_table.add({ 1, 0 });
     auto texture = texture_table.add({ 'P' });

     physics_objects.add({ position, velocity });
     draw_objects.add({ position, texture });

     while(true)
     {
          physics_step(physics_objects);
          draw(draw_objects);
          std::this_thread::sleep_for(std::chrono::milliseconds(500));
     }
     return 0;
}
