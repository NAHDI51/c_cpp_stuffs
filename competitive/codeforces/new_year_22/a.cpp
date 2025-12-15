#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss =vector<vs>;
using vb = vector<bool>;
using ii = pair<int ,int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using ll = long long;

void solve() {
    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int c = n/2;
        if(n%2) c++;
        if(k > c) {
            cout << -1 << '\n';
            continue;
        }
        bool dp[40][40];
        memset(dp, 0, sizeof(dp));
        int i = 0;
        while(k--) {
            dp[i][i] = 1;
            i += 2;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j]) cout << "R";
                else cout << ".";
            }
            cout << '\n';
        }
    }
}