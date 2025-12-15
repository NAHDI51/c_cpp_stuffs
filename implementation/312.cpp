#include <bits/stdc++.h>
using namespace std;

int dp[501][501];
int last(vector<int>& a, int l, int r) {
    int lft = (l-1 < 0) ? 1 : a[l-1];
    int ryt = ((r+1) >= a.size()) ? 1 : a[r+1];
    return lft*ryt;
}

int dynamic(vector<int>& a, int l, int r) {
    if(l > r) return -100000;
    if(dp[l][r] != -1) return dp[l][r];

    dp[l][r] = 0;
    for(int i = l; i <= r; i++) 
        dp[l][r] = max(dp[l][r], dynamic(a, l, i-1) + dynamic(a, i+1, r) + (a[i] * last(a, l, r)));
    
    return dp[l][r];
}
int maxCoins(vector<int>& a) {
    memset(dp, -1, sizeof(dp));
    return dynamic(a, 0, a.size()-1);
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << maxCoins(a) << '\n';
}