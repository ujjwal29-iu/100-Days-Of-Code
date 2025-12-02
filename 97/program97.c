//Q97: Print the initials of a name.

/*
Sample Test Cases:
Input 1:
John Doe
Output 1:
J.D.

*/
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    int i = 0;

    // Input full name
    fgets(str, sizeof(str), stdin);

    // Print first initial
    if (str[0] != ' ' && str[0] != '\n')
        printf("%c.", toupper(str[0]));

    // Loop through string to find spaces
    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0' && str[i + 1] != '\n')
            printf("%c.", toupper(str[i + 1]));
        i++;
    }

    printf("\n");
    return 0;
}
