#include <stdio.h>

int main() {
    int i, j, space;

    for(i = 1; i <= 5; i++) {
        
        for(space = 1; space <= 5 - i; space++) {
            printf(" ");
        }

        
        for(j = 6 - i; j <= 5; j++) {
            printf("%d", j);
        }

        printf("\n"); 
    }

    return 0;
}