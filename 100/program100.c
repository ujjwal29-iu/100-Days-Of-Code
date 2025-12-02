//Q100: Print all sub-strings of a string.

/*
Sample Test Cases:
Input 1:
abc
Output 1:
a,ab,abc,b,bc,c

*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int len, i, j, k;
    int first = 1; // for proper comma formatting

    // Input string
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    len = strlen(str);
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';

    len = strlen(str);

    // Generate and print all substrings
    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            if (!first)
                printf(",");
            first = 0;
            for (k = i; k <= j; k++)
                printf("%c", str[k]);
        }
    }

    printf("\n");
    return 0;
}
