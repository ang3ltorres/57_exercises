#include <iostream>
#include <string>
#include <format>

int main()
{
	std::string quote, author;
	
	std::cout << "What is the quote?\n--> ";
	std::getline(std::cin, quote);

	std::cout << "Who said it?\n--> ";
	std::getline(std::cin, author);

	std::cout << std::format("{} says, \"{}\".", author, quote);

	return 0;
}
