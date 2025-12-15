#include <bits/stdc++.h>
using namespace std;

/*
Dynamic programming:
Will give us the highest for each of the positions, building upon them, we fetch the highest answer.

BOTTOM UP
*/

int lcm(string a, string b) {
    if(a.empty() || b.empty()) return 0;

    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1));
    dp[0][0] = 0;

    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    return dp[dp.size()-1][dp[0].size()-1];
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << lcm(a, b) << '\n';
}



