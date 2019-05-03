#include "Configuration.h"
#include <curses.h>

Configuration::Configuration(WINDOW* window)
{
	this->window = window;
}

void Configuration::SetCBreakMode(bool value)
{
	value ? cbreak() : nocbreak();
}

void Configuration::SetEcho(bool value)
{
	value ? echo() : noecho();
}

void Configuration::SetHalfDelay(int ms)
{
	halfdelay(ms);
}

void Configuration::SetKeypad(bool value)
{
	keypad(this->window, value);
}

void Configuration::SetNoDelay(bool value)
{
	nodelay(this->window, value);
}

void Configuration::SetNoLine(bool value)
{
	value ? nl() : nonl();
}

void Configuration::SetRawMode(bool value)
{
	value ? raw() : noraw();
}

void Configuration::setTimeout(int miliseconds)
{
	wtimeout(this->window, miliseconds);
}

void Configuration::SetScroll(bool value)
{
	scrollok(this->window, value);
}