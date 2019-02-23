#include <iostream>
#include <math.h>

// This program outputs the force between two bodies using Newton's equation of: F = k((M1*M2)/D^2)

int main () {
    double mass1; // the three variables
    double mass2;
    double distance;
    float k = 0.0000000667;

    std::cout << "Please enter the mass of the first object: "; // all the inputs
    std::cin >> mass1;
    std::cout << std::endl;
    std::cout << "Please enter the mass of the second object: ";
    std::cin >> mass2;
    std::cout << std::endl;
    std::cout << "Please enter the distance between the two objects: ";
    std::cin >> distance;
    std::cout << std::endl;

    double force = k * ( (mass1*mass2) / pow(distance, 2) );

    std::cout << "The force between the two objects is: " << force << " Newtons";
    std::cout << std::endl;
}