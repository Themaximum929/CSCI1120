// Name:       Chan Chun Ming   
// Student ID: 1155163257
// Email:      maxchan929@gmail.com

#include <iostream>
#include <string.h>
#include <string>
#include "reversi.h"

/* You may include more headers here if necessary. */


// TODO: Write your main function here
void main() {
	// Enter block cells
	int block = 0;
	while (1) {
		std::cout << "Enter number of blocks: ";
		std::cin >> block;
		if (block >= 0 && block <= ((N * N) / 2)) break;
		else std::cout << "Too many blocks!" << std::endl;
	}
	// Initialize array
	char board[N][N] = {};
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			board[y][x] = '.';
		}
	}
	board[N / 2 - 1][N / 2 - 1] = 'X';
	board[N / 2][N / 2] = 'X';
	board[N / 2][N / 2 - 1] = 'O';
	board[N / 2 - 1][N / 2] = 'O';
	

	// Input block position
	std::string position;
	for (int c = 1; c < block+1; c++) {
		while (1) {
			std::cout << "Enter position for block " << c << ": ";
			std::cin >> position;
			std::string temp;
			for (int cc = 1; cc < position.size(); cc++) {
				temp += position[cc];
			}
			int y_axis = std::stoi(temp)-1;
			int x_axis;
			if ((int)position[0] >= 65 && (int)position[0] <= 90) x_axis = (int)position[0] - 65;
			else x_axis = (int)position[0] - 97;

			if (cin_failed() || !valid_move(board, 'B', y_axis, x_axis, false)) {
				std::cout << "Invalid position!" << std::endl;
			}
			else break;
		}
	}

	std::string invalid = "00";
	// Start game
	char player = 'X';
	for (int c = 1;; c++) {
		std::cout << "Round " << c << ":" << std::endl;
		print_board(board);
		
		// Check any valid moves
		if (!has_valid_moves(board, player)) {
			std::cout << "Player " << player << " has no valid moves! Pass!" << std::endl;
			if (player == 'X') {
				invalid[0] = '1';
			}
			else {
				invalid[1] = '1';
			}
		}
		else
		{
			// Check basic input validity
			while (1) {
				std::cout << "Player " << player << "'s turn: ";
				std::cin >> position;
				std::string temp;
				for (int cc = 1; cc < position.size(); cc++) {
					temp += position[cc];
				}
				int y_axis = std::stoi(temp)-1;
				int x_axis;
				if ((int)position[0] >= 65 && (int)position[0] <= 90) x_axis = (int)position[0] - 65;
				else x_axis = (int)position[0] - 97;

				if (cin_failed() || !valid_move(board, player, y_axis, x_axis, false)) {
					std::cout << "Invalid move!" << std::endl;
				}
				else {
					valid_move(board, player, y_axis, x_axis, true);
					break;
				}
			}
		}
		// check end game
		if (!has_empty_cells(board) || invalid == "11") {
			std::cout << "Game over:" << std::endl;
			print_board(board);
			int p1 = 0, p2 = 0;
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					if (board[y][x] == 'X') p1++;
					if (board[y][x] == 'O') p2++;
				}
			}
			if (p1 > p2) std::cout << "Player X wins!";
			else if (p1 < p2) std::cout << "Player O wins!";
			else std::cout << "Draw game!";
			break;
		}

		// switch player
		if (player == 'X') {
			player = 'O';
			invalid[1] = '0';
		}
		else {
			player = 'X';
			invalid[0] = '0';
		}		
	}
}