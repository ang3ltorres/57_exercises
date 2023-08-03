#include <iostream>
#include <format>
#include <functional>
#include <limits>

int main()
{
	const std::function<int(const std::string&)> getIntByInput = [](const std::string& text = "") -> int
	{
		int t;

		while (true)
		{
			if (text != "")
				std::cout << text;

			std::cin >> t;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				return t;
		}
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
