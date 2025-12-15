#include <bits/stdc++.h>
using namespace std;


//Flawed
/*
int maxProfit(vector<int>& p) {
    int N = p.size();
    vector<int> dp(N+1), rdp(N+1);

    int mx = 0, cur = 0;
    dp[0] = 0, dp[1] = 0;
    for(int i = 1; i < p.size(); i++) {
        if(p[i] >= p[i-1]) cur += p[i] - p[i-1];
        else cur = 0;
        mx = max(cur, mx);
        dp[i+1] = mx;
    }
    rdp[N] = 0, rdp[N-1] = 0;
    cur = 0, mx = 0;
    for(int i = p.size()-2; i >= 0; i--) {
        if(p[i] <= p[i+1]) cur += p[i+1] - p[i];
        else cur = 0;
        mx = max(cur, mx);
        rdp[i] = mx;
    }
    int ans = 0;
    for(int i = 0; i < dp.size(); i++) {
        ans = max(ans, dp[i] + rdp[i]);
        cout << dp[i] << "  " << rdp[i] << "  " << dp[i]+rdp[i] << '\n';
    }
    
    return ans;
}
*/

//Best
int maxProfit(vector<int>& p) {
    vector<int> cng(p.size());
    for(int i = 1; i < p.size(); i++) cng[i] = p[i] - p[i-1];
    //for(auto x : cng) cout << x << ' ';
    //cout << '\n';
    int N = p.size();
    vector<int> dp1(N+1), dp2(N+1);
    dp1[0] = 0;
    int sum = 0, best = 0;
    for(int i = 0; i < cng.size(); i++) {
        sum += cng[i];
        best = max(best, sum);
        if(sum < 0) sum = 0;
        dp1[i+1] = best;
    }
    sum = 0, best = 0;
    dp2[N] = 0;
    for(int i = p.size()-1; i >= 0; i--) {
        sum += cng[i];
        best = max(best, sum);
        if(sum < 0) sum = 0;
        dp2[i] = best;
    }
    int ans = 0;
    for(int i = 0; i < dp1.size(); i++) {
        ans = max(dp1[i] + dp2[i], ans);
        //cout << dp1[i] << "  " << dp2[i] << "  " << dp1[i] + dp2[i] << '\n';
    }
    
    return ans;
}

int main() {
    vector<int> v;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        v.push_back(m);
    }
    cout << maxProfit(v) << '\n';
}