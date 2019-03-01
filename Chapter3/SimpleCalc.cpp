#include <iostream>
#include <string>
#include <cmath>
#include <vector>

const std::string digits = "0123456789"; // 0-9

bool isDigit(char c) { // returns whether a char is a digit or not
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
    int solution = 0; // solution that will be outputed

    // receive equation input as one string
    std::cout << "Please enter your equation using only adding, subtracting, multiplying, and dividing (+ - * /):" << std::endl;
    getline(std::cin, equation);

    // fills up symbols with all the symbols of equation in order, left -> right
    // e.g. the equation "4 + 2 * 6 / 3",
    // the symbols vector would be [+, *, /]
    for (int i = 0; i < equation.length(); i++) { //finds all multiplication/division/addition/subtraction symbols left -> right
        if (equation.at(i) == '*') {
            symbols.push_back('*');
        }
        if (equation.at(i) == '/') {
            symbols.push_back('/');
        }
        if (equation.at(i) == '+') {
            symbols.push_back('+');
        }
        if (equation.at(i) == '-') {
            symbols.push_back('-');
        }
    }
 
    std::string currNum = ""; // this for loop adds all of the numbers into the numbers vector in order from left -> right
    for (int i = 0; i < equation.length(); i++) {
        if (isDigit(equation.at(i))) {
            currNum += equation.at(i);
            if (i == equation.length() - 1) {
                numbers.push_back(atoi(currNum.c_str())); //adds the current number to numbers(vector)
                currNum = "";
            }
        } else if (currNum != "") {
            numbers.push_back(atoi(currNum.c_str())); //adds the current number to numbers(vector)
            currNum = "";
        } else {
            currNum = "";
        }
    }

    // now for solving the problem...
    for (int i = 0; i < symbols.size(); i++) {
        int curr = 0;
        if (symbols.at(i) == '*') {
            curr = numbers.at(i) * numbers.at(i + 1);
            numbers.erase(numbers.begin() + i);
            numbers.erase(numbers.begin() + i);
            numbers.insert(numbers.begin() + i, curr);
            symbols.erase(symbols.begin() + i);
            i--; // needs to go back one iteration to make up for lost symbol
        }else if (symbols.at(i) == '/') {
            curr = numbers.at(i) / numbers.at(i + 1);
            numbers.erase(numbers.begin() + i);
            numbers.erase(numbers.begin() + i);
            numbers.insert(numbers.begin() + i, curr);
            symbols.erase(symbols.begin() + i);
            i--;
        }
    }

    solution = numbers.at(0);
    for (int i = 0; i < symbols.size(); i++) {
        if (symbols.at(i) == '+') {
            solution += numbers.at(i + 1);
        } else if (symbols.at(i) == '-') {
            solution -= numbers.at(i + 1);
        }
    }

    std::cout << "= " << solution << std::endl;
}