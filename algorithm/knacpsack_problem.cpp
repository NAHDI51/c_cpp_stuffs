#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& w, vector<int> g, int cap) {
    int dp[cap+1];
    memset(dp, 0, sizeof(dp));
    int mx = 0;

    for(int i = 0; i < w.size(); i++) {
        for(int j = cap; j >= 0; j--) {
            if(j-w[i] >= 0)
                dp[j] = max(dp[j-w[i]] + g[i] , dp[j]);
            mx = max(dp[j], mx);
        }
    }
    return mx;
}

int main() {
    vector<int> w, g;
    int n;
    int cap;
    cin >> n;
    cin >> cap;
    int n2 = n;
    while(n--) {
        int a;
        cin >> a;
        w.push_back(a);
    }
    while(n2--) {
        int a;
        cin >> a;
        g.push_back(a);
    }
    cout << knapsack(w, g, cap) << '\n';
}
