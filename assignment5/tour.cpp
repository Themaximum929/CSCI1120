#include <iostream>
#include "TwinKnightsTour.h"

void main() {
	//Starting positions
	int r1, r2, c1, c2;
	while (true) {
		std::cout << "Knights' starting positions (row1 col1 row2 col2): ";
		std::cin >> r1 >> c1 >> r2 >> c2;
		if (r1 >= TwinKnightsTour::N || r2 >= TwinKnightsTour::N || c1 >= TwinKnightsTour::N || c2 >= TwinKnightsTour::N
			|| r1 < 0 || r2 < 0 || c1 < 0 || c2 < 0 || (c1 == c2 && r1 == r2)) {
			std::cout << "Invalid position(s)!" << std::endl;
		}
		else break;
	}
	// Create object
	TwinKnightsTour knight(r1, c1, r2, c2);
	
	char k;
	int r, c;
	while (true) {
		knight.print();

		while (true) {
			std::cout << "Move (knight row col): ";
			std::cin >> k >> r >> c;
			if (knight.move(k, r, c)) break;
			else std::cout << "Invalid move!" << std::endl;
		}
		if (!knight.hasMoreMoves()) {
			knight.print();
			std::cout << "No more moves!" << std::endl;
			break;
		}
	}
}
