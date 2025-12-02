//Q88: Replace spaces with hyphens in a string.

#include <stdio.h>

int main() {
    char str[100];
    int i;

    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            str[i] = '-';
    }

    printf("%s\n", str);
    return 0;
}