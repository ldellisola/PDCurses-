#include <Console.h>



int main(void) {
	Console console(true);
	console.CreateStyle(Color::White, Color::Black, "basic");
	console.CreateStyle(Color::Green, Color::Black, "hacker");
	console.CreateStyle(Color::Black, Color::White, "inverted");

	console.SetStyle("basic");
	
	console.Beep();

	console.WriteLine("sep");


}