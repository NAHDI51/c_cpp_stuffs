#include <stdio.h>

void func(int* a) {
    int i, sum = 0;
    for(int i = 3; i < 5; i++) {
        sum += *(a+i);
    }
    printf("%d\n", sum);
}

int main() {
    int a[] = {1,2,3,4,5};
    func(a+3);
}