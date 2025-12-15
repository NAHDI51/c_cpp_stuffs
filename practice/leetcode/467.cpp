#include <bits/stdc++.h>
using namespace std;

int findSubstringInWraproundString(string p) {
    int hash[26];
    int dp[100001];
    memset(hash, 0, sizeof(hash));
    //memset(dp, 0, sizeof(dp));
    dp[0] = 1, hash[p[0]%26] = 1;
    for(int i = 1, l = 0, r = 0; i < p.size(); i++) {
        if(((p[i-1]+1)%26) == p[i]) r++;
        else r = i, l = i;
        if(hash[p[i]%26] < (r-l+1)) {
            dp[i] = r-l+1 - hash[p[i]%26];
            hash[p[i]%26] = r-l+1;
        } else 
            dp[i] = 0;
    }
    int cnt = 0;
    for(int i = 0; i < p.size(); i++) cnt += dp[i];
    return cnt;
}

int main() {
    string s;
    cin >> s;
    cout << findSubstringInWraproundString(s) << '\n';
}