#include <iostream>
#include <string>
#include <format>

int main()
{
	std::string snumber1, snumber2;
	std::cout << "What is the first number? "; std::getline(std::cin, snumber1);
	std::cout << "What is the second number? "; std::getline(std::cin, snumber2);

	int n1 = std::stoi(snumber1);
	int n2 = std::stoi(snumber2);

	std::cout << std::format("{} + {} = {}\n", n1, n2, n1 + n2);
	std::cout << std::format("{} - {} = {}\n", n1, n2, n1 - n2);
	std::cout << std::format("{} * {} = {}\n", n1, n2, n1 * n2);
	std::cout << std::format("{} / {} = {}\n", n1, n2, n1 / n2);

	return 0;
}