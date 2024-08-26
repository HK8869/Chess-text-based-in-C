#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 8

char board[SIZE][SIZE] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

void printBoard() {
    printf("  +-----------------+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d | ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  +-----------------+\n");
    printf("    a b c d e f g h\n");
}

bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, bool isWhiteTurn) {
    // Validation logic
    return true; // Placeholder for now
}

void makeMove(int fromRow, int fromCol, int toRow, int toCol) {
    char piece = board[fromRow][fromCol];
    board[fromRow][fromCol] = ' ';
    board[toRow][toCol] = piece;
}

int main() {
    bool isWhiteTurn = true;
    while (true) {
        printBoard();
        printf("%s's turn. Enter your move (e.g., e2e4): ", isWhiteTurn ? "White" : "Black");
        char move[5];
        scanf("%s", move);
        int fromCol = move[0] - 'a';
        int fromRow = 8 - (move[1] - '0');
        int toCol = move[2] - 'a';
        int toRow = 8 - (move[3] - '0');
        if (fromRow < 0 || fromRow >= SIZE || fromCol < 0 || fromCol >= SIZE ||
            toRow < 0 || toRow >= SIZE || toCol < 0 || toCol >= SIZE) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        if (isValidMove(fromRow, fromCol, toRow, toCol, isWhiteTurn)) {
            makeMove(fromRow, fromCol, toRow, toCol);
            isWhiteTurn = !isWhiteTurn;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
    return 0;
}
