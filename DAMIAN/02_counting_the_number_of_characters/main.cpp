#include <iostream>
#include <string>

int main () {
    std::string str;

    std::cout << "Enter the string: ";
    getline(std::cin,str);

    std::cout << str << " has " << str.length() << " characters";
}