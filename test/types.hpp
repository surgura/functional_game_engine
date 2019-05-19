#pragma once

#include <cstdint>

// unsigned integers
using u64 = uint64_t;
using u32 = uint32_t;
using u16 = uint16_t;
using u8 = uint8_t;

constexpr u64 operator "" _u64(unsigned long long val)
{
	return (u64)val;
}

constexpr u32 operator "" _u32(unsigned long long val)
{
	return (u32)val;
}

constexpr u16 operator "" _u16(unsigned long long val)
{
	return (u16)val;
}

constexpr u8 operator "" _u8(unsigned long long val)
{
	return (u8)val;
}

// floating point
using f32 = float;
using f64 = double;

constexpr f32 operator "" _f32(long double val)
{
	return (f32)val;
}

constexpr f64 operator "" _f64(long double val)
{
	return (f64)val;
}

// signed integers
using s64 = int64_t;
using s32 = int32_t;
using s16 = int16_t;
using s8 = int8_t;

// characters
using c8 = char;

// byte
using byte = u8;