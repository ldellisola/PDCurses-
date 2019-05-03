#pragma once
#include <initializer_list>
#include <string>
#include <map>


#include "Attributes.h"
#include "Colors.h"
#include "KeyCodes.h"
#include "Exceptions.h"
#include "Configuration.h"
#include "Clipboard.h"



// Foward Delaration
typedef struct _win WINDOW;
class ConsoleStyle;

class Console
{
public:
	Console();
	~Console();


	Configuration* configuration;
	Clipboard* clipboard;


	// It reads the input from the console.
	// intbufferSize: It is the maximum size of the string that the console will read
	std::string ReadLine(int bufferSize = 500);
	// It reads a single character from the console
	char ReadChar();
	// It reads a single Keycode from the console
	KeyCode ReadKeyCode();
	// It reads the caracters from the current position of the cursor, not the input of the user
	std::string ReadFromScreen(int bufferSize = 500);
	// It reads the characters from a given position without changing the cursor position.
	std::string ReadFromScreenAT(int y, int x,int bufferSize = 500);

	// Writes a string in the current position of the cursor
	void Write(std::string str);
	// Writes a string in the current line and moves the cursor to the next
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

	// It returns true if your keyboard has taht key.
	bool HasKey(int key);
	// It returns the name of the key.
	std::string KeyName(int key);


	// It creates an style that can be applied to any text written on the console (fore/background only)
	// Color Foreground: Color of the text
	// Color Background: Color of the terminal in that place.
	// std::string Name: Identifier to use the style afterwards.
	void CreateStyle(Color Foreground, Color Background, std::string Name, std::initializer_list<Attribute> attrs = std::initializer_list<Attribute>());

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

	// The console makes a beeping sound (or it will flash if it can't beep)
	void Beep();
	// The lines written in the console will invert their foreground and background colors for an instant
	void Flash();


	


	

private:
	WINDOW * window = nullptr;
	std::map<std::string, ConsoleStyle> styles;
	short StyleCount = 1;
};

