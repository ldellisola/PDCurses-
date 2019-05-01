#pragma once

#include <vector>
#include <string>
#include <map>
#include <exception>



enum class Color
{
	Black = 0 /*COLOR_BLACK*/,
	Blue = 1 /*COLOR_BLUE*/,
	Green = 2 /*COLOR_GREEN*/,
	Cyan = (Green |Blue)/*COLOR_CYAN*/,
	Red = 4/* COLOR_RED*/,
	Magenta =(Red|Blue) /*COLOR_MAGENTA*/,
	Yellow = (Red|Green) /*COLOR_YELLOW*/,
	White = 7 /*COLOR_WHITE*/
};