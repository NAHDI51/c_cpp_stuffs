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

#define maxN 200001

vii adj;
vb pos; 
int cnt;
int lift[maxN][19];
int h[maxN];
int p[maxN];

void dfs1(int u, int par, int hit = 0) {
    h[u] = hit;
    p[u] = par;
    lift[u][0] = p[u];
    for(auto v : adj[u]) {
        if(v == par) continue;
        dfs1(v, u, hit+1);
    }
}

void build(int n) {
    for1n(j, 18) forn(i, n) if((1<<j) <= h[i]) lift[i][j] = lift[lift[i][j-1]][j-1];
}

int jmp(int u, int p) {
    forn(k, 19) if(p&(1<<k)) u = lift[u][k];
    return u; 
}

bool dfs2(int u, int p) {
    if(pos[u]) {
        cnt++;
        return true;
    }   
    bool ok = true;
    for(auto v : adj[u]) { 
        if(v == p) continue;
        ok &= dfs2(v, u);
    }
    if(u != 0 && adj[u].sz() == 1) return false;
    return ok;
}

void solve() {
    int n, k;
    cin >> n >> k;
    adj = vii(n);
    pos = vb(n);
    cnt = 0;

    forn(i, k) {
        int a;
        cin >> a;
        pos[a-1] = true; 
    }
    forn(i, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    dfs1(0, -1);
    build(n);

    vb npos = pos;
    forn(i, n) {
        if(pos[i]) npos[jmp(i, h[i]/2)] = true;
    }
    pos = npos;
    if(dfs2(0, -1)) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}

int main() {
    FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

