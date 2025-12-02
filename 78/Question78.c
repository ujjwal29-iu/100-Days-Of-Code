#include <stdio.h>

int main() {
    int n, i, j, sum = 0;
    int a[10][10];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &n, &n);

    printf("Enter elements of the matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    
    for(i = 0; i < n; i++) {
        sum += a[i][i];
    }

    printf("%d\n", sum);

    return 0;
}