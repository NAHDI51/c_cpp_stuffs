#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(101, vector<int>(101, 0));
int lcs(string& a, int i1, string& b, int i2) {
    if(dp[i1][i2]) return dp[i1][i2];
    if(i1 == 0 || i2 == 0) dp[i1][i2] = 0;
    else if(a[i1] == b[i2]) dp[i1][i2] = 2 + lcs(a, i1-1, b, i2-1);
    else dp[i1][i2] = max(lcs(a, i1-1, b, i2), lcs(a, i1, b, i2-1));

    return dp[i1][i2];
}

int main() {

}