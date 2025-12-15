#include <bits/stdc++.h>
using namespace std;

#define MAX 10000000
int minFallingPathSum(vector<vector<int>>& m) {
    int dp[200][200];
    for(int i = 0; i < m[0].size(); i++) dp[0][i] = m[0][i]; //Base step

    for(int i = 1; i < m.size(); i++) {
        for(int j = 0; j < m[0].size(); j++) {
            dp[i][j] = MAX;
            for(int k = 0; k < m[0].size(); k++) {
                if(j == k) continue;
                dp[i][j] = min(dp[i][j], m[i][j]+dp[i-1][k]);
            }
        }
    }
    int mn = MAX;
    for(int i = 0; i < m[0].size(); i++) mn = min(mn, dp[m.size()-1][i]);
    return mn;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i  =0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> v[i][j];
    cout << minFallingPathSum(v) << '\n';
}