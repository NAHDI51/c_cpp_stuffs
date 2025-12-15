#include <bits/stdc++.h>
using namespace std;

//Let dp[s][i][j] denote the highest that can be made using i rows and j cols, where
//s=0 means negative, s=1 means positive
//FIrst, memset the dp with the value of -1.
//If grid[i-1][j-1] == 0, dp[0][i][j] = 0, dp[1][i][j] = 0;

//Let dp[1][i][j] value exist IFF we can make a positive value out of it.
//Let dp[0][i][j] value exist IFF we can make a negative value out of it.
//Then dp[1][i][j] = max(dp[0][i-1][j] * grid[i-1][j-1], dp[0][i][j-1] * grid[i-1][j-1], dp[1][i-1][j] * grid[i-1][j-1], dp[1][i][j-1] * grid[i-1][j-1])
//If they exist
//And dp[0][i][j] = min(dp[])

//Focus on two things. WE gotta make this negatively highest, and positively highest.
long long mod = 1e9+7;
long long MAX = 10000000000000;
long long MIN = -MAX;
long long dp[2][16][16];
int maxProductPath(vector<vector<int>>& a) {
    for(int i = 0; i <= a.size(); i++) 
        for(int j = 0; j <= a[0].size(); j++)
            dp[0][i][j] = dp[1][i][j] = -69;

    for(int i = 1; i <= a.size(); i++) {
        for(int j = 1; j <= a[0].size(); j++) {
            if(i == 1 && j == 1) {
                if(a[i-1][j-1] < 0) dp[0][i][j] = a[i-1][j-1];
                else if(a[i-1][j-1] == 0) dp[0][i][j] = dp[1][i][j] = a[i-1][j-1];
                else dp[1][i][j] = a[i-1][j-1];
                continue;
            }
            if(a[i-1][j-1] == 0) 
                dp[0][i][j] = 0, dp[1][i][j] = 0;

            //IF we currently have a negative value, we either switch to positive, or retain previous niggative
            else if(a[i-1][j-1] < 0) {
                dp[1][i][j] = MIN;
                if(dp[0][i-1][j] != -69) 
                    dp[1][i][j] = max(dp[1][i][j], dp[0][i-1][j] * a[i-1][j-1]);
                if(dp[0][i][j-1] != -69)
                    dp[1][i][j] = max(dp[1][i][j], dp[0][i][j-1] * a[i-1][j-1]);

                dp[0][i][j] = MAX;
                if(dp[1][i-1][j] != -69)
                    dp[0][i][j] = min(dp[0][i][j], dp[1][i-1][j] * a[i-1][j-1]);
                if(dp[1][i][j-1] != -69)
                    dp[0][i][j] = min(dp[0][i][j], dp[1][i][j-1] * a[i-1][j-1]);
                
                if(dp[1][i][j] == MIN) dp[1][i][j] = -69;
                if(dp[0][i][j] == MAX) dp[0][i][j] = -69;
            }
            else {
                dp[1][i][j] = MIN;
                if(dp[1][i-1][j] != -69)
                    dp[1][i][j] = max(dp[1][i][j], dp[1][i-1][j] * a[i-1][j-1]);
                if(dp[1][i][j-1] != -69)
                    dp[1][i][j] = max(dp[1][i][j], dp[1][i][j-1] * a[i-1][j-1]);
                
                dp[0][i][j] = MAX;
                if(dp[0][i-1][j] != -69)
                    dp[0][i][j] = min(dp[0][i][j], dp[0][i-1][j] * a[i-1][j-1]);
                if(dp[0][i][j-1] != -69)
                    dp[0][i][j] = min(dp[0][i][j], dp[0][i][j-1] * a[i-1][j-1]);

                if(dp[1][i][j] == MIN) dp[1][i][j] = -69;
                if(dp[0][i][j] == MAX) dp[0][i][j] = -69;
            }
        }
    }
    return (dp[1][a.size()][a[0].size()] == -69) ? -1 : dp[1][a.size()][a[0].size()] % mod;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vv(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> vv[i][j];
    cout << maxProductPath(vv) << '\n';
}