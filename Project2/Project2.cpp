/*
 * Course: CS215 - 014x
 * Project: Project 2
 * Purpose: It demonstrates the game of Nim played between two computer players
 *          In combinatorial game theory, a two-player deterministic perfect information turn-based game
 *          is a first-player-win if with perfect play the first player to move can always force a win.
 *          This program also shows that the game of Nim is a "CONDITIONAL first-player-win" game using two computer players.
 * Author: Dallin Liu
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include "Nim.h"

using namespace std;

int main()
{
    int seed = static_cast<int>(time(0));
    srand(seed);

    // Generate the initial size of pile (of marbles)
    // at the range of [PILE_MIN, PILE_MAX]
    // for testing purpose only: we set the initial size of pile to a constant PILE_SIZE_TEST
     int pileSize = PILE_SIZE_TEST;

    // comment out the testing purpose at line number 27, enable the following statement, which is the general case
    //int pileSize = PILE_MIN + rand() % (PILE_MAX - PILE_MIN + 1);

    // create a Nim object with initial pile size = pileSize
    Nim NimGame(pileSize);

    string name;
    cout << "Welcome to the game of Nim (for two players)" << endl;
    cout << "Please input your name: ";
    getline(cin, name);    
    cout << endl;

    cout << "*******************************************************" << endl;
    cout << "*                   The game of Nim                   *" << endl;
    cout << "*   Players alternate taking at least one but at      *" << endl;
    cout << "*   most half of the marbles in the pile.             *" << endl;
    cout << "*   The player who takes the last marble loses.       *" << endl;
    cout << "*   It is written by Dallin Liu                       *" << endl;
    cout << "*   I hope you beat the computer : )                  *" << endl;
    cout << "*   No matter what, have a great day!                 *" << endl;
    cout << "*******************************************************" << endl << endl;

    // Generate a random number to decide who goes first
    int firstPlayer = rand() % 2;

    // Display the message of who goes first followed by who goes second
    if (firstPlayer == 0) 
    {
        // Computer's turn
        cout << "The computer will play first." << endl;
        cout << "Then followed by " << name << "." << endl << endl;
    }
    else
    {
        // Player's turn
        cout << name << " will play first." << endl;
        cout << "Then followed by the Computer." << endl << endl;
    }

    // Loop until the game is over
    while (NimGame.getPileSize() > 1) 
    {
        NimGame.print();
        if (firstPlayer == 0) //it is computer's turn to play
        {
            // Computer's turn
            cout << "It is Computer's turn: " << endl;
            NimGame.computer_play();
            // Switch to player's turn
            firstPlayer = 1;
        }
        else // it is player's turn to play
        {
            // Player's turn
            cout << "It is " << name << "'s turn: " << endl;
            NimGame.player_play();

            // Switch to computer's turn
            firstPlayer = 0;
        }
    }
   
    // Check the which one has to take the last marble to lose the game
    if (firstPlayer == 0) // Computer's turn 
    {
        cout << "Computer must take the last marble. You win!" << endl;
    }
    else   // Player's turn means player loses
    {
        cout << "You must take the last marble. You lose!" << endl;
    }

    return 0;
}
