//Q68: Delete an element from an array.

/*
Sample Test Cases:
Input 1:
5
1 2 3 4 5
2
Output 1:
1 2 4 5

*/
#include <stdio.h>

int main() {
    int n, i, pos;
    
    // Input size of array
    scanf("%d", &n);
    int arr[n];
    
    // Input array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input position to delete
    scanf("%d", &pos);
    
    // Shift elements to the left from the given position
    for(i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    n--; // reduce size after deletion
    
    // Print updated array
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
