#ifndef PADAWAN_H
#define PADAWAN_H

#include <string>
#include "Youngling.h"

using std::string;

class Padawan : public Youngling {
public:
    Padawan();
    Padawan(int ms);
    void getInputs(string prompt, int &y, int &x, char &dir);
    virtual int pick(Board &board);
    virtual string info();
};

#endif // PADAWAN_H
