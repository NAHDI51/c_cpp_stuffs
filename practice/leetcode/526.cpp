#include <bits/stdc++.h>
using namespace std;

int countArrangement(int n) {
    vector<int> dp(1<<n, 0);
    dp[0] = 1;

    for(int i = 1; i < (1<<n); i++) {
        int sz = __builtin_popcount(i);
        for(int k = 0; k < n; k++) {
            //Let k+1 be the new element
            if(i&(1<<k)) {
                if(((k+1) % sz == 0) || (sz % (k+1) == 0))
                    dp[i] += (dp[i^(1<<k)]);
            }
        }
    }
    return dp[(1<<n)-1];
}

int main() {
    int n;
    cin >> n;
    cout << countArrangement(n) << '\n';
}