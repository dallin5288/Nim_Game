/*
*File: Nim.cpp
*Course: CS215 - 014x
*Project: Project 2
*Purpose:  Defines the implementation of the Nim class
*          declared in the Nim.h header file
*
* It represents the legal move when it is the computer's turn to play
* The computer takes “smart strategy” trying to win the game:
* (1)if the current pile size is not a Power-of-Two-minus-One, it takes
* off enough marbles to make the remaining a Power-of-Two-minus-One;
* (2)otherwise, it randomly takes at least one but at most half
* (Note that the private data member, pileSize, will be modified)
* @return: void function
*
* Author: (Dallin Liu)
 */

#include "Nim.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

Nim::Nim()
{
    pileSize = 0;
}

Nim::Nim(int iniSize)
{
    pileSize = iniSize;
}

void Nim::setPileSize(int size)
{
    pileSize = size;
}

int Nim::getPileSize() const
{
    return pileSize;
}

void Nim::computer_play()
{
    // Check if pile size is a Power-of-Two-minus-One
    int power = log2(pileSize + 1);     // Solves for power
    int limit = pow(2, power) - 1;      // Obtains the value of limit with corresponding power

    if (pileSize != limit) {
        // Take enough marbles to make pile size a Power-of-Two-minus-One
        int take = pileSize - limit;
        cout << "The computer takes " << take << " marbles.\n";
        pileSize = limit;
    }
    else {
        // Randomly take at least one but at most half of the remaining marbles
        srand(time(NULL));
        int take = rand() % (pileSize / 2) + 1;
        cout << "The computer takes " << take << " marbles.\n";
        pileSize -= take;
    }
}

void Nim::player_play()
{
    int take;

    // Do while loop for player to input the number of marbles to take
    do {
        cout << "Your turn to play ... you may take 1 to " << pileSize / 2 << " marbles\nYou take: ";
        cin >> take;
        if (cin.fail()) {
            // Input was not an integer, clear the error
            cin.clear();
            cout << "Invalid! Please try again...\n";
        }
        // Check if the number is within the range 
        else if (take < 1 || take > pileSize / 2) {
            cout << "Ooops, you picked too many or not enough.\nPlease try again..." << endl;
        }
        cin.ignore(256, '\n'); // Ignore the input

    } while (take < 1 || take > pileSize / 2);

    pileSize -= take; // Subtract from pile size

    cout << "You will take " << take << " marbles.\n";
}

void Nim::print() const
{
    // Prints out the current number of marbles in the pile 
    cout << endl << "There are " << pileSize << " marbles in the pile.\n";
    for (int i = 0; i < pileSize; i++) {
        cout << "\t" << MARBLE << "\n";
    }
}


