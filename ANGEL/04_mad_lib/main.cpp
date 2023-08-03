#include <iostream>
#include <string>
#include <format>
#include <random>

int main()
{
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(0, 3);

	int sentence = distribution(generator);

	std::string noun, verb, adjective, adverb;
	
	std::cout << "Enter a noun --> "; std::getline(std::cin, noun);
	std::cout << "Enter a verb --> "; std::getline(std::cin, verb);
	std::cout << "Enter a adjective --> "; std::getline(std::cin, adjective);
	std::cout << "Enter a adverb --> "; std::getline(std::cin, adverb);

	switch (sentence)
	{
		case 0:
			std::cout << std::format("Do you {} your {} {} {}? That's hilarious!", verb, adjective, noun, adverb);
			break;

		case 1:
			std::cout << std::format("{} {} your {} {} today? That sounds interesting!", adverb, verb, adjective, noun);
			break;

		case 2:
			std::cout << std::format("That {} {} my {} {} really {}.", adverb, verb, adjective, noun, adverb);
			break;

		case 3:
			std::cout << std::format("Wow, I can't believe you {} such a {} {} {}!", verb, adjective, noun, adverb);
			break;
	}

	return 0;
}
