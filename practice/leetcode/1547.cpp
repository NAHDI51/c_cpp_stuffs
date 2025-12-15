#include <bits/stdc++.h>
using namespace std;

class Solution {
unordered_map<int, unordered_map<int, int>> dp;
public:

int dynamic(vector<int>& c, int l, int r) {
    if(dp[l][r] == -1) return 0;
    if(dp[l][r]) return dp[l][r];

    dp[l][r] = INT_MAX;
    for(int i = 0; i < c.size(); i++) {
        if(l < c[i] && c[i] < r) 
            dp[l][r] = min(dp[l][r], dynamic(c, l, c[i]) + dynamic(c, c[i], r) + (r-l));
    }
    if(dp[l][r] == INT_MAX) dp[l][r] = -1;
    return (dp[l][r] == -1) ? 0 : dp[l][r];
}
int minCost(int n, vector<int>& cuts) { 
    return dynamic(cuts, 0, n);
}
};

int main() {
    vector<int> a;
    int k, n;
    cin >> k >> n;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    Solution s;
    cout << s.minCost(k, a) << '\n';
}