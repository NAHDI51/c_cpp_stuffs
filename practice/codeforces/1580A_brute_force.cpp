//brute force solution.

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using vb = vector<bool>;
using vbb  = vector<vb>;
using ii = pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
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

#define Flag cout << "Reached here.\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

#define pb push_back
#define pbb pop_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert
#define maxN 

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 1000000000
#define MIN -MAX

#define clr(x, y) memset(x, y, sizeof(x))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

#define mod 1000000007LL

ll modpow(ll a, ll b) {
    ll sm = 1;
    while(b) {
        if(b&1) sm *= b, sm %= mod;
        a *= a, a &= mod;
        b >>= 1;
    }
    return sm;
}

ll nCr(ll n, ll r) {
    ll ans = 1;
    r = min(r, n-r);

    for(int j = 1; j <= r; j++, n--) {
        if(!(n%j)) ans *= n/j;
        else if(!(ans%j)) ans = (ans/j) * n;
        else ans = (ans*n)/j;
        ans %= mod;
    }
    return ans;
}

vi fact(ll n) {
    vi fac;
    while(n%2 == 0) n /= 2, fac.pb(2);
    for(int i = 3; i * i <= n; i += 2) 
        while(n%i == 0) fac.pb(i), n /= i;
    if(n > 1) fac.pb(n);
    return fac;
}

void init() {
   FASTIO;
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
}
void solve() {
    int n, m;
    cin >> n >> m;
    vii a(n+1, vi(m+1));
    forn(i, n) {
        forn(j, m) {
            char c;
            cin >> c;
            a[i+1][j+1] = (c-48) + a[i][j+1] + a[i+1][j] - a[i][j];
        }
    }

    auto sm =  [&](int x, int y, int p, int q) {
        return a[p][q] - a[p][y-1] - a[x-1][q] + a[x-1][y-1];
    };
    int best = MAX; 
    for(int i = 5; i <= n; i++) {
        for(int j = 4; j <= m; j++) {
            for(int k = 1; k <= i-4; k++) {
                for(int l = 1; l <= j-3; l++) {
                    best = min(best, sm(k+1, l+1, i-1, j-1) - sm(k+1, j, i-1, j) - sm(k+1, l, i-1, l) - 
                        sm(i, l+1, i, j-1) - sm(k, l+1, k, j-1) + ((i-k-1)<<1) + ((j-l-1)<<1));
                }
            }
        }
    }
    cout << best << '\n';
    cout << '\n';
}

int main() {
   init();

    int t;
    cin >> t;
    while((t--)) {
        solve();
    }

}

