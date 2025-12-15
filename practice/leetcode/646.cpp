#include <bits/stdc++.h>
using namespace std;

int findLongestChain(vector<vector<int>>& p) {
    sort(p.begin(), p.end());

    vector<int> dp(p.size());
    dp[0] = 1;
    for(int i = 1; i < p.size(); i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) 
            if(p[j][1] < p[i][0])
                dp[i] = max(dp[i], dp[j]+1);
    }
    return dp.back();
}

int main() {
    vector<vector<int>> v;
    int n;
    cin >> n;
    while(n--)  {
        int a, b;
        cin >> a >> b;
        v.push_back(vector<int>({a, b}));
    }
    cout << findLongestChain(v) << '\n';
}