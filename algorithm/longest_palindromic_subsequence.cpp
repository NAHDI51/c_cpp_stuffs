#include <bits/stdc++.h>
using namespace std;

//MEMOIZATION
vector<vector<int>> dp(101, vector<int>(101)); 
int lcs(string& s, int i, int j) {
    if(i > j) return 0;
    if(dp[i][j]) return   dp[i][j];
    else if(i == j)       dp[i][j] = 1;
    else if(s[i] == s[j]) dp[i][j] = 2+lcs(s, i+1, j-1);
    else                  dp[i][j] = max(lcs(s, i+1, j), lcs(s, i, j-1));
    return dp[i][j];
}

int lcs(string s) {
    return lcs(s, 0, s.size()-1);
}

int main() {
    string s;
    cin >> s;
    cout << lcs(s) << '\n';
}