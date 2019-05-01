#include "ConsoleStyle.h"



ConsoleStyle::ConsoleStyle(std::string name, short id, Color fg, Color bg)
{
	this->Background = bg;
	this->Foreground = fg;
	this->ID = id;
	this->name = name;

	init_pair(id, (short)fg, (short)bg);
}


ConsoleStyle::~ConsoleStyle()
{
}

Color ConsoleStyle::GetForeground()
{
	return this->Foreground;
}

Color ConsoleStyle::GetBackground()
{
	return this->Background;
}

short ConsoleStyle::GetID()
{
	return this->ID;
}

std::string ConsoleStyle::GetName()
{
	return this->name;
}
