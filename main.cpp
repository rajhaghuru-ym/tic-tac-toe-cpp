#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getUserMove() {
    int slot;
    cout << "\nEnter your move (1-9): ";
    cin >> slot;
    return slot;
}

void convertToIndex(int slot, int &row, int &col) {
    row = (slot - 1) / 3;
    col = (slot - 1) % 3;
}

bool isValidMove(char board[3][3], int row, int col) {
    // Check boundaries
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }

    // Check if cell is empty
    if (board[row][col] != '-') {
        return false;
    }

    return true;
}

int main() {
    char board[3][3];

    // UC1: Initialize board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }

    // Display board
    cout << "Tic-Tac-Toe Board:\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    // UC2: Toss
    srand(time(0));
    int toss = rand() % 2;

    char userSymbol, computerSymbol;
    bool isUserTurn;

    if (toss == 0) {
        cout << "\nYou won the toss! You play first.\n";
        userSymbol = 'X';
        computerSymbol = 'O';
        isUserTurn = true;
    } else {
        cout << "\nComputer won the toss! Computer plays first.\n";
        userSymbol = 'O';
        computerSymbol = 'X';
        isUserTurn = false;
    }

    cout << "Your Symbol: " << userSymbol << endl;
    cout << "Computer Symbol: " << computerSymbol << endl;

    if (isUserTurn)
        cout << "Current Turn: User\n";
    else
        cout << "Current Turn: Computer\n";

if (isUserTurn) {
    int userMove = getUserMove();

    int row, col;
    convertToIndex(userMove, row, col);

    if (isValidMove(board, row, col)) {
        cout << "Valid Move at (" << row << "," << col << ")" << endl;
    } else {
        cout << "Invalid Move! Try again." << endl;
    }
}
    return 0;
}