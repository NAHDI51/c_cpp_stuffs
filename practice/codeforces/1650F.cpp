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
using pll = pair<ll,ll>;
using vpl = vector<pll>;
using vpll = vector<vpl>;

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

#define lb(a, val) lower_bound(all(a), val);
#define ub(a, val) upper_bound(all(a), val);

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 1000000000000LL
#define MIN -MAX

#define mod 1000000007LL

#define clr(x, y) memset(x, y, sizeof(x))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

ll binpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a, res %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return res;
}

vi fct(ll n) {
    vi fac;
    while(n%2 == 0) n /= 2, fac.pb(2);
    for(int i = 3; i * i <= n; i += 2) 
        while(n%i == 0) fac.pb(i), n /= i;
    if(n > 1) fac.pb(n);
    return fac;
}

ll gcd(ll a, ll b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a*b) / gcd(a, b);
}

#define maxN 100002
vll t[maxN];
vll p[maxN];
vll indx[maxN];
int a[maxN];
int elap;

vll get(int e) {
    //Flag;
    ll dp[101], back[101];
    vi sol[101];
    forn(i, 101) dp[i] = MAX, back[i] = -1, sol[i] = vi{};
    dp[0] = 0, back[0] = -1, sol[0] = {};

    forn(i, t[e].sz()) {
        //if(e == 1) cout << t[e][i] << ' ' << p[e][i] << '\n';
        rof(j, 101) {
            int ix = min(100LL, j+p[e][i]);
            if(dp[ix] > dp[j]+t[e][i]) {
                dp[ix] = dp[j]+t[e][i], back[ix] = j, sol[ix] = sol[j];
                sol[ix].pb(indx[e][i]);
            }
        }
    }
    vll ans;
    for(auto c : sol[100]) ans.pb(c);
    ans.pb(dp[100]);
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m ;
    forn(i, n) t[i] = vll{}, p[i] = vll{}, indx[i] = vll{};
    elap = 0;

    forn(i, n) cin >> a[i];
    forn(i, m) {
        int e, T, P;
        cin >> e >> T >> P;
        t[e-1].pb(T), p[e-1].pb(P);
        indx[e-1].pb(i+1);
    }

    vi ans;
    forn(i, n) {
        //Flag;
        auto c = get(i);
        if(elap+c.back() > a[i]) {
            cout << -1 << '\n';
            return;
        }
        elap += c.back();
        forn(j, c.sz()-1) ans.pb(c[j]);
    }
    cout << ans.sz() << '\n';
    forn(i, ans.sz()) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

