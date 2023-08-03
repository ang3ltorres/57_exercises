#include <iostream>
#include <string>

int main()
{
	std::string string;
	
	std::cout << "What is the input string?\n--> ";
	std::getline(std::cin, string);

	std::cout << string << " has " << string.length() << " characters.";

	return 0;
}
