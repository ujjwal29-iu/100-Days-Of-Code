//Q67: Insert an element in an array at a given position.

/*
Sample Test Cases:
Input 1:
4
10 20 30 40
2 15
Output 1:
10 20 15 30 40

*/
#include <stdio.h>

int main() {
    int n, i, pos, val;
    
    // Input size of array
    scanf("%d", &n);
    int arr[n + 1];  // extra space for new element
    
    // Input array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input position and element to insert
    scanf("%d %d", &pos, &val);
    
    // Shift elements to the right from the given position
    for(i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert new element
    arr[pos] = val;
    n++;
    
    // Print updated array
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
