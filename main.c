#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char currentPlayer = 'X';

// Function to initialize or reset the board
void resetBoard() {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Function to draw the current board
void drawBoard() {
    printf("\n");
    printf("  1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d", i + 1);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("  ---+---+---\n");
    }
    printf("\n");
}

// Function to check for a win condition
int checkWin() {
    // Rows, columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer))
            return 1;
    }

    // Diagonals
    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer))
        return 1;

    return 0;
}

// Function to check if the board is full
int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

// Main game function
int main() {
    int row, col;
    char playAgain;

    do {
        resetBoard();
        currentPlayer = 'X';
        int gameOver = 0;

        while (!gameOver) {
            drawBoard();
            printf("Player %c, enter your move (row and column): ", currentPlayer);
            scanf("%d %d", &row, &col);

            // Validate input
            if (row < 1 || row > 3 || col < 1 || col > 3) {
                printf("Invalid input. Please enter row and column between 1 and 3.\n");
                continue;
            }

            // Adjust for 0-based indexing
            row--; col--;

            // Check if cell is empty
            if (board[row][col] != ' ') {
                printf("Cell already taken! Try again.\n");
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin()) {
                drawBoard();
                printf("Player %c wins!\n", currentPlayer);
                gameOver = 1;
            } else if (isDraw()) {
                drawBoard();
                printf("It's a draw!\n");
                gameOver = 1;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
