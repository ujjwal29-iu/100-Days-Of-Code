//Q85: Reverse a string.

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;
    gets(str);

    len = 0;
    while (str[len] != '\0')
        len++;

    for (i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}