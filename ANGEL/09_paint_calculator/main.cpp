#include <iostream>
#include <format>
#include <limits>

int main()
{
	const auto getInt = [](const std::string& text = "") -> int
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
			else return t;
		}
	};

	const auto getGallons = [](const int& h, const int& w) -> int
	{
		static const int conversionRate = 350;
		return ((w*h) / conversionRate) + 1;
	};

	int length = getInt("What is the length of the room in feet? ");
	int width = getInt("What is the width of the room in feet? ");
	int gallons = getGallons(length, width);

	std::cout << std::format(
		"\nYou will need to purchase {} gallons of\n"
		"paint to cover {} square feet.",
		gallons, length * width
	);

	return 0;
}
