#ifndef BOARD_H
#define BOARD_H

const char BLANK = '.';

class Board
{
public:
    static const int W = 8;  // board width
    static const int H = 8;  // board height
    Board(const char* filename);
    void print() const;
    int wipeLine(int y, int x, int cap, bool vertical = false);
    void swapRows(int r1, int r2);
    int getStars() const;
private:
    int stars;
    char cells[H][W];
    void loadFromFile(const char* filename);
};

#endif // BOARD_H
