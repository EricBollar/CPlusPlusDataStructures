#include <iostream>

int main() {
	int testScore1; //I am not using an array because the example said to specifically do this
	int testScore2;
	int testScore3;
	int testScore4;

	int testWeight1;
	int testWeight2;
	int testWeight3;
	int testWeight4;

	std::cout << "This program will output the average of 4 weighted test scores." << std::endl;
	
	std::cout << "What is the score for test #1? (Enter the percentage as an integer)" << std::endl;
	std::cin >> testScore1;
	std::cout << "What is the weight of test #1? (Enter the weight percentage as an integer)" << std::endl;
	std::cin >> testWeight1;

	std::cout << "What is the score for test #2? (Enter the percentage as an integer)" << std::endl;
	std::cin >> testScore2;
	std::cout << "What is the weight of test #2? (Enter the weight percentage as an integer)" << std::endl;
	std::cin >> testWeight2;
	
	std::cout << "What is the score for test #3? (Enter the percentage as an integer)" << std::endl;
	std::cin >> testScore3;
	std::cout << "What is the weight of test #3? (Enter the weight percentage as an integer)" << std::endl;
	std::cin >> testWeight3;
	
	std::cout << "What is the score for test #4? (Enter the percentage as an integer)" << std::endl;
	std::cin >> testScore4;
	std::cout << "What is the weight of test #4? (Enter the weight percentage as an integer)" << std::endl;
	std::cin >> testWeight4;
	
	if (testWeight1 + testWeight2 + testWeight3 + testWeight4 != 100) {
		std::cout << "The 4 weights you entered do not add up to 100%. Please rerun the program and try again." << std::endl;
		system("PAUSE");
	}
	else {
		double avg = (testScore1 * testWeight1) + (testScore2 * testWeight2) + (testScore3 * testWeight3) + (testScore4 * testWeight4);
		std::cout << "The weighted average of these four tests is: " << avg * 0.01 << "%" << std::endl;
		system("PAUSE");
	}
}