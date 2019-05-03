#pragma once
#include <initializer_list>
#include <string>

#include "Colors.h"
#include "Attributes.h"



class ConsoleStyle {
public:
	ConsoleStyle(std::string name, short id, Color fg, Color bg, std::initializer_list<Attribute> attrs = std::initializer_list<Attribute>());
	ConsoleStyle() {}
	~ConsoleStyle();

	Color GetForeground();
	Color GetBackground();
	short GetID();
	std::string GetName();
	unsigned long GetAttributes();

private:
	Color Foreground;
	Color Background;
	short ID;
	std::string name;
	unsigned long Attributes = 0x00000000;

};