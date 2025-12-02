#include <stdio.h>

int main() {
    int n, m;
    int a[10][10];
    printf("Enter rows and columns: ");
    scanf("%d %d", &n, &m);

    printf("Enter matrix elements:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    
    for(int col = 0; col < m; col++) {
        int i = 0, j = col;
        while(i < n && j >= 0) {
            printf("%d ", a[i][j]);
            i++;
            j--;
        }
    }

    
    for(int row = 1; row < n; row++) {
        int i = row, j = m - 1;
        while(i < n && j >= 0) {
            printf("%d ", a[i][j]);
            i++;
            j--;
        }
    }

    return 0;
}