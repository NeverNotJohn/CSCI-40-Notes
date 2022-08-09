// Chapter 4 - Loops
//
// Visualize Wumpus World using for-loops.
// Users specify the number of rows and columns.
// Students should check for correct range and
// then place the user, wumpus, and pit into the
// wumpus world.

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
   
    // Variables
    int numRow, numCol;
    int userRow, userCol;
    int wumpusRow, wumpusCol;
    int pitRow, pitCol;

    // Initiate the random seed
    srand(13);

    // Get the number of rows
    cin >> numRow;

    // Check if it is within range
    if ( !(numRow >= 2 && numRow <= 9) ) {
        cout << "Row size is illegal!";
        return 1;
    }

    // Get the number of columns
    cin >> numCol;

    // Check if it is within range
    if (  !(numCol >= 2 && numCol <= 9) ) {
        cout << "Column size is illegal!";
        return 1;
    }

    // Randomly pick a location for the user
    userRow = rand() % numRow;
    userCol = rand() % numCol;
    cout << "User location: (" << userRow << ", " << userCol << ')' << endl;

    // Randomly pick a location for the wumpus
    wumpusRow = userRow;
    wumpusCol = userCol;
    while ((wumpusRow == userRow) && (wumpusCol == userCol)) {
        wumpusRow = rand() % numRow;
        wumpusCol = rand() % numCol;
    }
    cout << "Wumpus location: (" << wumpusRow << ", " << wumpusCol << ')' << endl;

    // Randomly pick a location for the pit
    pitRow = userRow;
    pitCol = userCol;
    while (((pitRow == userRow) && (pitCol == userCol)) || ((pitRow == wumpusRow) && (pitCol == wumpusCol))) {
        pitRow = rand() % numRow;
        pitCol = rand() % numCol;
    }
    cout << "Pit location: (" << pitRow << ", " << pitCol << ')' << endl;

    // Print the grid
    
    for (int z = 0; z < numCol; z++) {
            cout << " ---";
        }

    cout << endl;

    for (int i = 0; i < numRow; i++) { // column

        for (int z = 0; z < numCol; z++) { // important stuff output locations of chars

            if ( (z == pitCol) && (i == pitRow) ) {
                cout << "| o ";
            }

            else if ( (z == userCol) && (i == userRow) ) {
                cout << "| * ";
            }

            else if ( (z == wumpusCol) && (i == wumpusRow) ) {
                cout << "| W ";
            }

            else {
                cout << "|   ";
            }
        }

        cout << "|";
        cout << endl;

        for (int z = 0; z < numCol; z++) {
            cout << " ---";
        }

        if (i == numRow - 1) {
        }

        else {
            cout << endl;
        }
   }

    // Terminate
    return 0;
}