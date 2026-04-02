#include <stdio.h>
#define N 8

int board[N];

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check column and diagonals
        if (board[i] == col || 
            board[i] - i == col - row || 
            board[i] + i == col + row)
            return 0;
    }
    return 1;
}
void solve(int row) {
    if (row == N) {
        // Print solution
        printf("\nSolution:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    solve(0);
    return 0;
}
