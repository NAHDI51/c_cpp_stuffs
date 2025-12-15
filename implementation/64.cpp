#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& a) {
    vector<vector<int>> dp(a.size(), vector<int>(a[0].size()));

    dp[0][0] = a[0][0];
    for(int i = 1; i < a.size(); i++) dp[i][0] = dp[i-1][0] + a[i][0];
    for(int i = 1; i < a[i].size(); i++) dp[0][i] = dp[0][i-1] + a[0][i];

    for(int i = 1; i < a.size(); i++) 
        for(int j = 1; j < a[0].size(); j++)
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];

    return dp[a.size()-1][a[0].size()-1];
}

int main() {

}