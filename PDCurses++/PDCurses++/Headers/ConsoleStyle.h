#pragma once
#include "Colors.h"
#include "Attributes.h"
#include <vector>
#include <string>
#include <map>
#include <exception>
#include <cstdint>
#include <initializer_list>

class ConsoleStyle {
public:
	//ConsoleStyle(std::string name,short id, Color fg, Color bg);
	ConsoleStyle(std::string name, short id, Color fg, Color bg, std::initializer_list<Attribute> attrs = std::initializer_list<Attribute>());
	ConsoleStyle() {}
	~ConsoleStyle();

	Color GetForeground();
	Color GetBackground();
	short GetID();
	std::string GetName();
	int32_t GetAttributes();

private:
	Color Foreground;
	Color Background;
	short ID;
	std::string name;
	int32_t Attributes = 0x00000000;

};