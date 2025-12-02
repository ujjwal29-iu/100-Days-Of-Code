//Q98: Print initials of a name with the surname displayed in full.

/*
Sample Test Cases:
Input 1:
John David Doe
Output 1:
J.D. Doe

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1000];
    int len, i = 0, lastSpace = -1;

    // Input full name
    fgets(str, sizeof(str), stdin);

    // Remove newline if present
    len = strlen(str);
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';

    len = strlen(str);

    // Find the last space (before surname)
    for (i = 0; i < len; i++) {
        if (str[i] == ' ')
            lastSpace = i;
    }

    // Print initials (excluding surname)
    if (str[0] != ' ')
        printf("%c.", toupper(str[0]));

    for (i = 1; i < lastSpace; i++) {
        if (str[i] == ' ' && str[i + 1] != ' ')
            printf("%c.", toupper(str[i + 1]));
    }

    // Print space and surname in full
    if (lastSpace != -1)
        printf(" %s\n", &str[lastSpace + 1]);
    else
        printf("\n"); // single name case

    return 0;
}
