#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>> dp;
bool isMatch(string s, string p) {
    dp.resize(s.size(), vector<int>(p.size(), -1));
    /*
    if(s.empty()) {
        for(auto x : p) if(x != '*') return false;
        return true;
    }
    */
    return dynamic(s, p, s.size()-1, p.size()-1);
}
bool dynamic(string& s, string& p, int i, int j) {
    if(i == -1) {
        if(j == -1) return true;
        for(int k = 0; k <= j; k++) if(p[k] != '*') return false;
        return true;
    }
    if(dp[i][j] != -1) return dp[i][j];
    if(p[j] == '?') dp[i][j] = dynamic(s, p, i-1, j-1);
    else if(p[j] == '*') {
        for(int k = 0; k <= (i+1); k++) {
            if(dynamic(s, p, i-k, j-1)) {
                dp[i][j] = true;
                return dp[i][j];
            }
        }
        dp[i][j] = false;
    } else dp[i][j] = ((s[i] == p[j]) && dynamic(s, p, i-1, j-1));
    
    return dp[i][j];
}
};

int main() {
    string s, p;
    cin >> s >> p;
    Solution sol;
    cout << sol.isMatch(s, p) << '\n';
}