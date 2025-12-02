//Q86: Check if a string is a palindrome.

#include <stdio.h>

int main() {
    char str[100];
    int i, len = 0, flag = 0;

    gets(str);

    while (str[len] != '\0')
        len++;

    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");

    return 0;
}