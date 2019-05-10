#include <cstdint>
#include <iostream>
#include <string>
#include "table.hpp"
#include <thread>

struct vector
{
     std::int32_t x;
     std::int32_t y;
};

using physics_table_t = tables::table_t<tables::row_reference_t<vector>, tables::row_reference_t<vector>>;

void physics_step(physics_table_t& physics_table)
{
     for (auto& row : physics_table)
     {
          vector& position = std::get<0>(*std::get<0>(*row));
          vector& velocity = std::get<0>(*std::get<1>(*row));

          position.x += velocity.x;
          position.y += velocity.y;
     }
}

struct texture
{
     char tex;
};

using draw_table_t = tables::table_t<tables::row_reference_t<vector>, tables::row_reference_t<texture>>;

void draw(draw_table_t& draw_table)
{
     for (auto& row : draw_table)
     {
          vector& position = std::get<0>(*std::get<0>(*row));
          texture& tex = std::get<0>(*std::get<1>(*row));
          // TODO print
          std::cout << "Drawing: " << tex.tex << " @ " << position.x << " " << position.y << std::endl;
     }
}

int main()
{
     tables::table_t<vector> position_table;
     tables::table_t<vector> velocity_table;
     tables::table_t<texture> texture_table;
     physics_table_t physics_table;
     draw_table_t draw_table;

     // create the player
     auto position = position_table.add_row({{1, 1}});
     auto velocity = velocity_table.add_row({{1, 0}});
     auto texture = texture_table.add_row({{'P'}});

     physics_table.add_row({position, velocity});
     draw_table.add_row({position, texture});

     while(true)
     {
          //std::string input;
          //std::cin >> input;
          physics_step(physics_table);
          draw(draw_table);
          std::this_thread::sleep_for(std::chrono::milliseconds(500));
     }
     return 0;
}
