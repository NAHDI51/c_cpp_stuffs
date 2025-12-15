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

#define pb push_back
#define pbb pop_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert
#define maxN 101

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

bool dp[maxN][maxN*maxN];

void solve() {
    int n;
    cin >> n;
    vi a(n) , b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];

    if(n == 1) {
        cout << 0 << '\n';
        return;
    }

    clr(dp, 0);
    dp[0][0] = 1;
    for1n(i, n) {
        forn(j, 10001) {
            if(j-a[i-1] >= 0) dp[i][j] |= dp[i-1][j-a[i-1]];
            if(j-b[i-1] >= 0) dp[i][j] |= dp[i-1][j-b[i-1]];
        }
    }
    auto t = accumulate(all(a), 0)+ accumulate(all(b), 0);
    int mn = MAX;
    forn(j, 10001) {
        if(dp[n][j]) mn = min(mn, ((j*j) + ((t-j)*(t-j))));
    }
    int sm = 0;
    forn(i, n) sm += ((n-2) * (a[i]*a[i] + b[i]*b[i]));
    cout << mn + sm << '\n';
}

int main() {
    int t;
    cin >> t;
    while((t--)) {
        solve();
    }

}


