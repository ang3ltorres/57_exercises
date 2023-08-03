#include <iostream>
#include <string>
#include <format>

int main()
{
	const auto getFloatByInput = [](const std::string& text) -> float
	{
		std::string t;
		std::cout << text;
		std::getline(std::cin, t);
		return std::stof(t);
	};

	const auto feetToMeters = [=](const float squareFeet) -> float
	{
		static const float conversionFactor = 0.09290304;
		return squareFeet * conversionFactor;
	};

	float h = getFloatByInput("What is the length of the room in feet? ");
	float w = getFloatByInput("What is the width of the room in feet? ");

	float areaFeet = h * w;
	float areaMeters = feetToMeters(areaFeet);

	std::cout << std::format("You entered dimensions of {} feet by {} feet.\nThe area is\n{:.3f} square feet\n{:.3f} square meters", h, w, areaFeet, areaMeters);

	return 0;
}
