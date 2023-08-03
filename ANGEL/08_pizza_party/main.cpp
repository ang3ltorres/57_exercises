#include <iostream>
#include <format>
#include <functional>

int main()
{
	const std::function<int(const std::string&)> getIntByInput = [](const std::string& text = "") -> int
	{
		std::string t;
		if (text != "")
			std::cout << text;

		std::getline(std::cin, t);
		return std::stoi(t);
	};

	int people = getIntByInput("How many people? ");
	int pizzas = getIntByInput("How many pizzas do you have? ");
	int slices = getIntByInput("How many slices per pizza? ");

	int totalSlices = slices * pizzas;
	
	std::cout << std::format
	(
		"\n{} people with {} pizzas.\n"
		"Each person gets {} {} of pizza.\n"
		"There are {} leftover pieces.",
		people, pizzas, totalSlices / people, (totalSlices / people > 1) ? "pieces" : "piece", totalSlices % people
	);

	return 0;
}
