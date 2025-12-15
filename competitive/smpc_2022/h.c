#include <stdio.h>

int main() {
    long long DP[30001] = {};
    int m[] = {1, 5, 10, 25, 50}, i, j;
    DP[0] = 1;
    for(i = 0; i < 5; i++) {
        for(j =  m[i]; j <= 30000; j++) {
            DP[j] += DP[j-m[i]];
        }
    }
    while(1) {
        int n;
        scanf("%d\n", &n);
        if(n == 0) return 0;
        else printf("%lld\n", DP[n]);
    }
    return 0;
}