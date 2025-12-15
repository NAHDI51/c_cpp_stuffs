#include <bits/stdc++.h>
using namespace std;

#define MAX 10000000
int col;
int dp[101][101];

int dynamic(vector<vector<int>>& m, int r, int c) {
    if(c <= 0 || c > col) return MAX;
    //Otherwise, always valid.
    if(r == 0) return dp[r][c] = 0;
    if(dp[r][c] != -1) return dp[r][c];
    dp[r][c] = m[r-1][c-1] + min({dynamic(m, r-1, c-1), dynamic(m, r-1, c), dynamic(m, r-1, c+1)});
    return dp[r][c];
}
int minFallingPathSum(vector<vector<int>>& m) {
    col = m[0].size();
    memset(dp, -1, sizeof(dp));
    int ans = MAX;
    for(int i = 0; i < col; i++) ans = min(ans, dynamic(m, m.size(), i+1));
    return ans;
}

int main( ){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i  =0; i < n; i++) 
        for(int j = 0; j < n; j++)
            cin >> v[i][j];
    cout << minFallingPathSum(v) << '\n';
}