//Q92: Find the first repeating lowercase alphabet in a string.

/*
Sample Test Cases:
Input 1:
stress
Output 1:
s

*/
#include <stdio.h>

int main() {
    char str[1000];
    int freq[26] = {0};  // to count frequency of each lowercase letter
    int i = 0;
    char first = '\0';

    // Input string
    fgets(str, sizeof(str), stdin);

    // Find first repeating character
    while (str[i] != '\0' && str[i] != '\n') {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
            if (freq[ch - 'a'] == 2) {  // found repeating
                first = ch;
                break;
            }
        }
        i++;
    }

    if (first != '\0')
        printf("%c\n", first);
    else
        printf("-1\n");  // if no repeating character found

    return 0;
}
