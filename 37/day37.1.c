#include <stdio.h>

int main() {
    int r, c, i, j, sum;
    int a[10][10], rowSum[10];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of the matrix:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    
    for(i = 0; i < r; i++) {
        sum = 0;
        for(j = 0; j < c; j++) {
            sum += a[i][j];
        }
        rowSum[i] = sum;
    }

    printf("Sum of each row:\n");
    for(i = 0; i < r; i++) {
        printf("%d ", rowSum[i]);
    }

    return 0;
}