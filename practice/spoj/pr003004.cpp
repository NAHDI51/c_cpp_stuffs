#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ull dp[18][2][160];
//We don't need to worry about any trailing zero in this one.

ull solve(vector<int>& dig, int n, bool t, int sm) {
    if(n == -1) return sm;
    if(dp[n][t][sm] != -1) return dp[n][t][sm];

    dp[n][t][sm] = 0;
    int lim = t ? dig[n] : 9;
    for(int i = 0; i <= lim; i++) 
        dp[n][t][sm] += solve(dig, n-1, t && (i == dig[n]), sm+i);

    return dp[n][t][sm];
}

vector<int> twist(int a) {
    vector<int> ans;
    while(a) {
        ans.push_back(a%10);
        a /= 10;
    }
    return ans;
}

ull Solve(ull a) {
    auto s = twist(a);
    memset(dp, -1, sizeof(dp));
    auto t = solve(s, s.size()-1, 1, 0);
    //cout << "Reached here.\n";
    return t;
}

void SOLVE(ull a, ull b) {
    if(a == 0) cout << Solve(b) << '\n';
    else cout <<  Solve(b) - Solve(a-1) << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        ull a, b;
        cin >> a >> b;
        SOLVE(a, b);
    }
}