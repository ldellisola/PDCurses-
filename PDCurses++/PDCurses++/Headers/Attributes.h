#pragma once

#include <cstdint>

enum class Attribute : int32_t
{
	AlteranteCharSet = 0x0001000,
	Blink = 0x00400000,
	Bold = 0x00800000,
	Italic = 0x00080000,
	Left = 0x00040000,
	Reverse = 0x00200000,
	Right = 0x00020000,
	Standout = (Reverse | Bold),
	Underline = 0x00100000

	
};