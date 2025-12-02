#include <stdio.h>

int main() {
    int n, i;
    float numerator = 2.0, denominator = 3.0, sum = 0.0;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        sum = sum + (numerator / denominator);
        numerator = numerator + 2;
        denominator = denominator + 4;
    }

    printf("Approximate sum: %.2f", sum);
    return 0;
}