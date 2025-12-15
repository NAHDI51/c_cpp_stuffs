#include <bits/stdc++.h>
using namespace std;

int maxUncrossedLines(vector<int>& a, vector<int>& b) {
    int dp[501][501];
    for(int i = 0; i <= a.size(); i++) dp[i][0] = 0;
    for(int i = 0; i <= b.size(); i++) dp[0][i] = 0;

    for(int i = 1; i <= a.size(); i++) {
        for(int j = 1; j <= b.size(); j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if(a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j], 1+dp[i-1][j-1]);
        }
    }
    return dp[a.size()][b.size()];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    cout << maxUncrossedLines(a, b) << '\n';
}
