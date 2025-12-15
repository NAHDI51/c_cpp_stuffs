#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using vb = vector<bool>;
using ii = pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using ll = long long;

#define x first
#define y second

#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, a, b) for(int i = a; i <= b; i++)
#define rof(i, n) for(int i = n-1; i >= 0; i--)
#define rofe(i, a, b) for(int i = b; i >= a; i--)

#define pb push_back
#define sz size
#define maxN

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};


ll mod = 1e9+7;
int n, m;

ll modpow(ll n, ll a) {
    ll sm = 1;
    while(a) {
        if(a&1) sm *= n, sm %= mod;
        n *= n, n %= mod;
        a >>= 1;
    }
    return sm;
}

void solve() {
    cin >> n >> m;
    ll bit = 0;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        bit |= c; 
    }
    //cout << bit << '\t' << modpow(2, n-1) << '\n';
    cout << (bit * modpow(2, n-1)) % mod << '\n';
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}