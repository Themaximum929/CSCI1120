#include <iostream>
#include <random>

int main() {
	// Initialization
	int price[16] = {0, 1000, 2000, 3000, 4000, 8000, 10000, 20000, 30000, 40000, 60000, 80000, 150000, 250000, 500000, 1000000 };
	char op_set[] = "+-*/";

	// Initialize random generator
	int seed, two_num[2] = { 0 }, question[4] = { 0 }, lifetime = 999, correct = 1, c = 1;
	std::cout << "Enter seed: ";
	std::cin >> seed;

	std::mt19937 gen(seed);
	std::uniform_int_distribution<> generate_num(1, 100);
	std::uniform_int_distribution<> op_gen(0, 3);


	// Question loop
	for (c ; c < 16; c++) {
		if (c == 5 || c == 10) { std::cout << "Question " << c << " ($" << price[c] << "#):" << std::endl; }
		else { std::cout << "Question " << c << " ($" << price[c] << "):" << std::endl; }

		// Generate random numbers for question
		for (int x = 0; x < 2; x++) two_num[x] = generate_num(gen);
		int op = op_gen(gen), s;
		switch (op) {
		case 0: { s = two_num[0] + two_num[1]; break; }
		case 1: { s = two_num[0] - two_num[1]; break; }
		case 2: { s = two_num[0] * two_num[1]; break; }
		case 3: { s = two_num[0] / two_num[1]; break; }
		}
		std::cout << two_num[0] << " " << op_set[op] << " " << two_num[1] << " = ?" << std::endl;

		// Random generate 4 numbers and change random 1 into the solution, new gen if generate num = correct answer
		int insert = 0;
		while (insert != 4) {
			int gened = generate_num(gen);
			if (gened != s) {
				question[insert] = gened;
			}
			insert++;
		}
		question[op_gen(gen)] = s;

		if (lifetime == 999 && c != 15) { std::cout << "A. " << question[0] << "  B. " << question[1] << "  C. " << question[2] << "  D. " << question[3] << "  E. Jump  F. Withdraw" << std::endl; }
		else { std::cout << "A. " << question[0] << "  B. " << question[1] << "  C. " << question[2] << "  D. " << question[3] << "  F. Withdraw" << std::endl; }

		// Answer questions
		char answer;
		std::cout << "Final answer: ";
		std::cin >> answer;

		switch (answer) {
		case 'e': {
			lifetime = c;	
			break; 
		}
		case 'f': {
			break; 
		}
		default:
			if (question[(int)answer - 97] != s) {
				correct = 0;
				break;
			}
		}
		// End situation
		if (answer == 'f' && lifetime == 999) {
			std::cout << "Game over!\nYou got $" << price[c - 1] << "!";
			break;
		}
		else if (answer == 'f') {
			std::cout << "Game over!\nYou got $" << price[c - 2] << "!";
			break;
		}
		else if ((correct == 0 && c <= 5) || (correct == 0 && lifetime == 5 && c == 6)) {
			std::cout << "Game over!\nYou got $0!";
			break;
		}
		else if ((correct == 0 && c <= 10) || (correct == 0 && lifetime == 10 && c == 11)) {
			std::cout << "Game over!\nYou got $" << price[5] << "!";
			break;
		}
		else if (correct == 0) {
			std::cout << "Game over!\nYou got $" << price[10] << "!";
			break;
		}
		else if (lifetime != c) std::cout << "Right!" << std::endl;
	}
	if (c == 16)	
		std::cout << "Game over!\nYou got $1000000!\nCongrats! You are a millionare!";

	return 0;
}
