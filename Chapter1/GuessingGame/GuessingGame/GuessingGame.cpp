#include <iostream>
#include <time.h>

int main () {
	srand(time(NULL));
	int num = rand() % 101;
	int playerGuess;
	bool stop = false;

	while (stop == false) {
		std::cout << "I have picked a number between 0 and 100! What is your guess:" << std::endl;
		std::cin >> playerGuess;

		if (playerGuess == num) {
			std::cout << "Your guess was correct!" << std::endl;
			std::cout << "The number was: " << num << std::endl;
			system("PAUSE");
			stop = true;
		}
		else if (playerGuess > num) {
			std::cout << "Your guess is higher than the number. Guess again!" << std::endl;
		}
		else if (playerGuess < num) {
			std::cout << "Your guess is lower than the number. Guess again!" << std::endl;
		}
	}
}