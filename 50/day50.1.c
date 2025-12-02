//Q99: Change the date format from dd/04/yyyy to dd-Apr-yyyy.

#include <stdio.h>
#include <string.h>

int main() {
    char date[20];
    int d, m, y;
    char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    gets(date);
    sscanf(date, "%d/%d/%d", &d, &m, &y);

    printf("%02d-%s-%d", d, months[m - 1], y);
    return 0;
}