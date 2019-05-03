#pragma once
#include <string>

class Clipboard {

	// It returns the content of the clipboard
	std::string Get();
	// It sets the contents of the clipboard
	void Set(std::string str);
	// It clears the clipboard
	void Clear();
};