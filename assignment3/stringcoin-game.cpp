// Name:       Chan Chun Ming	
// Student ID: 1155163257	
// Email:      1155163257@link.cuhk.edu.hk

#include "stringcoin.h"
#include <iostream>
#include <string>

void main() {
	long long network = 1111111111111111100;
	int player = 1, position = 0;

	// Print network
	printNetwork(network);

	while (1) {
		// player 1 and 2 original score
		int p1S = playerScore(network, 1);
		int p2S = playerScore(network, 2);

		

		// While loop for check input validity
		while (1) {
			std::cout << "Player " << player << "'s move (1-17): ";
			std::cin >> position;
			//std::cout << (stringState(network, position)) << " " << (position > 0 && position < 18) << std::endl;
			if (stringState(network, position) && (position > 0 && position < 18)) { 
				break;
			}
			else {
				std::cout << "Invalid. Try again!" << std::endl;
			}
		}	
		// Update network
		updateNetwork(network, position, player);		

		
		// Switch player and print extra turn if their point change
		if (player == 1 && p1S == playerScore(network, 1)) {
			player = 2;
		}
		else if (player == 2 && p2S == playerScore(network, 2)) {
			player = 1;
		}
		else if ((p1S != playerScore(network, 1) || p2S != playerScore(network, 2)) && network / 100 != 0) {
			std::cout << "Player " << player << " scores! Get extra turn." << std::endl; 
		}

		// Print network
		printNetwork(network);

		// Determine winner
		if (network / 100 == 0) {
			if (network % 10 > ((network / 10) % 10)) {
				std::cout << "Player 2 wins!";
			}
			else if (network % 10 < ((network / 10) % 10)) {
				std::cout << "Player 1 wins!";
			}
			else {
				std::cout << "Draw game!";
			}
			break;
		}
	}
}