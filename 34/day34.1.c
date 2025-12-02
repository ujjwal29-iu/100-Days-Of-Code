#include <stdio.h>

int main() {
    int n, pos, num, i;
    int a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter position and element to insert: ");
    scanf("%d %d", &pos, &num);

    
    for(i = n - 1; i >= pos; i--) {
        a[i + 1] = a[i];
    }

    
    a[pos] = num;
    n++; 

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
