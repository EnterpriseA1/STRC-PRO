#include <stdio.h>

void MATRIX_MUL(int size, int MATRIX_A[size][size], int MATRIX_B[size][size], int MATRIX_RESULT[size][size]);

int main() {
    int n;
    scanf("%d", &n);
    int MATRIX_A[n][n];
    int MATRIX_B[n][n];
    int MATRIX_RESULT[n][n];
    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &MATRIX_A[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &MATRIX_B[i][j]);
        }
    }

    MATRIX_MUL(n, MATRIX_A, MATRIX_B, MATRIX_RESULT);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", MATRIX_RESULT[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void MATRIX_MUL(int size, int MATRIX_A[size][size], int MATRIX_B[size][size], int MATRIX_RESULT[size][size]) {
    int i, j, k;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            int result = 0;
            for (k = 0; k < size; k++) {
                result += MATRIX_A[i][k] * MATRIX_B[k][j];
            }
            MATRIX_RESULT[i][j] = result;
        }
    }
}
