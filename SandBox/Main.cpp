
#include <Console.h>

// Save your Clipboard
int main(void) {
	Console console;
	console.configuration->StartColor();
	console.configuration->SetEcho(false);
	console.configuration->SetKeypad(true);

	console.CreateStyle(Color::Black, Color::Green, "green");
	console.CreateStyle(Color::Black, Color::Red, "red");

	console.WriteLine("Hey, let's test this thing!");
	console.WriteLineAt(2, 0, "Instruction:");
	console.WriteLineAt(3, 20, "- You just have to copy the phrase: \"Hello World\" to the clipboard.");
	console.WriteLineAt(4, 20, "- Press Enter to leave.");
	console.WriteLineAt(6, 0, "Your phrase is:");

	do {
		std::string value = console.clipboard->Get();

		console.DeleteLine(7);

		if (value == "Hello World")
			console.SetStyle("green");
		else
			console.SetStyle("red");

		console.WriteLineAt(7, 15, value);



	} while (console.ReadKeyCode() != KeyCode::Enter);





}