#include <stdio.h>

int main() {
    int a, b;
    char op;                                   

    printf("Enter two numbers and an operator (+, -, *, /, %%): ");
    scanf("%d %d %c", &a, &b, &op);              

    
    switch (op) {
        case '+':
            printf("%d", a + b);            
            break;
        case '-':
            printf("%d", a - b);             
            break;
        case '*':
            printf("%d", a * b);                 
            break;
        case '/':
            if (b != 0)
                printf("%d", a / b);          
            else
                printf("Error: Division by zero");
            break;
        case '%':
            if (b != 0)
                printf("%d", a % b);             
            else
                printf("Error: Division by zero");
            break;
        default:
            printf("Invalid operator");          
    }

    return 0;                               
}