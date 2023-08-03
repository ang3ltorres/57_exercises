#include <iostream>
#include <string>
#include <format>
#include <chrono>

int main()
{
	const auto now = std::chrono::system_clock::now();
	const std::time_t tc = std::chrono::system_clock::to_time_t(now);
	tm time = *(std::localtime(&tc));

	unsigned int year = time.tm_year + 1900;

	const auto getIntByInput = [](const std::string& text) -> int
	{
		std::string t;
		std::cout << text;
		std::getline(std::cin, t);
		return std::stoi(t);
	};

	int age = getIntByInput("What is your current age? ");
	int ageToRetire = getIntByInput("At what age would you like to retire? ");
	std::cout << std::format("You have {} years left until you can retire.\nIt's {}, so you can retire in {}.", ageToRetire - age, year, year + (ageToRetire - age));

	return 0;
}
