#pragma once
//#include <curses.h>
#include "Colors.h"
//C:\Dev\C++\PDCurses++\PDCurses++\Vendor\PDCurses\Headers
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