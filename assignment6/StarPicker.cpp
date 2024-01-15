#include <iostream>
#include <string>
#include "StarPicker.h"

using namespace std;

StarPicker::StarPicker() {
}

string StarPicker::getTeam() {
    return team;
}

void StarPicker::setTeam(string t) {
    team = t; 
}

string StarPicker::info() {
    return getTeam();
};

bool StarPicker::getInt(int &z) {
    cin >> z;
    if (!cin.good()) {
        cin.clear();
        string tmp;
        getline(cin, tmp);  // clear the buffer
        cout << "Invalid input: " << tmp << endl;
        return false;
    }
    return true;
}
