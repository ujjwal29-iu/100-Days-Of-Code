#include <stdio.h>

int main() {
    int percent;                         

    printf("Enter percentage: ");          
    scanf("%d", &percent);               

    
    if (percent >= 90 && percent <= 100)
        printf("Grade A");
    else if (percent >= 80 && percent < 90)
        printf("Grade B");
    else if (percent >= 70 && percent < 80)
        printf("Grade C");
    else if (percent >= 60 && percent < 70)
        printf("Grade D");
    else if (percent >= 0 && percent < 60)
        printf("Grade F");
    else
        printf("Invalid percentage");      

    return 0;                              
}
