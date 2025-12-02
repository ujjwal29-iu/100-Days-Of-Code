#include <stdio.h>

int main() {
    float radius, area, circumference;   

    printf("Enter radius: ");              
    scanf("%f", &radius);              

    area = 3.14 * radius * radius;        
    circumference = 2 * 3.14 * radius;     

    printf("Area=%.2f, Circumference=%.2f", area, circumference);
                                        

    return 0;                             
}
