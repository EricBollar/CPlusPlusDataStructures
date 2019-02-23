#include <iostream>

int main() {
    int seconds;

    std::cout << "Enter the elapsed time for an event in seconds: ";
    std::cin >> seconds;
    std::cout << std::endl;

    int hours = seconds/(3600);
    seconds = seconds % 3600;
    int minutes = seconds/60;
    seconds = seconds % 60;

    std::cout << "Your event will last " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << std::endl;
    std::cout << "Or in other words, " << hours << ":" << minutes << ":" << seconds << std::endl;
}