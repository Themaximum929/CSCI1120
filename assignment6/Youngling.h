#ifndef YOUNGLING_H
#define YOUNGLING_H

#include <string>
#include "StarPicker.h"

using std::string;

class Youngling : public StarPicker {
public:
    Youngling();
    Youngling(int ms);
    int getMaxStars(); 
    void setMaxStars(int ms);
    void getInputs(string prompt, int &y, int &x);
    virtual int pick(Board &board);
    virtual string info();
private:
    int maxStars;
};

#endif // YOUNGLING_H
