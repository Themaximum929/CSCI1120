#ifndef STARPICKER_H
#define STARPICKER_H

#include <string>
#include "Board.h"

using std::string;

/* An abstract base class representing a game player */
class StarPicker {
public:
    StarPicker();
    string getTeam();
    void setTeam(string t);
    bool getInt(int &z);
    virtual int pick(Board &board) = 0;
    virtual string info();
private:
    string team;
};

#endif // STARPICKER_H
