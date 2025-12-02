//Q99: Change the date format from dd/04/yyyy to dd-Apr-yyyy.

/*
Sample Test Cases:
Input 1:
15/04/2025
Output 1:
15-Apr-2025

*/
#include <stdio.h>
#include <string.h>

int main() {
    int day, month, year;
    char months[][4] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    // Input date in dd/mm/yyyy format
    scanf("%d/%d/%d", &day, &month, &year);

    // Validate month
    if (month < 1 || month > 12) {
        printf("Invalid month\n");
        return 0;
    }

    // Print in desired format
    printf("%02d-%s-%d\n", day, months[month - 1], year);

    return 0;
}
