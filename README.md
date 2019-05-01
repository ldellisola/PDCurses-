# PDCurses++

PDCurses++ is a simple C++ wrapper for the C library [PDCurses](https://github.com/wmcbrine/PDCurses).

## Functions

Everything is documented on the headers, so there is little reason to make some propper docs.

One important thing to note is that currently you can only have **ONE** instance of the console, as we call initscrn() in the constructor and endwin() in the desctructor. So if you create 2 instances of the console, when you destroy one instance, it will break everything on the other one.

Anyway, this wrapper supports:

- Scrolling.
- Reading from the user's input.
- Reading from the Console.
- Writing to the Console.
- All Console options in PDCurses (Keypad,CBreak,Echo,...)
- Get cursor position and change it.
- Create font styles (using colors and attributes).
- Clipboard support.
- Some Miscelanius functions (Beep and Flash)
