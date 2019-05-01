#pragma once
#include "ConsoleStyle.h"
#include "Exceptions.h"

#include <string>

#include <vector>
#include <string>
#include <map>
#include <exception>



/*
	Cosas para implementar:

		- Scroll
		- Beep y flash
		- Atributos en los stilos
		- Mouse?
		- Window (y ver como hacemos para arreglar lo de initscr() (supongo que con singleton))
		- clipboard

	Arreglos:

		- Modularizar todo.
		- Acomodar las carpetas
*/



extern Color;

class Console
{
public:
	Console(bool useColor = true);
	~Console();

	// In cbreak mode, characters typed by the user are made available immediately, 
	// and erase / kill character processing is not performed.In nocbreak mode, 
	// typed characters are buffered until a newline or carriage return.Interruptand 
	// flow control characters are unaffected by this mode.PDCurses always starts in cbreak mode.
	void SetCBreakMode(bool value);

	// Echo control whether typed characters are echoed by the input routine. 
	// Initially, input characters are echoed.
	void SetEcho(bool value);

	// HalfDelayMode is similar to CBreak Mode, but allows for a time limit to be specified, in tenths 
	// of a second. This causes getch() to block for that period before returning ERR if no key has been received.
	void SetHalfDelay(int ms);

	// Keypad controls whether getch() returns function/special keys as single key codes (e.g., the left 
	// arrow key as KEY_LEFT). Per X/Open, the default for keypad mode is OFF. With keypad mode off, 
	// if a special key is pressed, getch() does nothing or returns ERR.
	void SetKeypad(bool value);

	// NoDelay controls whether wgetch() is a non-blocking call. If the option is enabled, and no input is ready, 
	// wgetch() will return ERR. If disabled, wgetch() will hang until input is ready.
	void SetNoDelay(bool value);

	// NoLine enables the translation of a carriage return into a newline on input. nonl() disables this. 
	// Initially, the translation does occur.
	void SetNoLine(bool value);

	// Raw mode is similar to cbreak mode, in that characters typed are immediately passed through to
	// the user program. The difference is that in raw mode, the INTR, QUIT, SUSP, and STOP characters 
	// are passed through without being interpreted, and without generating a signal.
	void SetRawMode(bool value);

	// Timeout sets blocking or non-blocking reads for the specified window. The delay is measured
	// in milliseconds. If it's negative, a blocking read is used; if zero, then non-blocking reads 
	// are done -- if no input is waiting, ERR is returned immediately. If the delay is positive, 
	// the read blocks for the delay period; if the period expires, ERR is returned.
	void setTimeout(int miliseconds);

	// Enables scrolling in a region of the Console
	void SetScroll(bool value);

	// It reads the input from the console.
	// intbufferSize: It is the maximum size of the string that the console will read
	std::string ReadLine(int bufferSize = 500);
	// It reads a single character from the console
	char ReadChar();
	// It reads the caracters from the current position of the cursor, not the input of the user
	std::string ReadFromScreen(int bufferSize = 500);
	// It reads the characters from a given position without changing the cursor position.
	std::string ReadFromScreenAT(int y, int x,int bufferSize = 500);


	// Writes a string in the current position
	void WriteLine(std::string str);
	// Writes a string in a given position without changing the position of the cursor
	void WriteLineAt(int y, int x, std::string str);
	// Moves the cursos to a given position and writes a string
	void WriteLineAndMoveCursor(int y, int x, std::string str);

	// Writes a char in the current position
	void WriteChar(char c);
	// Writes a char in a given position without changing the position of the cursor
	void WriteCharAt(int y, int x, char c);
	// Moves the cursor to a given position and writes a char
	void WriteCharAndMoveCursor(int y, int x, char c); 

	// It defines a region of the console as scrollable.
	void DefineScrollableRegion(int top, int bottom);
	// It scrolls N lines. If N > 0 it scrolls up. if N < 0 it scrolls down.
	void Scroll(int n = 1);


	bool HasKey(int key);
	std::string KeyName(int key);

	// It creates an style that can be applied to any text written on the console (fore/background only)
	// Color Foreground: Color of the text
	// Color Background: Color of the terminal in that place.
	// std::string Name: Identifier to use the style afterwards.
	void CreateStyle(Color Foreground, Color Background, std::string Name);

	// It sets an already created style to the console.
	void SetStyle(std::string Name);

	// It clears the Console
	void Clear();
	// It Clears the contents of a single line
	void ClearLine(int y);
	// It clears everything thats after a given position
	void ClearFrom(int y, int x);

	// It deletes a given line without changing the cursor position
	void DeleteLine(int y);
	// It deletes the current line without changing the cursor position
	void DeleteCurrentLine();
	// It inserts a line in a given position without changing the cursor position
	void InsertLine(int y);

	// It moves the cursor
	void MoveCursor(int x, int y);
	// It retrieves the position of the cursor
	void GetCursorPosition(int &x, int &y);


private:
	WINDOW* window = nullptr;
	std::map<std::string, ConsoleStyle> styles;
	short StyleCount = 1;
};

