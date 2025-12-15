#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
#define MAX 1000000
int dynamic(string& s, int l, int r) {
    if(l > r) return 0;
    if(l == r) dp[l][r] = 1;
    if(dp[l][r] != -1) return dp[l][r];

    if(s[l] == s[r]) dp[l][r] = dynamic(s, l, r-1);
    else {
        dp[l][r] = MAX;
        for(int k = l; k < r; k++) {
            dp[l][r] = min(dp[l][r], dynamic(s, l, k) + dynamic(s, k+1, r));
        }
    }
    return dp[l][r];
}
int strangePrinter(string s) {
    memset(dp, -1, sizeof(dp));
    string st;
    for(int i = 0; i < s.size()-1; i++) {
        while(s[i] == s[i+1]) i++;
        st.push_back(s[i]);
    }
    if(s.back() != st.back()) st.push_back(s.back());
    return dynamic(st, 0, st.size()-1);
}

int main() {
    string s;
    cin >> s;
    cout << strangePrinter(s) << '\n';
}