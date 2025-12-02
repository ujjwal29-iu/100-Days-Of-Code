//Q70: Rotate an array to the right by k positions.

/*
Sample Test Cases:
Input 1:
5
1 2 3 4 5
2
Output 1:
4 5 1 2 3

*/
#include <stdio.h>

int main() {
    int n, k, i;
    
    // Input size of array
    scanf("%d", &n);
    int arr[n];
    
    // Input array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input number of rotations
    scanf("%d", &k);
    
    // Normalize k if greater than n
    k = k % n;
    
    // Rotate using temporary array
    int temp[n];
    
    // Copy last k elements to beginning
    for(i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }
    
    // Copy first (n - k) elements after that
    for(i = 0; i < n - k; i++) {
        temp[k + i] = arr[i];
    }
    
    // Print rotated array
    for(i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    
    return 0;
}

