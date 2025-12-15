#include <bits/stdc++.h>
using namespace std;

int dp[11][11][2];

int solve(vector<int>& dig, int n, int score, bool flag) {
    if(n == -1) return score;
    if(dp[n][score][flag] != -1) return dp[n][score][flag];

    int lim = (flag) ? dig[n] : 9;

    dp[n][score][flag] = 0;
    for(int i = 0; i <= lim; i++) {
        int ns = (i == 1) ? score+1 : score;
        bool nf = (flag && (i == dig[n]));
        dp[n][score][flag] += solve(dig, n-1, ns, nf);
    }
    return dp[n][score][flag];
}

int countDigitOne(int n) {
    vector<int> a;
    while(n) {
        a.push_back(n%10);
        n /= 10;
    }
    memset(dp, -1 ,sizeof(dp));
    return solve(a, a.size()-1, 0, 1);
    
}

int main() {
    int n;
    cin>> n;
    cout << countDigitOne(n) << '\n';
}