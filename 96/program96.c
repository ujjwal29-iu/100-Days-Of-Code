//Q96: Reverse each word in a sentence without changing the word order.

/*
Sample Test Cases:
Input 1:
I love coding
Output 1:
I evol gnidoc

*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int start = 0, end = 0, len;

    // Input sentence
    fgets(str, sizeof(str), stdin);
    len = strlen(str);

    // Remove newline character if present
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';

    len = strlen(str);

    // Reverse each word in place
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            end = i - 1;
            // Reverse the word between start and end
            while (start < end) {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            start = i + 1; // move to the next word
        }
    }

    printf("%s\n", str);
    return 0;
}
