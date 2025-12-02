#include <stdio.h>

int main() {
    long num;
    int count[10] = {0}; 
    int digit, maxCount = 0, maxDigit = 0;

    printf("Enter a number: ");
    scanf("%ld", &num);

    
    while(num > 0) {
        digit = num % 10;     
        count[digit]++;      
        num = num / 10;      
    }

    
    for(int i = 0; i < 10; i++) {
        if(count[i] > maxCount) {
            maxCount = count[i];
            maxDigit = i;
        }
    }

    printf("%d\n", maxDigit);

    return 0;
}