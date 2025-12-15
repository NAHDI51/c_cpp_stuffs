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

#define maxN 


void solve() {
    int n, k;
    cin >> n >> k;
    vb col(n+1);
    forn(i, k) {
        int c;
        cin >> c;
        col[c] = true;
    }
    vii adj(n+1);
    forn(i, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }

    vi dp(n+1);
    vii suf(n+1), pref(n+1);
    vii child(n+1);
    function<void(int,int)> dfs = [&](int u, int p ) -> void{
        dp[u] = (col[u]) ? 0 : -1;
        for(auto v : adj[u]) {
            if(v != p) {
                child[u].pb(v);
                dfs(v,u);
                if(dp[v] != -1) dp[u] = max(dp[u], dp[v]+1);
            }
        }
        int l = child[u].sz();
        pref[u].rsz(l), suf[u].rsz(l);
        forn(i, l) {
            pref[u][i] = dp[child[u][i]];
            if(i > 0) pref[u][i] = max(pref[u][i], pref[u][i-1]);
        }
        rof(i,l) {
            suf[u][i] = dp[child[u][i]];
            if(i < l-1) suf[u][i] = max(suf[u][i], suf[u][i+1]);
        }
        // cout << u << ' ' << dp[u] << '\n';
    };
    dfs(1,-1);
    int mx = dp[1];
    function<void(int,int)> reroot = [&](int u, int above) {
        if(above != -1) dp[u] = max(dp[u], above);
        if(dp[u] != -1) mx = min(mx, dp[u]);
        // cout << u << ' ' << dp[u] << ' ' << mx << ' ' << above << '\n';

        int l = child[u].sz();
        forn(i, l) {
            int v = child[u][i];
            int nb = above;
            if((i > 0) && pref[u][i-1] != -1) nb = max(nb, pref[u][i-1]+1);
            if((i < l-1) && suf[u][i+1] != -1) nb = max(nb, suf[u][i+1]+1);
            if(col[u] == true) nb = max(0,nb);
            // cout << u << ' ' << v << ' ' << above << ' ' << cur << '\n';
            reroot(v, (nb == -1) ? -1 : nb+1);
        }
    }; 
    reroot(1,-1);
    cout << mx << '\n';
}

int main() {
    //Sublime
    // init();
    // FASTIO;

    int t;
    cin >> t;
    while(t--) solve();
}

