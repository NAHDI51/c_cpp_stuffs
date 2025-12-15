#include <bits/stdc++.h>
using namespace std;

int lcs(vector<int>& a) {
    int hi = 1;
    vector<int> dp(a.size());
    for(int i = 0; i < a.size(); i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) 
            if(a[i] > a[j])
                dp[i] = max(dp[i], dp[j]+1);

        hi = max(hi, dp[i]);
    }
    if(hi == 1) return a.size();
    cout << hi << '\n';
    int cnt = 0;
    for(int i = 0; i < a.size(); i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                if(dp[j]+1 == hi) cnt++;
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return cnt;
}

int main() {
    vector<int> a;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << lcs(a) << '\n';
}