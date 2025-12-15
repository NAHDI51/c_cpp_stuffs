#include <stdio.h>

int main() {
    int n = 12345;
    int rev = 0;
    while(n) {
        int temp = n % 10;
        n /= 10;
        rev *= 10;
        rev += temp;
    }
    printf("%d\n", rev);
    
}