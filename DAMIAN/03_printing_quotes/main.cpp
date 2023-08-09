#include <iostream>
#include <string>

int main () {
    std::string quote,author;

    std::cout << "What is the cuote?: ";
    getline(std::cin,quote);

    std::cout << "Who said it?: ";
    getline(std::cin,author);

    std::cout << author << " says: " << "\"" + quote + "\"";

    return 0;
}