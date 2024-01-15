/*
* Name: Chan Chun Ming
* SID: 1155163257
* Email: 1155163257@link.cuhk.edu.hk
*/

#include <iostream>
#include "TwinKnightsTour.h"

TwinKnightsTour::TwinKnightsTour(int r1, int c1, int r2, int c2)
{
	// Initialize board
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (y == r1 && x == c1) board[y][x] = "A";
			else if (y == r2 && x == c2) board[y][x] = "a";
			else board[y][x] = ".";
		}
	}
	// Initialize variable
	posR1 = r1;
	posC1 = c1;
	posR2 = r2;
	posC2 = c2;
	steps1 = 0;
	steps2 = 0;
	consec1 = 0; 
	consec2 = 0;
}

void TwinKnightsTour::print() const
{
	// First row
	for (int x = 0; x < N; x++) {
		if (x == 0) std::cout << "    " << x;
		else if (x < 10) std::cout << "  " << x;
		else std::cout << " " << x;
	}
	std::cout << std::endl;
	// Other row
	for (int y = 0; y < N; y++) {
		if (y < 10) std::cout << " " << y;
		else std::cout << y;
		for (int x = 0; x < N; x++) {
			if (y == posR1 && x == posC1) std::cout << "  " << "@";
			else if (y == posR2 && x == posC2) std::cout << "  " << "#";
			else if (board[y][x].length() == 1) std::cout << "  " << board[y][x];
			else std::cout << " " << board[y][x];
		}
		std::cout << std::endl;
	}
}

bool TwinKnightsTour::isValid(char knight, int r, int c) const
{
	// Proper position
	if (r < 0 || r >= N || c < 0 || c >= N) return false;
	// Unvisited square
	if (board[r][c] != ".") return false;
	// Consec moves
	if ((consec1 == 2 && knight == '@') || (consec2 == 2 && knight == '#')) return false;
	// Lshape
	if (knight == '@') {
		if (((r - posR1 == 1 || r - posR1 == -1) && (c - posC1 == 2 || c - posC1 == -2))
			|| ((r - posR1 == 2 || r - posR1 == -2) && (c - posC1 == 1 || c - posC1 == -1))) return true;
	}
	if (knight == '#') {
		if (((r - posR2 == 1 || r - posR2 == -1) && (c - posC2 == 2 || c - posC2 == -2))
			|| ((r - posR2 == 2 || r - posR2 == -2) && (c - posC2 == 1 || c - posC2 == -1))) return true;
	}
	return false;
}

bool TwinKnightsTour::hasMoreMoves() const
{
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (isValid('@', y, x)) return true;
			if (isValid('#', y, x)) return true;
		}
	}
	return false;
}

bool TwinKnightsTour::move(char knight, int r, int c)
{
	if (!isValid(knight, r, c)) return false;
	//Update position
	if (knight == '@') {
		steps1++;
		string content = "";
		if (steps1 / 26 != 0) content += (char)steps1 / 26 + 64;	
		content += (char) steps1 % 26 + 65;
		board[r][c] = content;
		posR1 = r;
		posC1 = c;
		consec1++;
		consec2 = 0;
	}
	if (knight == '#') {
		steps2++;
		string content = "";
		if (steps2 / 26 != 0) content += (char)steps2 / 26 + 96;
		content += (char)steps2 % 26 + 97;
		board[r][c] = content;
		posR2 = r;
		posC2 = c;		
		consec2++;
		consec1 = 0;
	}
	return true;
}
