#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[10][2][100][1000];
int k;

int solve(vector<int>& a, int n, bool t, int sm, int rem) {
    if(n == -1) {
        if(sm%k == 0 && rem%k == 0) return 1;
        else return 0;
    }
    if(dp[n][t][sm][rem] != -1) return dp[n][t][sm][rem];
    dp[n][t][sm][rem] = 0;
    int lim = t ? a[n] : 9;

    for(int i = 0 ; i <= lim; i++) {
        bool nt = (t && i == lim);
        dp[n][t][sm][rem] += solve(a, n-1, nt, sm+i, (rem*10+i)%k);
    }
    return dp[n][t][sm][rem];
}

int solve(int n) {
    vector<int> a;
    while(n) {
        a.push_back(n%10);
        n /= 10;
    }
    memset(dp, -1, sizeof(dp));
    return solve(a, a.size()-1, 1, 0, 0);

}

int main() {
    int t;
    cin>> t;
    int i = 1;
    while(t--) {
    int a, b, c;
    cin >> a >> b >> c;
    k = c;
    cout  << "Case " << i++ << ": " << solve(b) - solve(a-1) << '\n';
    }
}