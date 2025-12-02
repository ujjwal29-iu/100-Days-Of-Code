#include <stdio.h>
#include <math.h>     

int main() {
    int n, original, digit, count = 0;
    int sum = 0;

    printf("Enter a number: ");        
    scanf("%d", &n);                 

    original = n;                       

    
    int temp = n;
    while (temp != 0) {
        count++;
        temp = temp / 10;
    }

    
    temp = n;
    while (temp != 0) {
        digit = temp % 10;
        sum = sum + pow(digit, count);  
        temp = temp / 10;
    }

    
    if (sum == original)
        printf("Armstrong");
    else
        printf("Not Armstrong");

    return 0;
}