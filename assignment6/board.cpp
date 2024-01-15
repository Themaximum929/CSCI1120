#include <iostream>
#include <fstream>
#include "Board.h"

using namespace std;

Board::Board(const char* filename) : stars(H * W),
    cells {
        'A','B','B','B','B','B','B','B',
        'A','C','C','C','C','D','D','D',
        'A','E','E','E','B','E','C','B',
        'A','B','E','B','B','E','C','B',
        'A','B','E','D','D','E','C','B',
        'A','C','E','F','F','E','F','B',
        'A','D','A','B','B','E','C','B',
        'A','C','A','B','B','D','C','B'
    }
{
    if (filename[0] != '\0')
        loadFromFile(filename);
}

void Board::loadFromFile(const char* filename) {
    // TODO: Add your code here
}

// print the game board on the screen
void Board::print() const {
    cout << " ";
    for (int i = 0; i < W; i++)
        cout << " " << i;
    cout << endl;
    for (int i = 0; i < H; i++) {
        cout << i;
        for (int j = 0; j < W; j++) {
            cout << " " << cells[i][j];
        }
        cout << endl;
    }   
}

int Board::wipeLine(int y, int x, int cap, bool vertical) {
    // TODO: Add your code here
}

void Board::swapRows(int r1, int r2) {
    // TODO: Add your code here
}

int Board::getStars() const {
    return stars;
}

