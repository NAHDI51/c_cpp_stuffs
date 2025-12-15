#include <bits/stdc++.h>
using namespace std;

class Solution {
vector<vector<int>> dp;
public:

int dynamic(string& s1, string& s2, int i, int j) {
    if(dp[i][j] != -1) return dp[i][j];
    if(i == 0 || j == 0) dp[i][j] = max(i, j);
    else if(s1[i-1] == s2[j-1]) dp[i][j] = dynamic(s1, s2, i-1, j-1);
    else dp[i][j] = min(initializer_list<int>{dynamic(s1, s2, i-1, j), dynamic(s1, s2, i, j-1), dynamic(s1, s2, i-1, j-1)}) + 1;
    return dp[i][j];
}

int minDistance(string& s1, string& s2) {
    dp.resize(s1.size()+1, vector<int>(s2.size()+1, -1));
    return dynamic(s1, s2, s1.size(), s2.size());
}
};

int main() {
    string a, b;
    cin >> a >> b;
    Solution s;
    cout << s.minDistance(a, b) << '\n';
}