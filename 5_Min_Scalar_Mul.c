#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

void matrixChainOrder(int dims[], int n, int m[MAX_SIZE][MAX_SIZE], int s[MAX_SIZE][MAX_SIZE]) {
    int i, j, k, L, q;

    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParenthesis(int s[MAX_SIZE][MAX_SIZE], int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n, i;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dims[MAX_SIZE];
    printf("Enter the dimensions of matrices:\n");
    for (i = 0; i <= n; i++) {
        scanf("%d", &dims[i]);
    }

    int m[MAX_SIZE][MAX_SIZE] = {0};
    int s[MAX_SIZE][MAX_SIZE] = {0};

    matrixChainOrder(dims, n, m, s);

    printf("Minimum number of scalar multiplications: %d\n", m[1][n]);

    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(s, 1, n);
    printf("\n");

    return 0;
}
// Enter the number of matrices: 4
// Enter the dimensions of matrices:
// 10 20 30 40 50
// Minimum number of scalar multiplications: 38000
// Optimal Parenthesization: (((A1A2)A3)A4)
