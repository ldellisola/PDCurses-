#include "Console.h"

#include "Clipboard.h"
#include "Configuration.h"
#include "ConsoleStyle.h"
#include <curses.h>

Console::Console()
{
	window = initscr();
	configuration = new Configuration(this->window);
	this->clipboard = new Clipboard();

	THROWIF(window == nullptr)
}


Console::~Console()
{
	delete configuration;
	delete clipboard;
	endwin();
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
	 return wgetch(this->window);
}

KeyCode Console::ReadKeyCode()
{
	return (KeyCode)wgetch(this->window);
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

void Console::Write(std::string str)
{
	printw((str).c_str());
	wrefresh(this->window);
}

void Console::WriteLine(std::string str)
{
	printw((str+"\n").c_str());
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

void Console::CreateStyle(Color Foreground, Color Background, std::string Name, std::initializer_list<Attribute> attrs)
{
	this->styles[Name] = ConsoleStyle(Name, StyleCount++, Foreground, Background,attrs);
}

void Console::SetStyle(std::string Name)
{
	THROWIF(wcolor_set(this->window, this->styles.at(Name).GetID(), nullptr) != OK);
	attr_t prevAttr;
	short temp;
	wattr_get(this->window, &prevAttr, &temp, nullptr);
	wattr_off(this->window, prevAttr, nullptr);
	wattr_on(this->window, this->styles.at(Name).GetAttributes(), nullptr);
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

void Console::Beep()
{
	beep();
}

void Console::Flash()
{
	flash();
}




