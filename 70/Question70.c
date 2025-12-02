#include <stdio.h>

int main() {
    int n, k, i;
    int a[100], temp[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter number of positions to rotate: ");
    scanf("%d", &k);

    
    k = k % n;

    
    for(i = 0; i < k; i++) {
        temp[i] = a[n - k + i];
    }

    
    for(i = n - 1; i >= k; i--) {
        a[i] = a[i - k];
    }

    
    for(i = 0; i < k; i++) {
        a[i] = temp[i];
    }

    printf("Array after rotation:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
 return 0;
}