//Q78: Find the sum of main diagonal elements for a square matrix.

/*
Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 9
Output 1:
15

*/
#include <stdio.h>

int main() {
    int n, m;
    int sum = 0;

    // Input number of rows and columns
    scanf("%d %d", &n, &m);

    int matrix[n][m];

    // Input matrix elements
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Works only for square matrices
    if(n != m) {
        printf("Matrix is not square\n");
        return 0;
    }

    // Sum of main diagonal elements
    for(int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    // Print result
    printf("%d\n", sum);

    return 0;
}
