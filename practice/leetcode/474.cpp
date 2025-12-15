#include <bits/stdc++.h>
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<pair<int, int>> vi;
    for(int i = 0; i < strs.size(); i++) {
        int M ,N;
        M = N = 0;
        for(int j = 0; j < strs[i].size(); j++) {
            if(strs[i][j] == '0') M++;
            else N++;
        }
        vi.push_back({M,N});
    }

    int dp[101][101];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for(int i = 0; i < strs.size(); i++) {
        for(int j = m; j >= 0; j--) {
            for(int k = n; k >= 0; k--) {
                if((dp[j][k] != -1) && (j+vi[i].first <= m) && (k+vi[i].second <= n))
                    dp[j+vi[i].first][k+vi[i].second] = max(dp[j+vi[i].first][k+vi[i].second], dp[j][k]+1);
            }
        }
    }
    int mx = 0;
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++)
            mx = max(mx, dp[i][j]);
    }
    return mx;
}

int main() {
    vector<string> vs;
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    while(n--) {
        string s;
        cin >> s;
        vs.push_back(s);
    }
    cout << findMaxForm(vs, a, b) << '\n';
}