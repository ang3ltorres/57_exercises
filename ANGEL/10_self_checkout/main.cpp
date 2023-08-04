#include <iostream>
#include <format>
#include <limits>
#include <array>
#include <tuple>

struct Item
{
	Item() = default;

	Item(const int& amount, const float& price)
	: amount(amount), price(price) {}

	int amount;
	float price;
};

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

template <std::size_t SIZE> std::tuple<float, float, float> calc(const std::array<Item, SIZE>& item)
{
	static const float taxRate = 0.055f;

	float subtotal = 0;

	for (auto& i : item)
		subtotal += (i.amount * i.price);

	return std::tuple<float, float, float>{subtotal, taxRate * subtotal, subtotal + (taxRate * subtotal)};
}

int main()
{

	const auto getItem = [&]() -> Item {
		return Item(getNumber<int>("Enter the amount: "), getNumber<float>("Enter the price: $"));
	};

	std::array<Item, 3> items;
	for (std::size_t i = 0; i < items.size(); i++) {

		std::cout << std::format("--- Enter item {:02} ---\n", i+1);
		items[i] = getItem();
		std::cout << std::endl;
	}

	auto c = calc(items);
	std::cout << std::format(
		"Subtotal: ${:.03f}\n"
		"Tax: ${:.03f}\n"
		"Total: ${:.03f}",
		std::get<0>(c), std::get<1>(c), std::get<2>(c));

	return 0;
}