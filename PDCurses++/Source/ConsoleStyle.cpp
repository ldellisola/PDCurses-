#include "ConsoleStyle.h"
#include <curses.h>



//ConsoleStyle::ConsoleStyle(std::string name, short id, Color fg, Color bg)
//{
//	this->Background = bg;
//	this->Foreground = fg;
//	this->ID = id;
//	this->name = name;
//	this->Attributes = 0;
//	
//
//	init_pair(id, (short)fg, (short)bg);
//}

ConsoleStyle::ConsoleStyle(std::string name, short id, Color fg, Color bg, std::initializer_list<Attribute> attrs)
{
	this->name = name;
	this->ID = id;
	this->Foreground = fg;
	this->Background = bg;
	init_pair(id, (short)fg, (short)bg);

	for (auto att : attrs)
		Attributes |= (int32_t)att;
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

int32_t ConsoleStyle::GetAttributes()
{
	return this->Attributes;
}
