#include <stdio.h>

int main() {
    int n, i, num;
    int a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (sorted):\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to insert: ");
    scanf("%d", &num);

    
    i = n - 1;
    while(i >= 0 && a[i] > num) {
        a[i + 1] = a[i]; 
        i--;
    }

    
    a[i + 1] = num;
    n++; 

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}