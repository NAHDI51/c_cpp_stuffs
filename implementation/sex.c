#include <stdio.h>

int main() {
    long long n;

    printf("Enter the value of N: ");
    scanf("%lld", &n);

    long long sum = 0;
    for(long long i = 1; i <= n; i *= 2) sum += i;

    printf("The value of sum is: %lld", sum);

    return 0;
}