#include <stdio.h>

int main() {
    int n, i, key;
    int a[100];
    int low, high, mid, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (sorted):\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(a[mid] == key) {
            printf("Found at index %d\n", mid);
            found = 1;
            break;
        }
        else if(a[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if(found == 0)
printf("-1\n");

    return 0;
}