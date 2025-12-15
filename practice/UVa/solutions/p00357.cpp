#include <bits/stdc++.h>
using namespace std;

int main() {
    int c = 0;
    /*
    long long dp[30001];
    int coins[5] = {1, 5, 10, 25, 50};
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < 5; i++) {
        for(int j = coins[i]; j < 30001; j++) {
            dp[j] += dp[j-coins[i]];
        }
    }
    */
    long long DP[30001] = {};
    int m[] = {1, 5, 10, 25, 50}, i, j;
    DP[0] = 1;
    for(i = 0; i < 5; i++) {
        for(j =  m[i]; j <= 30000; j++) {
            DP[j] += DP[j-m[i]];
        }
    }

    while(scanf("%d", &c) == 1) {
        if(DP[c] == 1) cout << "There is only 1 way to produce " << c << " cents change.\n";
        else cout << "There are " << DP[c] << " ways to produce " << c << " cents change.\n";
        //cout << "reached here.\n";
    }
    return 0;
/*
    while(scanf("%d", &c) == 1) {
        if(dp[c] != 1)
            printf("There are %lld ways to produce %d cents change.\n", dp[c], c);
        else
            printf("There is only 1 way to produce %d cents change.\n", c);
    }
*/
}
/*
17
11
4
*/