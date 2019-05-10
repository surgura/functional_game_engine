#include <cstdint>
#include "table.hpp"

struct vector
{
     std::int32_t x;
     std::int32_t y;
};

tables::table<vector> position_table;
tables::table<vector> velocity_table;
using physics_table_t = tables::table<tables::row_reference<vector>, tables::row_reference<vector>>;
physics_table_t physics_table;

void physics_step(physics_table_t& physics)
{
     for (auto& row : physics)
     {
          std::get<0>(*std::get<0>(row)).x += std::get<0>(*std::get<1>(row)).x;
          std::get<0>(*std::get<0>(row)).y += std::get<0>(*std::get<1>(row)).y;
     }
}

int main()
{
     return 0;
}
