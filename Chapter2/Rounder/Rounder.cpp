#include <iostream>

int main() {
    double input;

    std::cout << "Please enter a decimal number: ";
    std::cin >> input;
    std::cout << std::endl;

    input += 0.5;
    int roundedNum = (int)input; //the rounded number

    std::cout << roundedNum;
    std::cout << std::endl;
}