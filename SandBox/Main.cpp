#include <Console.h>
#include<Attributes.h>


int main(void) {
	Console console(true);
	console.SetScroll(true);
	console.CreateStyle(Color::White, Color::Black, "basic", {Attribute::Standout});
	console.DefineScrollableRegion(0, 50);

	console.SetStyle("basic");
	
	console.WriteLine("HOALALAALALALA");

	console.ReadChar();

}