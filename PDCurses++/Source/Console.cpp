
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
	halfdelay(ms);
}

void Console::SetKeypad(bool value)
{
	keypad((WINDOW*)this->window, value);
}

void Console::SetNoDelay(bool value)
{
	nodelay((WINDOW*)this->window, value);
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
	wtimeout((WINDOW*)this->window, miliseconds);
}

void Console::SetScroll(bool value)
{
	scrollok((WINDOW*)this->window, value);
}

std::string Console::ReadLine(int bufferSize)
{
	char* temp = new char[bufferSize];

	wgetnstr((WINDOW*)this->window, temp, bufferSize);

	std::string retValue = std::string((const char*)temp);

	delete[] temp;
	return retValue;
}

char Console::ReadChar()
{
	return (char)wgetch((WINDOW*)this->window);
}

std::string Console::ReadFromScreen(int bufferSize)
{
	
	char* temp = new char[bufferSize];
	winnstr((WINDOW*)this->window, temp, bufferSize);

	std::string retValue = std::string((const char*)temp);
	delete[]temp;

	return retValue;
}

std::string Console::ReadFromScreenAT(int y, int x, int bufferSize)
{
	char* temp = new char[bufferSize];
	int prevX, prevY;

	GetCursorPosition(prevX, prevY);
	mvwinnstr((WINDOW*)this->window, y,x,temp, bufferSize);

	std::string retValue = std::string((const char*)temp);
	delete[]temp;
	MoveCursor(prevX, prevY);
	return retValue;
}

void Console::Write(std::string str)
{
	printw((str).c_str());
	wrefresh((WINDOW*)this->window);
}

void Console::WriteLine(std::string str)
{
	printw((str+"\n").c_str());
	wrefresh((WINDOW*)this->window);
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
	mvwprintw((WINDOW*)this->window, y, x, str.c_str());
	wrefresh((WINDOW*)this->window);
}

void Console::WriteChar(char c)
{
	wprintw((WINDOW*)this->window, "%c", c);
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
	mvwprintw((WINDOW*)this->window, x, y, "%c", c);
}

void Console::DefineScrollableRegion(int top, int bottom)
{
	wsetscrreg((WINDOW*)this->window, top, bottom);
}

void Console::Scroll(int n)
{
	wscrl((WINDOW*)this->window, n);
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
	THROWIF(wcolor_set((WINDOW*)this->window, this->styles.at(Name).GetID(), nullptr) != OK);
	attr_t prevAttr;
	short temp;
	wattr_get((WINDOW*)this->window, &prevAttr, &temp, nullptr);
	wattr_off((WINDOW*)this->window, prevAttr, nullptr);
	wattr_on((WINDOW*)this->window, this->styles.at(Name).GetAttributes(), nullptr);
}

void Console::Clear()
{
	THROWIF(wclear((WINDOW*)this->window) != OK)	
}

void Console::ClearLine(int y)
{
	MoveCursor(0, y);
	THROWIF(wclrtoeol((WINDOW*)this->window) != OK)
}

void Console::ClearFrom(int y, int x)
{
	MoveCursor(x, y);
	wclrtobot((WINDOW*)this->window);
}

void Console::DeleteLine(int y)
{
	int prevX, PrevY;
	GetCursorPosition(prevX, PrevY);
	mvwdeleteln((WINDOW*)this->window, y, 0);
	MoveCursor(prevX, PrevY);
}

void Console::DeleteCurrentLine()
{
	wdeleteln((WINDOW*)this->window);
}

void Console::InsertLine(int y)
{
	int prevX, prevY;
	GetCursorPosition(prevX, prevY);
	mvwinsertln((WINDOW*)this->window, y, 0);
	MoveCursor(prevX, prevY);
}

void Console::MoveCursor(int x, int y)
{
	THROWIF(wmove((WINDOW*)this->window, y, x) != OK)
}

void Console::GetCursorPosition(int& x, int& y)
{
	getyx((WINDOW*)this->window, y, x);
}

void Console::Beep()
{
	beep();
}

void Console::Flash()
{
	flash();
}

std::string Console::GetClipboard()
{
	char* temp = nullptr;
	long size;
	PDC_getclipboard(&temp, &size);

	std::string retValue = std::string((const char*)temp);
	PDC_freeclipboard(temp);
	return retValue;
}

void Console::SetClipboard(std::string str)
{
	PDC_setclipboard(str.c_str(), str.length());
}

void Console::ClearClipboard()
{
	PDC_clearclipboard();
}


