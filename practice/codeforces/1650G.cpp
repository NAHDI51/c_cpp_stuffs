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

using pll = pair<ll, ll>;
vi adj[maxN];
pll d1[maxN];
pll d2[maxN];
int vis[maxN];
int n, m, s, t;

//A little improvement in the implementation.
void bfs(int s) {
    for1n(i, n) vis[i] = false;
    queue<ii> q;
    d1[s] = {0, 1};
    d2[s] = {1, 0};
    vis[s] = 1;
    q.push({s, 0});
    while(!q.empty()) {
        auto c = q.front(); q.pop();
        int u = c.f, m = c.s;

        for(auto v : adj[u]) {
            if(vis[v] == 0) {
                d1[v].f = d1[u].f+1, d2[v].f = d1[v].f+1;
                q.push({v, 0}), vis[v] = 1;
            }
            if(m == 0) {
                if(vis[v] == 1 && d1[u].f == d1[v].f) vis[v] = 2, q.push({v, 1});
                
                if(d1[u].f+1 == d1[v].f) d1[v].s += d1[u].s, d1[v].s %= mod;
                if(d1[u].f+1 == d2[v].f) d2[v].s += d1[u].s, d2[v].s %= mod;
            } else {
                if(vis[v] == 1 && d2[u].f == d1[v].f) vis[v] = 2, q.push({v, 1});
                
                if(d2[u].f+1 == d2[v].f) d2[v].s += d2[u].s, d2[v].s %= mod;
            }
        }
    }
}
void solve() {
    cin >> n >> m >> s >> t;
    for1n(i, n) {
        adj[i] = vi{};
        d1[i] = {MAX, 0}, d2[i] = {MAX, 0};
    }
    forn(i, m) {
        int a, b;
        cin >> a >> b; 
        adj[a].pb(b), adj[b].pb(a);
    }
    bfs(s);
    cout << (d1[t].s + d2[t].s) % mod << '\n';
}

int main() {
    FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

