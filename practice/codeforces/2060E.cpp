#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <initializer_list>
#include <tuple>

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

#define maxN 200004

int par[maxN];
int cnt[maxN];  
int cntf[maxN];
bool vis[maxN];
int parf[maxN];
//only for parents

void dfs(int parent, int u, vii& adj) {
    if(vis[u]) return;
    vis[u] = true;

    par[u] = parent;
    // cnt[parent]++;

    for(auto v : adj[u]) 
        dfs(parent, v, adj);
    
    return;
}

void dfs2(int parent, int u, vii& adj) {
    if(vis[u]) return;
    vis[u] = true;

    parf[u] = parent;
    // cntf[parent]++;

    for(auto v : adj[u]) {
        if(par[u] == par[v]) dfs(parent, v, adj);
    }
    return;
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2; 
    
    vii adjf(n+1);
    vii adjg(n+1);

    forn(i, m1) {
        int a, b;
        cin >> a >> b;
        adjf[b].pb(a);
        adjf[a].pb(b);
    }
    forn(i, m2) {
        int a ,b;
        cin >> a >> b;
        adjg[a].pb(b);
        adjg[b].pb(a);
    }
    for1n(i, n) {
        vis[i] = false, cnt[i] = 0, par[i] = -1;
        // cntf[i] = 0;
        parf[i] = -1;
    }
    for1n(i, n) dfs(i, i, adjg);

    int ans = 0;
    for1n(u, n) {
        for(auto v: adjf[u]) {
            if(v < u && par[v] != par[u]) ans++;
        }
    }
    // cout << "Ans: " << ans << '\n';
    for1n(i, n) vis[i] = false;
    for1n(i, n) dfs2(i, i, adjf);

    for1n(u,n) if(parf[u] == u) cnt[par[u]]++;
    for1n(u, n) if(par[u] == u) {
        // cout << cnt[par[u]] << ' ' << u << '\n';
        ans += cnt[par[u]]-1;
    }
    
    cout << ans << '\n';
}

int main() {
    //Sublime
    // init();
    // FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

