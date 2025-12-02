//Q94: Find the longest word in a sentence.

/*
Sample Test Cases:
Input 1:
I love programming
Output 1:
programming

*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    char word[1000], longest[1000];
    int i = 0, j = 0, maxLen = 0, len = 0;

    // Input sentence
    fgets(str, sizeof(str), stdin);

    while (1) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
            word[j++] = str[i];
        } else {
            word[j] = '\0';
            len = strlen(word);
            if (len > maxLen) {
                maxLen = len;
                strcpy(longest, word);
            }
            j = 0; // reset for next word
            if (str[i] == '\0' || str[i] == '\n')
                break;
        }
        i++;
    }

    printf("%s\n", longest);
    return 0;
}
