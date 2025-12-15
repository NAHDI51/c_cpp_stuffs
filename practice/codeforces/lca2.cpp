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

/*
The lca algorithm:
1. Get the euler path, first, and height array of the graph.
2. Make a sparse table based on the euler path and keep the priorities as height.
3. Query the sparse table.
*/

#define maxN 120000
int sp[17][maxN];
int f[maxN], h[maxN];
vi adj[maxN];
vi e;
int lg[maxN*2+2];
int esz;

void dfs(int u, int p, int hit) {
    f[u] = e.sz(), e.pb(u);
    h[u] = hit;
    for(auto v : adj[u]) {
        if(v == p) continue;
        dfs(v, u, hit+1);
        e.pb(u);
    }
}

void build() {
    dfs(0, -1, 0);
    esz = e.sz();
    forn(i, esz) sp[0][i] = e[i];
    for(int j = 1; (1<<j) < esz; j++) 
        for(int i = 0; i+(1<<j) < esz; i++) 
            sp[j][i] = h[sp[j-1][i]] < h[sp[j-1][i+(1<<(j-1))]] ? sp[j-1][i] : sp[j-1][i+(1<<(j-1))];
    lg[1] = 0;
    for(int i = 2; i < maxN*2+2; i++) lg[i] = lg[i/2]+1;
}

int lca(int u, int v) {
    u = f[u], v = f[v];
    if(u > v) swap(u, v);
    auto l = lg[v-u+1];
    return (h[sp[l][u]] < h[sp[l][v-(1<<l)+1]]) ? sp[l][u] : sp[l][v-(1<<l)+1];
}

int dist(int u, int v) {
    return h[u] + h[v] - 2*h[lca(u, v)];
}

void solve() {
    int n;
    cin >> n;
    forn(i, n -1) {
        int a, b;
        cin >> a >> b; 
        a--, b--;
        adj[a].pb(b), adj[b].pb(a);
    }
    build();
    Flag;
    int m;
    cin >> m;
    forn(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << "Lca: " << lca(a,b)+1 << ' ' << "Distance: " << dist(a,b) << '\n';
    }
}

int main() {
    solve();
}

