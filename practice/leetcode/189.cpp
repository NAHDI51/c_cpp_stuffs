#include <bits/stdc++.h>
using namespace std;

//TIME LIMIT EXCEEDED (O(N^2))
/*
#define maxN 1001
int dp[maxN][maxN]; //maxSum(l,r)

int dynamic(int k, int r) {
    if(r == -1 || k == 0) return 0;
    int mx = 0;
    for(int i = r; i >= 0; i--) mx = max(mx, dp[i][r] + dynamic(k-1, i-1));
    return mx;
}
    
void kadane(int t, vector<int>& c) {
    int best = 0, cur = 0;
    for(int i = t; i >= 0; i--) {
        cur += c[i];
        if(cur < 0) cur = 0;
        best = max(cur, best);
        dp[i][t] = best;
    }
}

int maxProfit(int k, vector<int>& p) {
    if(p.empty()) return 0;
    vector<int> c(p.size());
    c[0] = 0;
    for(int i = 1; i < c.size(); i++) c[i] = p[i] - p[i-1];
    for(int i  =0; i < c.size(); i++) kadane(i, c);
    return dynamic(k, c.size()-1);
}
*/

//O(NK)
int dp[1001][101];
int dynamic(vector<int>& p, int k, int n) {
    if(k == 0 || n == 0 || n == -1) return 0;
    if(dp[n][k] != -1) return dp[n][k];
    dp[n][k] = 0;
    for(int i = n; i >= 0; i--) {
        if((p[n] - p[i]) >= 0) dp[n][k] = max(dp[n][k], dynamic(p, k-1, i-1) + (p[n] - p[i]));
        else dp[n][k] = max(dp[n][k], dynamic(p, k, i));
    }
    //cout << dp[n][k] << '\n';
    return dp[n][k];
}
int maxProfit(int k, vector<int>& p) {
    for(int i = 0; i < 1001; i++)
        for(int j = 0; j < 101; j++) dp[i][j] = -1;
    return dynamic(p, k, p.size()-1);
}

int main() {
    vector<int> a;
    int n, k;
    cin >> n >> k;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << maxProfit(k, a) << '\n';
}