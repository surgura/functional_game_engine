#pragma once

#include "types.hpp"

template <typename value_type>
struct vector
{
	value_type x;
	value_type y;
};

using vectoru32 = vector<u32>;
using vectorf32 = vector<f32>;