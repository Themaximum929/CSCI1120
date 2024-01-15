#ifndef MASTER_H
#define MASTER_H

#include <string>
#include "Padawan.h"

using std::string;

class Master : public Padawan {
public:
    Master();
    void getInputs(string prompt, char &swap, int &r1, int &r2);
    virtual int pick(Board &board);
    void magicSwap(Board &board);
    virtual string info();
};

#endif // MASTER_H
