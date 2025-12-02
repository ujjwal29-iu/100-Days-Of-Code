#include <stdio.h>
#include <math.h>  

int main() {
    float principal, rate, time;        
    float simpleInterest, compoundInterest;

    printf("Enter principal, rate and time: ");   
    scanf("%f %f %f", &principal, &rate, &time); 

    simpleInterest = (principal * rate * time) / 100;  
    compoundInterest = principal * pow((1 + rate / 100), time) - principal;  

    printf("Simple Interest=%.2f, Compound Interest=%.2f", simpleInterest, compoundInterest);
                                                      

    return 0;                                        
}
