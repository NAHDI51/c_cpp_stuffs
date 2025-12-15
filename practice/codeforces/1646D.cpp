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

#define MAX 1000000000
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

ll gcd(ll a, ll b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a*b) / gcd(a, b);
}

#define maxN 200002

//dp + rerooting?
//Rerooting is redundant.
vii adj;
ii dp[maxN][2];
vpi sol[maxN][2];
int ans[maxN];

//Adjacent coloring? 
//Keep buds and leafs seperate. Their ultimate results are already determined.
//NO.

void dfs(int u, int p) {
    dp[u][0] = {0,0}, dp[u][1] = {0,0};

    for(auto v : adj[u]) {
        if(v == p) continue;
        dfs(v,u);

        //Black->White/black
        dp[u][0].f += max(dp[v][0], dp[v][1]).f;
        dp[u][0].s += max(dp[v][0], dp[v][1]).s;

        //White->black
        dp[u][1].f += dp[v][0].f, dp[u][1].s += dp[v][0].s;

        sol[u][1].pb({v, 0});
        if(dp[v][0] > dp[v][1]) sol[u][0].pb({v, 0});
        else sol[u][0].pb({v , 1});
    }
    dp[u][1].f++, dp[u][1].s -= adj[u].sz();
}

void get(int u, int m) {
    if(m == 1) ans[u] = adj[u].sz();
    else ans[u] = 1;
    for(auto v : sol[u][m]) if(ans[v.f] == 0) get(v.f, v.s);
}

void solve() {
    int n;
    cin >> n;

    adj = vii(n);

    forn(i, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    if(n == 2) {
        cout << 2 << ' ' << 2 << '\n' << 1 << ' ' << 1 << '\n';
        return;
    }
    dfs(0, -1);
    int cnt, sm = 0;

    if(dp[0][0] > dp[0][1]) get(0, 0), cnt = dp[0][0].f;
    else get(0, 1), cnt = dp[0][1].f;

    forn(i, n) sm += ans[i];

    cout << cnt << ' ' << sm << '\n';
    forn(i, n) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    solve();
}

 