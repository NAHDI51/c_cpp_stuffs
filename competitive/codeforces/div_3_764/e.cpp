#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;
using vl = vector<ll>;
using vll = vector<vl>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using ii = pair<int ,int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;

ll A = 9973;
ll B = (int)1e9+9;

void solve() {
    int n, m;
    cin >> n >> m;
    vs s(n) ;
    string t;
    for(int i = 0; i < n; i++) cin >> s[i];
    cin >> t

    vll hsh(n, vi(m+1));
    vl p(m);
    p[0] = 1;
    for(int i = 1; i < m; i++) p[i] = (p[i-1] * A) % B;
    for(int i = 0; i < n; i++) {
        hsh[i][0] = 1;
        for(int j = 1; j < m+1; j++) 
            hsh[i][j] = ((hsh[i][j-1] * A) + s[i][j-1]) % B;
    }

    ll hash_t(m+1);
    hash_t[0] = 1;
    for(int i = 1; i < hash_t.size(); i++)
        hash_t[i] = ((hash_t[i-1] * A) + t[i-1]) % B;
        

    auto hashval = [&](int i, int l, int r) -> ll {
        return (((hsh[i][r+1] - (hsh[i][l] * p[r-l+1]) + B) % B) % B);
    };
    auto hashtval = [&] (int l ,int r) -> ll {
        return (((hash_t[r+1] - (hash_t[l] * p[r-l+1]) + B) % B) % B);
    };
    auto search = [&](int l, int r) -> vi {
        int hval = hashtval(l, r);
        for(int i = 0; i < n; i++) {
            for(int j = 0, k = l-r+1+j; k < m; j++, k++)
                if(hashval(i, j, k) == hval) return {i, j, k};
        }
        return vi{};
    }

    bool dp[1000][1000];
    memset(dp, 0, sizeof(dp));
    pair<array<int ,3>, array<int ,3>> sol[1000][1000];
    for(int i = 0, j = 1; j < m; j++, i++) {
        auto s = search(i, j);
        if(!s.empty()) {
            dp[i][j] = 1;
            sol[i][j] = {{s[0], s[1], s[2]}, {0,0,0}};
        }
    }
    for(int i = 0, j < 2; j < m; i++, j++) {
        auto s = search(i, j);
        if(!s.empty()) {
            dp[i][j] = 1;
            sol[i][j] = {{s[0], s[1], s[2]}, {0,0,0}};
        }
    }
    for(int i = 3; i < m; i++) {
        for(int j = 0; j <= i-3; j++) {
            for(int k = j+1; k < i-1; k++) {
                if(dp[j][k] != 0 && dp[k+1][i] != 0) {
                    dp[i][j] = 1;
                    sol[i][j] = {}
                }
                if(dp[i][j]) break;
            }
        }
    }

}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();   
    }
}