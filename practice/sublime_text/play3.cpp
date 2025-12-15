#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

void init() {
    #ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    #endif
}

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

#define maxN 200003

vi adj[maxN];
bool vis[maxN];
map<ii, bool> ans;
//map<ii, bool> bad;
ii ind[maxN];

void dfs(int u) {
    vis[u] = true;
    for(auto v : adj[u]) {
        int mn = min(v,u), mx = max(v,u);
        if(!vis[v]) {
            //Flag;
            if(ans.find({mn,mx}) == ans.end()) ans[{mn,mx}] = 0; 
            dfs(v);
        }
        else {
            if(ans.find({mn,mx}) != ans.end()) continue;
            ans[{mn,mx}] = 1;
        }
    }
}

bool work(int u, int root, int h, vi& a) {
    a.pb(u);
    if(h == 3) {
        if(u == root) return true;
        a.pbb();
        return false;
    }
    bool ok = false;
    for(auto v : adj[u]) {
        ok |= work(v, root, h+1, a);
        if(ok) return true;
    }
    a.pbb();
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    forn(i, n) adj[i] = vi{}, vis[i] = false;
    forn(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(a > b) swap(a, b);
        adj[a].pb(b);
        adj[b].pb(a);
        ind[i] = {a,b};
    }
    if(m <= n+1) {
        dfs(0);
        forn(i, m) {
            cout << ans[ind[i]];
        }
        cout << '\n';
        return;
    } 
    forn(i, n) {
        vi a;
        if(work(i,i,0,a)) {
            //Flag;
            //forn(i, a.sz()) cout << a[i] << ' ';
            //cout << '\n';
            ans[{min(a[0],a[1]), max(a[1],a[2])}] = 1;
            ans[{min(a[1],a[2]), max(a[1],a[2])}] = 1;
            ans[{min(a[2],a[0]), max(a[2],a[0])}] = 0;
            //bad[{min(a[0],a[1]), max(a[1],a[2])}] = true;
            //bad[{min(a[1],a[2]), max(a[1],a[2])}] = true;
            break;
        }
    }
    dfs(0);
    forn(i, m) cout << ans[ind[i]];
    cout << '\n';
} 

int main() {
    //Sublime
    init();
    FASTIO;
    int t;
    cin >> t;
    forn(i, t) solve();
}


