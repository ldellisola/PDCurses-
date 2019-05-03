
#include <Console.h>
#include <Attributes.h>


int main(void) {
	Console console(true);
	console.CreateStyle(Color::White, Color::Black, "basic", {Attribute::Standout});
	
	while (true)
		console.ReadLine();
	console.ReadChar();

}