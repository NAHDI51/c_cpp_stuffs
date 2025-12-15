#include <bits/stdc++.h>
using namespace std;

//Question:
/*
Given K elements with a[0, ..., k-1] values and b[0, ..., k-1] weights and a maximum weight capacity, 
determine the maximum value you can get.
*/

int knapsack(vector<int>& a, vector<int>& b, int n) {
    vector<vector<int>> dp(a.size()+1, vector<int>(n+1, 0));
    for(int i = 1; i <= a.size(); i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if((j - b[i-1]) >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-b[i-1]] + a[i-1]);
        }
        //cout << dp[i][n] << '\n';
    }
    return dp[dp.size()-1][dp[0].size()-1];
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> a, b;
    int c = k;
    while(c--) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    c = k;
    while(c--) {
        int t;
        cin >> t;
        b.push_back(t);
    }
    cout << knapsack(a, b, n) << '\n';
}