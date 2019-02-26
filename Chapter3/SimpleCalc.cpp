#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string equation;

    std::cout << "Please enter your equation using only adding, subtracting, multiplying, and dividing (+ - * /):" << std::endl;
    getline(std::cin, equation);

    for (int i = 0; i < equation.length(); i++) {
        if (equation.at(i) == '*' || equation.at(i) == '/') {
            std::cout << "multiplication/division at" << i;
        }
    }
    for (int i = 0; i < equation.length(); i++) {
        if (equation.at(i) == '+' || equation.at(i) == '-') {
            std::cout << "addition/subtraction at " << i;
        }
    }
}