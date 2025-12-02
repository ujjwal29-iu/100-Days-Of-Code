//Q98: Print initials of a name with the surname displayed in full.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100], words[10][20];
    gets(name);

    int i = 0, j = 0, k = 0;
    while (name[i] != '\0') {
        if (name[i] == ' ') {
            words[k][j] = '\0';
            k++;
            j = 0;
        } else {
            words[k][j++] = name[i];
        }
        i++;
    }
    words[k][j] = '\0';
    int count = k + 1;

    for (i = 0; i < count - 1; i++)
        printf("%c.", toupper(words[i][0]));

    printf("%s", words[count - 1]);
    return 0;
}