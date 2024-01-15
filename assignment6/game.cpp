#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
#include "Master.h"

using namespace std;

int runRound(Board &board, vector<StarPicker*> &team) {
    // TODO: Add your code here
}

int main() {
    string filename;
    cout << "Enter board file name: ";
    getline(cin, filename);
    Board board(filename.c_str());

    Youngling y1, y2;
    Padawan p1, p2;
    Master m1, m2;
    
    vector<StarPicker*> jedi { &y1, &p1, &m1 }; 
    vector<StarPicker*> sith { &y2, &p2, &m2 };

    for (int i = 0; i < int(jedi.size()); i++)
         jedi[i]->setTeam("Jedi");

    for (int i = 0; i < int(sith.size()); i++)
         sith[i]->setTeam("Sith");

    int rounds, jediScore = 0, sithScore = 0;
    cout << "How many rounds to play? ";
    cin >> rounds;

    cout << "Initial board:" << endl;
    board.print();
    for (int i = 1; i <= rounds; i++) {
        if (board.getStars() <= 0)
            break;
        cout << "Round " << i << ":" << endl;
        if (i % 2 ==0)
            jediScore += runRound(board, jedi);
        else
            sithScore += runRound(board, sith);
        cout << "Score: Jedi " << jediScore << " vs. Sith " << sithScore << endl;
    } 

    cout << "Game Over!" << endl;
    if (jediScore > sithScore) 
        cout << "Jedi wins!";
    else 
    if (jediScore < sithScore) 
        cout << "Sith wins!";
    else 
        cout << "Game draws!";

    return 0;
}
