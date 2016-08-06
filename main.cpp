/*
* Ernest Ho
* Created a game of TIC TAC TOE
* A 3x3 board is created and users select where they want their X or O by typing A, B, C, ...
*/

#include <vector>
#include <iostream>

using namespace std;

const bool CLEAR_SCREEN = true;

/// @brief Utilizes an escape character sequence to clear the screen
void clearScreen() {
    cout << endl;

    if (CLEAR_SCREEN) {
        cout << "\033c";
    }

    cout << endl;

    return;
}


/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector < char >&gameBoard) {
    clearScreen();
    for (int i = 0; i < 9; i += 3) {
        cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
            << gameBoard.at(i + 2) << "  " << endl;
        if (i < 6) {
            cout << "-----|-----|-----" << endl;
        }
    }
    cout << endl;

    return;
}



/// @brief Fills vector with characters starting at lower case a.
///
///     If the vector is size 3 then it will have characters a to c.
///     If the vector is size 5 then it will have characters a to e.
///     If the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void initVector(vector <char> &v) {

    // TODO: implement function (1) 
    // GOOD
    unsigned int i = 0;
    for (i = 0; i < v.size(); ++i) {
        v.at(i) = 'a' + i;
    }
    return;
}


/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char boardPosition) {

    // TODO: implement function (2)
    // GOOD
    if (boardPosition == 'a') 
    return 0; 
    else if (boardPosition == 'b')
    return 1; 
    else if (boardPosition == 'c')
    return 2; 
    else if (boardPosition == 'd')
    return 3; 
    else if (boardPosition == 'e')
    return 4; 
    else if (boardPosition == 'f')
    return 5; 
    else if (boardPosition == 'g')
    return 6; 
    else if (boardPosition == 'h')
    return 7;
    else if (boardPosition == 'i')
    return 8; 
    else
    return -1;
}


/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board 
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector<char>  &gameBoard, unsigned int positionIndex) {

    // TODO: implement function (3)
    // GOOD
    if ((gameBoard.at(positionIndex)) != 'O' && (gameBoard.at(positionIndex) != 'X'))
    return true;
    
    else
    return false;
}

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///
/// @param board the current tic-tac-toe board 
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector<char> &gameBoard) {

    // TODO: implement function
    char boardPosition = ' ';
    int i = 0;
    
    do {
    cout << "Please choose a position: ";
    cin >> boardPosition; 
    cout << endl;
    
    i = convertPosition (boardPosition);
    }
    while ((!validPlacement(gameBoard, i)));


    return i;
}


/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same 
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board 
/// @return true if the game has been won, false otherwise
bool gameWon(const vector<char> &gameBoard) {

    // TODO: implement function
    // GOOD
    int i = 0;
    for (i = 0; i < 3; i++) {
        if ((gameBoard.at(i) == gameBoard.at(i+3)) && (gameBoard.at(i+3) == gameBoard.at(i+6)))
        return true;
        
        else if ((gameBoard.at(3*i) == gameBoard.at(3*i+1)) && (gameBoard.at(3*i+1) == gameBoard.at(3*i+2)))
        return true;
    }
    
    
    if ((gameBoard.at(0) == gameBoard.at(4)) && (gameBoard.at(4) == gameBoard.at(8)))
    return true;
    
    else if ((gameBoard.at(2) == gameBoard.at(4)) && (gameBoard.at(4) == gameBoard.at(6)))
    return true;
    
    
    
    return false;
}


/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board 
/// @return true iff the board is full (no cell is available)
bool boardFull(const vector<char> &gameBoard) {

    // TODO: implement function
    // GOOD
    unsigned int i = 0;
    int j = 0;
    for (i = 0; i < gameBoard.size(); ++i) {
        if ((gameBoard.at(i) == 'O') || (gameBoard.at(i) == 'X')) {
            ++j;
        }
    }
    
    if (j == 9)
    return true;
    
    else
    return false;
}


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main() {
    // Variables that you may find useful to utilize
    vector<char> gameBoard(9);
    int curPlay;
    int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'

    /// TODO: Initialize board to empty state
    initVector(gameBoard);

    /// TODO: Display empty board
    drawBoard(gameBoard);

    /// TODO: Play until game is over
    while ((!boardFull(gameBoard)) && (!gameWon(gameBoard))) {


        /// TODO: Get a play
        curPlay = getPlay(gameBoard);

        /// TODO: Set the play on the board
        gameBoard.at(curPlay) = (whosTurn == PLAYER1) ? 'X' : 'O';

        /// TODO: Switch the turn to the other player
        if ((!boardFull(gameBoard)) && (!gameWon(gameBoard))) {
            if (whosTurn == PLAYER1) {
                whosTurn = PLAYER2;
            }
            else if (whosTurn == PLAYER2) {
                whosTurn = PLAYER1;
            }
        }

        /// TODO: Output the updated board
         drawBoard(gameBoard);
         
}


    /// TODO: Determine winner and output appropriate message
    if (whosTurn == PLAYER1 && gameWon(gameBoard)) {
        cout << "PLAYER 1 WINS!" << endl;
    }
    else if (whosTurn == PLAYER2 && gameWon(gameBoard)) {
        cout << "PLAYER 2 WINS!" << endl;
    }
    else {
        cout << "NO ONE WINS!" << endl;
    }

    return 0;
}