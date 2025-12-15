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

#define maxN 200002

vi adj[maxN];
int dp[maxN], id[maxN], od[maxN];
int sol[maxN];

//if id[i] = 0 or 1, we cannot associate any vertex with it.
//If od[i] = 0 or 1, dp[i] = 1, because we cannot simply proceeed further.
//if od[i] > 1, we can take the best answer.
//I've also implemented the answer for debugging purposes
int dfs(int u, int p) {
    if(dp[u] != -1) {
        if(id[u] <= 1) return 0;
        return dp[u];
    }
    dp[u] = 0;
    if(od[u] <= 1) {
        dp[u] = 1;
        if(id[u] <= 1) return 0;
        return dp[u];
    }
    for(auto v : adj[u]) {
        if(v == p) continue;
        if(dp[u] < dfs(v, u)) {
            dp[u] = dp[v];   
            sol[u] = v;
        }
    }
    dp[u]++;
    if(id[u] <= 1) return 0;
    return dp[u];
}

void clear(int n) {
    forn(i, n) {
        adj[i] = vi{};
        dp[i] = -1;
        id[i] = 0, od[i] = 0;
        sol[i] = i;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    clear(n);

    forn(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        id[b]++, od[a]++;
    }
    forn(i, n) if(dp[i] == -1) dfs(i, -1);
    int mx = 0, idx = 0;;
    forn(i, n) {
        if(mx < dp[i] ) mx = dp[i],idx = i;
    }
    cout << mx << '\n';
    /*
    while(idx != sol[idx]) {
        cout << idx+1 << ' ';
        idx = sol[idx];
    }
    cout << idx+1 << '\n';
    */
}

int main() {
    FASTIO;
    solve();
}
 