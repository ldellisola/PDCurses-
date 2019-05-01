#include <Console.h>
#include<Attributes.h>


int main(void) {
	Console console(true);
	console.CreateStyle(Color::White, Color::Black, "basic", { Attribute::AlteranteCharSet });


	console.SetStyle("basic");
	
	console.WriteLine("TEst");


	console.ReadChar();

}