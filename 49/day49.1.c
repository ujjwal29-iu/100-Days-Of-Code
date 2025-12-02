//Q97: Print the initials of a name.

#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    gets(name);

    printf("%c.", toupper(name[0]));

    for (int i = 1; name[i] != '\0'; i++) {
        if (name[i] == ' ' && name[i + 1] != '\0')
            printf("%c.", toupper(name[i + 1]));
    }

    return 0;
}