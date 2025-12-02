#include <stdio.h>

int main() {
    int n, reversed = 0, digit, original;       

    printf("Enter a number: ");               
    scanf("%d", &n);                           

    original = n;                              


    while (n != 0) {
        digit = n % 10;                      
        reversed = reversed * 10 + digit;       
        n = n / 10;                               
    }

    
    if (original == reversed)
        printf("Palindrome");
    else
        printf("Not palindrome");

    return 0;                                  
}
