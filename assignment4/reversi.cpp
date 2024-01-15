// Comment: sorry for not optimizing the programme because of too rush but it could run all the testcases, thank you for all the tutors and lecturers effort to make the testcases.

#include <iostream>
#include <iomanip>
#include <limits>
#include "reversi.h"

/* You may include more headers here if necessary. */

using namespace std;

bool flip_func(char board[][N], char p, int y, int x, bool check) {
    bool moved = false;
    // left
    int c = x - 1;
    bool re = false;
    if(!(board[y][c] == p))
    { 
        while (c != x + 1) {
            if (c == -1) break;
            else if (board[y][c] == '#' || (board[y][c] == '.' && re == false)) break;
            else if (board[y][c] == p && c != x - 1 && check == true) {
                return true;
            }
            else if (board[y][c] == p || re == true) {
                board[y][c] = p;
                re = true;
                moved = true;
                c++;
            }
            else c--;
        }
    }
    //up
    c = y - 1;
    re = false;
    if(!(board[c][x] == p))
    { 
        while (c != y + 1) {
            if (c == -1) break;
            else if (board[c][x] == '#' || (board[c][x] == '.' && re == false)) break;
            else if (board[c][x] == p && c != y - 1 && check == true) {
                return true;
            }
            else if (board[c][x] == p || re == true) {
                board[c][x] = p;
                re = true;
                moved = true;
                c++;
            }

            else c--;
        }
    }
    // right
    c = x + 1;
    re = false;
    if(!(board[y][c] == p))
    { 
        while (c != x - 1) {
            if (c == N) break;
            else if (board[y][c] == '#' || (board[y][c] == '.' && re == false)) break;
            else if (board[y][c] == p && c != x + 1 && check == true) {
                return true;
            }
            else if (board[y][c] == p || re == true) {
                board[y][c] = p;
                re = true;
                moved = true;
                c--;
            }
            else c++;
        }
    }
    // down 
    c = y + 1;
    re = false;
    if (!(board[c][x] == p))
    {
        while (c != y - 1) {
            if (c == N) break;
            else if (board[c][x] == '#' || (board[c][x] == '.' && re == false)) break;
            else if (board[c][x] == p && c != y + 1 && check == true) {
                return true;
            }
            else if (board[c][x] == p || re == true) {
                board[c][x] = p;
                re = true;
                moved = true;
                c--;
            }
            else c++;
        }
    }
    // upleft
    int yy = y - 1;
    int xx = x - 1;
    re = false;
    if (!(board[yy][xx] == p)) {
        while (yy != y + 1) {
            if (yy == -1 || xx == -1) break;
            else if (board[yy][xx] == '#' || (board[yy][xx] == '.' && re == false)) break;
            else if (board[yy][xx] == p && yy != y - 1 && xx != x - 1 && check == true) {
                return true;
            }
            else if (board[yy][xx] == p || re == true) {
                board[yy][xx] = p;
                re = true;
                moved = true;
                yy++;
                xx++;
            }
            else {
                yy--;
                xx--;
            }
        }
    }

    // downleft
    yy = y + 1;
    xx = x - 1;
    re = false;
    if (!(board[yy][xx] == p)) {
        while (yy != y - 1) {
            if (yy == N || xx == -1) break;
            else if (board[yy][xx] == '#' || (board[yy][xx] == '.' && re == false)) break;
            else if (board[yy][xx] == p && yy != y + 1 && xx != x - 1 && check == true) {
                return true;
            }
            else if (board[yy][xx] == p || re == true) {
                board[yy][xx] = p;
                re = true;
                moved = true;
                yy--;
                xx++;
            }
            else {
                yy++;
                xx--;
            }
        }
    }
    // upright 
    yy = y - 1;
    xx = x + 1;
    re = false;
    if (!(board[yy][xx] == p)) {
        while (yy != y + 1) {
            if (yy == -1 || xx == N) break;
            else if (board[yy][xx] == '#' || (board[yy][xx] == '.' && re == false)) break;
            else if (board[yy][xx] == p && yy != y - 1 && xx != x + 1 && check == true) {
                return true;
            }
            else if (board[yy][xx] == p || re == true) {
                board[yy][xx] = p;
                re = true;
                moved = true;
                yy++;
                xx--;
            }
            else {
                yy--;
                xx++;
            }
        }
    }
    // downright
    yy = y + 1;
    xx = x + 1;
    re = false;
    if (!(board[yy][xx] == p)) {
        while (yy != y - 1) {
            if (yy == N || xx == N) break;
            else if (board[yy][xx] == '#' || (board[yy][xx] == '.' && re == false)) break;
            else if (board[yy][xx] == p && yy != y + 1 && xx != x + 1 && check == true) {
                return true;
            }
            else if (board[yy][xx] == p || re == true) {
                board[yy][xx] = p;
                re = true;
                moved = true;
                yy--;
                xx--;
            }
            else {
                yy++;
                xx++;
            }
        }
    }
    if (moved == false && check == false) board[y][x] = p;
    if (check == true) return false;
    return true;
}

// Return true if console input fails (e.g., the user enters alphabets while 
// an integer is expected.) or false otherwise
// This function bypasses any weird input by skipping to the next newline  
bool cin_failed() {
    bool failed = cin.fail();
    if (failed) {
        cin.clear();  // clear the error flag on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skip to next newline
    }
    return failed;
}

// Print the game board
void print_board(char board[][N]) {
    cout << "  ";
    for (int i = 0; i < N; i++)
        cout << setw(2) << char('A' + i);
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << setw(2) << i + 1 << ' ';
        for (int j = 0; j < N; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}

// Return true if the move by player p at cell (y, x) is valid, or false otherwise 
// If flip is passed as true, the move is made on the board
bool valid_move(char board[][N], char p, int y, int x, bool flip) {
    //check move is valid
    if (y >= N || x >= N) return false;
    if (board[y][x] != '.') return false;
    else if (flip == false && p == 'B') {
        board[y][x] = '#';
        return true;
    }
    else if (!flip_func(board, p, y, x, true)) return false;
    else if (flip == false) return true;
    // Carry move
    flip_func(board, p, y, x, false);
    return true;
}

// Return true if player p still has valid move(s) on the board, or false otherwise
bool has_valid_moves(char board[][N], char p) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {      
            if (board[y][x] == '.' && flip_func(board, p, y, x, true)) {
                return true; 
            }
        }
    }
    return false;
}

// Return true if the game board still has empty cell(s), or false otherwise
bool has_empty_cells(char board[][N]) {
    bool empty = false;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (board[y][x] == '.') {
                empty = true;
            }
        }
    }
    return empty;
}

