#include "stringcoin.h"
#include <iostream>
#include <string>
using namespace std;

/* Returns true if position pos of the game network still has a string (not cut
   yet); returns false otherwise (that is, string was already cut). */
bool stringState(long long network, int pos) {
    // TO DO; add a return statement in order to compile
    long long div = network;
    for (int c = pos-2; c < 17; c++) {
        div /= 10;
    }
    if (div % 10 == 1) {
        return true; 
    }
    else {
        return false;
    }
}

/* Prints the network to the screen. Do NOT modify! Do NOT use any arrays
   outside this function! */
void printNetwork(long long network) {
    int i;
    string s[18];    // Do NOT use any arrays outside this function!

    for (i = 1; i <= 17; i++)
        if (i <= 3 || i >= 15 || (i >= 8 && i <= 10))
            s[i] = stringState(network, i) ? "|" : " ";
        else
            s[i] = stringState(network, i) ? "--" : "  ";

    cout << "*************\n";
    for (i = 1; i <= 17; i += 7) {
        cout << "*  " << s[i] << "  " << s[i + 1] << "  " << s[i + 2]
            << "  *\n";
        if (i < 15)
            cout << "*" << s[i + 3] << "$" << s[i + 4] << "$" << s[i + 5]
            << "$" << s[i + 6] << "*\n";
    }
    cout << "*************\n";
    cout << "Player 1 score: " << network / 10 % 10 << endl;
    cout << "Player 2 score: " << network % 10 << endl;
}

/* Returns the score of Player p in network. (Either the 18th or 19th digit in
   network.) */
int playerScore(long long network, int p) {
    // TO DO; add a return statement in order to compile
    if (p == 2) {
        return (network % 10);
    }
    else {
        return ((network / 10) % 10);
    }
}

/* Performs the task of Player p cutting a string in position pos of network.
   The reference parameter network should get updated, and if any coins are
   disconnected, the score of Player p shall be incremented, to reflect the new
   network configuration. */
void updateNetwork(long long& network, int pos, int p) {
    // Change the digit from 1 to 0;
    long long sub = 1;
    for (int c = pos - 2; c < 17; c++) {
        sub *= 10;
    }
    network -= sub;

    // Check any coins disconnected
    int up = 1, l_side = 4, r_side = 5, down = 8;
    for (int c = 0; c < 6; c++) {
        // If pos == string, check the coin
        if (up == pos || l_side == pos || r_side == pos || down == pos)
        {
            // Add score if 4 side does not have string  
            if (!(stringState(network, up)) && !(stringState(network, l_side)) && !(stringState(network, r_side)) && !(stringState(network, down))) {
                if (p == 1) {
                    network += 10;
                }
                else {
                    network += 1;
                }
            }
        }        
        // +5 to check the coin next line, +1 to check adjacent coin
        if (c == 2) {
            up += 5, l_side += 5, r_side += 5, down += 5;
        }
        else {
            up += 1, l_side += 1, r_side += 1, down += 1;
        }

    }

}
