#include <stdio.h>
#include <stdbool.h>

// Function to print the Tic Tac Toe board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if there is a winner
bool checkWin(char board[3][3], char symbol) {
    // Check rows, columns, and diagonals for the same symbol
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return true;
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
            return true;
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return true;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return true;

    return false;
}

// Function to check if the board is full
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char board[3][3];
    int row, col;
    char currentPlayer = 'X';

    // Initialize the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Welcome to 3x3 Tic Tac Toe!\n");
    printf("Player 1: X\tPlayer 2: O\n");

    // Game loop
    while (true) {
        printBoard(board);

        // Get the current player's move
        printf("Player %c, enter your move (row [1-3] and column [1-3]): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Convert input to array indices
        row--;
        col--;

        // Check if the move is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Check if the current player wins
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                printf("Congratulations! Player %c wins!\n", currentPlayer);
                break;
            }

            // Check if the board is full (draw)
            if (isBoardFull(board)) {
                printBoard(board);
                printf("It's a draw!\n");
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    return 0;
}
