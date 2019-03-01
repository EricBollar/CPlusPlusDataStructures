#include <iostream>
#include <string>
#include <cmath>
#include <vector>

const std::string digits = "0123456789"; // 0-9

bool isDigit(char c) {
    for (int i = 0; i < digits.length(); i++) {
        if (c == digits.at(i)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string equation; // variables
    std::vector<int> numbers; // all integers in equation, in order
    std::vector<char> symbols; // all symbols (+-*/) in equation, in order
    int solution; // solution that will be outputed

    //receive equation input
    std::cout << "Please enter your equation using only adding, subtracting, multiplying, and dividing (+ - * /):" << std::endl;
    getline(std::cin, equation);

    // fills up symbols with all the symbols of equation in order, left -> right
    for (int i = 0; i < equation.length(); i++) { //finds all multiplication/division/addition/subtraction symbols left -> right
        if (equation.at(i) == '*') {
            symbols.push_back('*');
            std::cout << '*' << std::endl;
        }
        if (equation.at(i) == '/') {
            symbols.push_back('/');
            std::cout << '/' << std::endl;
        }
        if (equation.at(i) == '+') {
            symbols.push_back('+');
            std::cout << '+' << std::endl;
        }
        if (equation.at(i) == '-') {
            symbols.push_back('-');
            std::cout << '-' << std::endl;
        }
    }
 
    std::string currNum = ""; // this for loop adds all of the numbers into the numbers vector in order from left -> right
    for (int i = 0; i < equation.length(); i++) {
        if (isDigit(equation.at(i))) {
            currNum += equation.at(i);
            if (i == equation.length() - 1) {
                std::cout << currNum << std::endl;
                numbers.push_back(atoi(currNum.c_str()));
                currNum = "";
            }
        } else if (currNum != "") {
            std::cout << currNum << std::endl;
            numbers.push_back(atoi(currNum.c_str()));
            currNum = "";
        } else {
            currNum = "";
        }
    }
}