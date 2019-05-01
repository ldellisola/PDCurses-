//#include "pch.h"

#include "Console.h"
#include <curses.h>

Console::Console(bool useColor)
{
	window = initscr();

	THROWIF(window == nullptr)

	if(useColor)
		THROWIF(start_color() != OK)
}


Console::~Console()
{
	endwin();
}

void Console::SetCBreakMode(bool value)
{
	value ? cbreak() : nocbreak();
}

void Console::SetEcho(bool value)
{
	value ? echo() : noecho();
}

void Console::SetHalfDelay(int ms)
{
	halfdelay(ms)
}

void Console::SetKeypad(bool value)
{
	keypad(this->window, value);
}

void Console::SetNoDelay(bool value)
{
	nodelay(this->window, value);
}

void Console::SetNoLine(bool value)
{
	value ? nl() : nonl();
}

void Console::SetRawMode(bool value)
{
	value ? raw() : noraw();
}

void Console::setTimeout(int miliseconds)
{
	wtimeout(this->window,miliseconds)
}

void Console::SetScroll(bool value)
{
	scrollok(this->window, value);
}

std::string Console::ReadLine(int bufferSize)
{
	char* temp = new char[bufferSize];

	wgetnstr(this->window, temp, bufferSize);

	std::string retValue = std::string((const char*)temp);

	delete[] temp;
	return retValue;
}

char Console::ReadChar()
{
	return (char)wgetch(this->window);
}

std::string Console::ReadFromScreen(int bufferSize)
{
	
	char* temp = new char[bufferSize];
	winnstr(this->window, temp, bufferSize);

	std::string retValue = std::string((const char*)temp);
	delete[]temp;

	return retValue;
}

std::string Console::ReadFromScreenAT(int y, int x, int bufferSize)
{
	char* temp = new char[bufferSize];
	int prevX, prevY;

	GetCursorPosition(prevX, prevY);
	mvwinnstr(this->window, y,x,temp, bufferSize);

	std::string retValue = std::string((const char*)temp);
	delete[]temp;
	MoveCursor(prevX, prevY);
	return retValue;
}

void Console::WriteLine(std::string str)
{
	printw(str.c_str());
	wrefresh(this->window);
}

void Console::WriteLineAt(int y, int x, std::string str)
{
	int prevX, prevY;
	GetCursorPosition(prevX, prevY);

	WriteLineAndMoveCursor(y, x, str);

	MoveCursor(prevX, prevY);
}

void Console::WriteLineAndMoveCursor(int y, int x, std::string str)
{
	mvwprintw(this->window, y, x, str.c_str());
	wrefresh(this->window);
}

void Console::WriteChar(char c)
{
	wprintw(this->window, "%c", c);
}

void Console::WriteCharAt(int y, int x, char c)
{
	int prevX , prevY;
	GetCursorPosition(prevX, prevY);

	WriteCharAndMoveCursor(y, x, c);

	MoveCursor(prevX, prevY);
}

void Console::WriteCharAndMoveCursor(int y, int x, char c)
{
	mvwprintw(this->window, x, y, "%c", c);
}

void Console::DefineScrollableRegion(int top, int bottom)
{
	wsetscrreg(this->window, top, bottom);
}

void Console::Scroll(int n)
{
	wscrl(this->window, n);
}

bool Console::HasKey(int key)
{
	return has_key(key);
}

std::string Console::KeyName(int key)
{
	return std::string(keyname(key));
}

void Console::CreateStyle(Color Foreground, Color Background, std::string Name)
{
	this->styles[Name] = ConsoleStyle(Name, StyleCount++, Foreground, Background);
}

void Console::SetStyle(std::string Name)
{
	THROWIF(wcolor_set(this->window, this->styles.at(Name).GetID(), nullptr) != OK)
}

void Console::Clear()
{
	THROWIF(wclear(this->window) != OK)	
}

void Console::ClearLine(int y)
{
	MoveCursor(0, y);
	THROWIF(wclrtoeol(this->window) != OK)
}

void Console::ClearFrom(int y, int x)
{
	MoveCursor(x, y);
	wclrtobot(this->window);
}

void Console::DeleteLine(int y)
{
	int prevX, PrevY;
	GetCursorPosition(prevX, PrevY);
	mvwdeleteln(this->window, y, 0);
	MoveCursor(prevX, PrevY);
}

void Console::DeleteCurrentLine()
{
	wdeleteln(this->window);
}

void Console::InsertLine(int y)
{
	int prevX, prevY;
	GetCursorPosition(prevX, prevY);
	mvwinsertln(this->window, y, 0);
	MoveCursor(prevX, prevY);
}

void Console::MoveCursor(int x, int y)
{
	THROWIF(wmove(this->window, y, x) != OK)
}

void Console::GetCursorPosition(int& x, int& y)
{
	getyx(this->window, y, x);
}


