#include "Clipboard.h"
#include <curses.h>

std::string Clipboard::Get()
{
	char* temp = nullptr;
	long size;
	PDC_getclipboard(&temp, &size);

	std::string retValue = std::string((const char*)temp);
	PDC_freeclipboard(temp);
	return retValue;
}

void Clipboard::Set(std::string str)
{
	PDC_setclipboard(str.c_str(), str.length());
}

void Clipboard::Clear()
{
	PDC_clearclipboard();
}