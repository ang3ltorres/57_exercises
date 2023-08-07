#include <iostream>
#include <format>
#include <limits>

template <typename T> T getNumber(const std::string& text = "")
{
	T n;
	while (true)
	{
		if (text != "") std::cout << text;
		std::cin >> n;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else return n;
	}
}

int main()
{
	float p = getNumber<float>("Enter the principal: ");
	float r = getNumber<float>("Enter the rate of interest: ");
	float t = getNumber<float>("Enter the number of years: ");

	const auto simpleInterest = [](float p, float r, float t) -> float { return p*(1+((r/100)*t)); };
	
	std::cout << std::format("\nAfter {} years at {}%, the investment will\nbe worth ${:.02f}.", t, r, simpleInterest(p, r, t));

	return 0;
}
