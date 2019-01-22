#include <iostream>
#include <string>

int main() {
	std::string origPrice;
	std::cout << "Enter the price of the item in the format: ##.##" << std::endl;
	std::getline(std::cin, origPrice);

	std::string paidAmount;
	std::cout << "Enter the amount of money paid in the format: ##.##" << std::endl;
	std::getline(std::cin, paidAmount);

	double orig = std::stof(origPrice);
	double paid = std::stof(paidAmount);

	double change = paid - orig;

	if (change < 0) {
		std::cout << "The customer has not paid enough money for this item." << std::endl;
		system("PAUSE");
		return 0;
	}

	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int pennies = 0;

	double i = change;
	while (i > 0.0f) {
		if (i > 0.25) {
			quarters++;
			i -= 0.25;
		}
		else if (i > 0.1) {
			dimes++;
			i -= 0.1;
		}
		else if (i > 0.05) {
			nickels++;
			i -= 0.05;
		}
		else {
			pennies++;
			i -= 0.01;
		}
	}
	pennies -= 1; // because floating number is greater than 0 like 0.0000001 so an extra penny will be added

	std::cout << "You owe $" << change << " to the customer." << std::endl;
	std::cout << "Give them " << quarters << " quarters." << std::endl;
	std::cout << "Give them " << dimes << " dimes." << std::endl;
	std::cout << "Give them " << nickels << " nickels." << std::endl;
	std::cout << "Give them " << pennies << " pennies." << std::endl;
	system("PAUSE");
}