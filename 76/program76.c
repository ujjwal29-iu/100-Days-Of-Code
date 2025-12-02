//Q76: Check if a matrix is symmetric.

/*
Sample Test Cases:
Input 1:
2 2
1 2
2 1
Output 1:
True

Input 2:
2 2
1 0
2 1
Output 2:
False

*/
#include <stdio.h>

int main() {
    int n, m;
    int isSymmetric = 1;
    
    // Input number of rows and columns
    scanf("%d %d", &n, &m);
    
    int matrix[n][m];
    
    // Input matrix elements
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // A matrix must be square to be symmetric
    if(n != m) {
        printf("False\n");
        return 0;
    }
    
    // Check symmetry: matrix[i][j] == matrix[j][i]
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if(!isSymmetric) break;
    }
    
    if(isSymmetric)
        printf("True\n");
    else
        printf("False\n");
    
    return 0;
}
