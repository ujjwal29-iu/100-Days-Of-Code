#include <stdio.h>

int main() {
    int r, c, i, j, k, distinct = 1;
    int a[10][10];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    
    if(r != c) {
        printf("False\n");
        return 0;
    }

    printf("Enter elements of the matrix:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    
    for(i = 0; i < r; i++) {
        for(k = i + 1; k < r; k++) {
            if(a[i][i] == a[k][k]) {
                distinct = 0;
                break;
            }
        }
        if(distinct == 0)
            break;
    }

    if(distinct == 1)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}