#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000
int main() {
    int t, mx = 0;
    cin >> t;
    int dp[10001];
    memset(dp, 0, sizeof(dp));
    vector<int> arr;
    while(t--) {
        int m;
        cin >> m;
        arr.push_back(m);
        mx = max(mx, arr.back());
    }
    for(int i = 1; i*i <= mx; i++) dp[i*i] = 1;

    for(int i = 2; i <= mx; i++) {
        if(dp[i] == 1) continue;
        dp[i] = MAX;
        for(int j = 1; j <= i/2; j++)
            dp[i] = min(dp[i], dp[j]+dp[i-j]);  
    }
    for(int i = 0; i < arr.size(); i++) 
        cout << dp[arr[i]] << '\n';
}