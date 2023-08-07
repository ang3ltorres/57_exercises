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
		if (std::cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }
		else return n;
	}
}

int main()
{
	float euros = getNumber<float>("How many euros are you exchanging? ");
	float exchangeRate = getNumber<float>("What is the exchange rate? ");

	std::cout << std::format(
		"{} euros at an exchange rate of {} is\n"
		"${:.2f} U.S. dollars.\n",
		euros, exchangeRate, euros * exchangeRate);

	return 0;
}