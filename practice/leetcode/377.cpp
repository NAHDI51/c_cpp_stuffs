#include <bits/stdc++.h>
using namespace std;

int combinationSum4(vector<int>& a, int t) {
    int dp[1001];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= t; i++) {
        for(auto x : a) {
            if((i-x) >= 0) dp[i] += dp[i-x];
        }
    }
    return dp[t];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << combinationSum4(a, k) << '\n';
}