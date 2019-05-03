#pragma once


typedef struct _win WINDOW;


class Configuration {
	
public:

	Configuration(WINDOW* window);


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
private:
	WINDOW* window = nullptr;
};