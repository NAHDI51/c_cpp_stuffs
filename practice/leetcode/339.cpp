#include <bits/stdc++.h>
using namespace std;

int dp[201][201];

int dfs(vector<vector<int>>& a, int i, int j) {
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = 1;
    if(((i-1) != -1) && (a[i-1][j] > a[i][j])) dp[i][j] = max(dp[i][j], 1+dfs(a, i-1, j));
    if(((i+1) != a.size()) && (a[i+1][j] > a[i][j])) dp[i][j] = max(dp[i][j], 1+dfs(a, i+1, j));
    if(((j-1) != -1) && (a[i][j-1] > a[i][j])) dp[i][j] = max(dp[i][j], 1+dfs(a,i,j-1));
    if(((j+1) != a[0].size()) && (a[i][j+1] > a[i][j])) dp[i][j] = max(dp[i][j], 1+dfs(a,i,j+1));

    return dp[i][j];
}

int longestIncreasingPath(vector<vector<int>>& a) {
    int mx = 1;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < a[0].size(); j++)
            mx = max(mx, dfs(a, i, j));
    return mx;
}

int main() {
    vector<int>
}