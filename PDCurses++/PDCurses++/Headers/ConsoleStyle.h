#pragma once
#include "Colors.h"
#include <vector>
#include <string>
#include <map>
#include <exception>

class ConsoleStyle {
public:
	ConsoleStyle(std::string name,short id, Color fg, Color bg);
	ConsoleStyle() {}
	~ConsoleStyle();

	Color GetForeground();
	Color GetBackground();
	short GetID();
	std::string GetName();

private:
	Color Foreground;
	Color Background;
	short ID;
	std::string name;

};