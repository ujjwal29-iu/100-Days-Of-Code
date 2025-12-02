//Q77: Check if the elements on the diagonal of a matrix are distinct.

/*
Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 1
Output 1:
False

Input 2:
3 3
1 2 3
4 5 6
7 8 9
Output 2:
True

*/
#include <stdio.h>

int main() {
    int n, m;
    int isDistinct = 1;

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
        printf("False\n");
        return 0;
    }

    // Check if diagonal elements are distinct
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(matrix[i][i] == matrix[j][j]) {
                isDistinct = 0;
                break;
            }
        }
        if(!isDistinct) break;
    }

    if(isDistinct)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
