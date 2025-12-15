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
using table = unordered_map<unsigned long, int>;

#define f first
#define s second

#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, a, b) for(int i = a; i <= b; i++)
#define for1n(i, n) for(int i = 1; i <= n; i++)
#define rof(i, n) for(int i = n-1; i >= 0; i--)
#define rofe(i, a, b) for(int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
#define dsc(type) greater<type>

#define pb push_back
#define sz size
#define maxN 1001

#define MAX 1000000000
#define MIN -MAX

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int n, k;
int w[maxN];

void solve(){
    cin >> n >> k;

    vi b(n), c(n);
    forn(i,n) cin >> b[i];
    forn(i,n) cin >> c[i];

    if(k == 0) {
        int sm = 0;
        forn(i, n) if(b[i] == 1) sm += c[i];
        cout << sm << '\n';
        return;
    }

    int sm = 0;
    forn(i, n) sm += w[b[i]];

    if(sm <= k) {
        cout << accumulate(all(c), 0) << '\n';
        return;
    }

    //Let dp[k] e the maximum value one can pull of using k weights.
    vi dp(k+1, MIN);
    dp[0] = 0;

    forn(i, n) {
        rof(j, k+1) {
            //cout << dp[j]+c[i] << '\n';
            //cout << b[i] << ' ' << w[b[i]] << '\n';
            if((j+w[b[i]]) <= k) {
                dp[j+w[b[i]]] = max(dp[j]+c[i], dp[j+w[b[i]]]);
            }
        }
    }
    int mx = 0;
    forn(i, k+1) mx = max(dp[i], mx);
    cout << mx << '\n';
}

int main() {
    forn(i, maxN) w[i] = maxN-1;
    w[1] = 0;
    for1n(i, maxN-1) {
        for1n(j, i) {
            int ni = i+i/j;
            if(ni < maxN) w[ni] = min(w[i]+1, w[ni]);
        }
    }
    //forn(i, maxN) cout << i << ' ' << w[i] << '\n';
    //cout << '\n';

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}