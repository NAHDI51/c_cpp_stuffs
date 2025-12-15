#include <stdio.h>

int main() {
    printf("How many times do you want to say hello? ");
    long long times;
    scanf("%lld", &times);

    for(long long i = 0; i < times; i++) {
        printf("Hello Wahi for the %lld no time!\n", i+1);
    }
    return 0;
}