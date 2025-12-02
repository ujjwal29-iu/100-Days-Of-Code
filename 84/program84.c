//Q84: Convert a lowercase string to uppercase without using built-in functions.

/*
Sample Test Cases:
Input 1:
hello
Output 1:
HELLO

*/
#include <stdio.h>

int main() {
    char str[1000];
    int i = 0;

    // Input string
    fgets(str, sizeof(str), stdin);

    // Convert to uppercase manually
    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;  // ASCII difference between lowercase and uppercase
        }
        i++;
    }

    // Print the uppercase string
    printf("%s\n", str);
    return 0;
}
