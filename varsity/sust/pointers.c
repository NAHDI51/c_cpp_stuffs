#include <stdio.h>

void func(int* p) {
    int i, sum = 0;
    for(int i = 3; i < 5; i++) {
        printf("%d ",*(p+i));
        sum += *(p+i);
    }
    printf("sum: %d\n", sum);
}

int main() {
    int a[5] = {10,20,30,40,50};
    func(a+3);
}