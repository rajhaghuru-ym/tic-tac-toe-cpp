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
    cout << "You selected slot: " << userMove << endl;
}
    return 0;
}