#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string equation;

    std::cout << "Please enter your equation using only adding, subtracting, multiplying, and dividing (+ - * /):" << std::endl;
    getline(std::cin, equation);

    std::cout << equation;
}