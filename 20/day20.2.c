#include <stdio.h>
#include <string.h>

int main() {
    char binary[50];  
    int i;

    printf("Enter a binary number: ");
    scanf("%s", binary);   

    
    for (i = 0; i < strlen(binary); i++) {
        if (binary[i] == '0')
            binary[i] = '1'; 
        else if (binary[i] == '1')
            binary[i] = '0';   
    }

    
    printf("%s", binary);

    return 0;
}