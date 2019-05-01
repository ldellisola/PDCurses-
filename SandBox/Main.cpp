#include <Console.h>
#include<Attributes.h>


int main(void) {
	Console console(true);
	console.SetScroll(true);
	console.CreateStyle(Color::White, Color::Black, "basic");
	console.DefineScrollableRegion(0, 50);

	console.SetStyle("basic");
	
	for (int i = 0; i < 50; i++)
		console.WriteLine("Test\n");

	for (int i = 0; i < 10; i++)
		console.Scroll(-1);
	for (int i = 0; i < 10; i++)
		console.Scroll(1);

	console.ReadChar();

}