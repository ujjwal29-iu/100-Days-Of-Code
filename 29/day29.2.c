#include <stdio.h>

int main() {
    int n, i;
    int a[100];
    int max, min;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    
    max = a[0];
    min = a[0];

    
    for(i = 1; i < n; i++) {
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];
    }

    printf("Max = %d, Min = %d\n", max, min);

    return 0;
}