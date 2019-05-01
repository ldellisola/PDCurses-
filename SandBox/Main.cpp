#include <Console.h>



int main(void) {
	Console console(true);
	console.CreateStyle(Color::White, Color::Black, "basic");
	console.CreateStyle(Color::Green, Color::Black, "hacker");
	console.CreateStyle(Color::Black, Color::White, "inverted");

	console.SetStyle("basic");
	console.WriteLine("puta");

	console.SetStyle("hacker");
	console.WriteLineAt(1, 0, "Puta Linea 2");

	console.SetStyle("inverted");
	console.WriteLine(" Despues de Puta");

	console.SetStyle("basic");
	console.WriteLineAndMoveCursor(2, 10, "lejos de todo");
	console.WriteLine(".Continua");

	console.MoveCursor(0, 0);

	console.ClearLine(1);

	console.ClearFrom(2, 20);
	int x, y;
	console.GetCursorPosition(x, y);

	
	console.WriteCharAndMoveCursor(10, 0, 'B');
	console.WriteCharAt(8, 12, 'C');
	console.WriteChar('A');

}