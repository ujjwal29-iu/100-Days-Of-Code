#include <stdio.h>

int main() {
    int r, c, i, j, sum = 0;
    int a[10][10];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of the matrix:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            sum += a[i][j];
        }
    }

    printf("Sum of all elements = %d\n", sum);

    return 0;
}