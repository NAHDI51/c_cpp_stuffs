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

// #include <bits/stdc++.h>

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
using lll = __int128;
using vlll = vector<__int128>;

#define f first
#define s second

#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, a, b) for(int i = a; i <= b; i++)
#define for1n(i, n) for(int i = 1; i <= n; i++)
#define all(x) x.begin(), x.end()

#define Flag cout << "Reached here.\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define pb push_back
#define pbb pop_back
#define sz size
#define rsz resize
#define ins insert

#define one_count(x) __builtin_popcount(x)
#define end_zero(x) __builtin_clz(x)
#define beg_zero(x) __builtin_ctz(x)

#define MAX 1000000000ll
#define MIN -MAX

#define mod 1000000007LL
#define clr(x, y) memset(x, y, sizeof(x))

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

#define maxN 

void solve() {
    int n, k;
    cin >> n >> k;

    vii adj(n+1);
    vi size(n+1);
    vi oks(n+1);
    vii child(n+1), suf(n+1), pref(n+1);
    vi nsize(n+1), ndp(n+1);
    forn(i, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    // for1n(i, n) cout << oks[i] << ' ';
    // cout << '\n';
    ll ans = 0;

    function<void(int,int)> dfs = [&](int u, int p) {
        size[u] = 1;
        for(auto v : adj[u]) {
            if(v != p) {
                child[u].pb(v);
                dfs(v,u);
                size[u] += size[v];
                oks[u] += oks[v];
            }
        }
        if(size[u] >= k) oks[u]++;
        int K = child[u].sz();
        pref[u].rsz(K+1), suf[u].rsz(K+1);
        forn(i, K) {
            pref[u][i] = oks[child[u][i]];
            if(i > 0) pref[u][i] += pref[u][i-1];
        }
        for(int i = K-1; i >= 0; i--) {
            suf[u][i] = oks[child[u][i]];
            if(i < K-1) suf[u][i] += suf[u][i+1];
        }
    };
    dfs(1,-1);
    function<void(int,int)> reroot = [&](int u, int p) {
        ans += oks[u];
        // cout << u << ' ' << oks[u] << '\n';
        for(auto v : adj[u]) {
            if(v != p) {
                auto lsu = size[u], lsv = size[v];
                auto oku = oks[u], okv = oks[v];
                size[u] = n - size[v];
                if(size[v] < k) oks[v]++;
                size[v] = n;
                oks[u] -= okv;
                if(size[u] < k) oks[u]--;
                oks[v] += oks[u];
                // cout << v << ' ' << u << ' ' << size[v] << ' ' << size[u] << ' ' << oks[u] << ' ' << oks[v] << '\n';
                reroot(v,u);
                size[u] = lsu, size[v] = lsv;
                oks[u] = oku, oks[v] = okv;
            }
        }
    };
    // for1n(i, n) cout << size[i] << ' ';
    // cout << '\n'; 
    // for1n(i, n) cout << oks[i] << ' ';
    // cout << '\n';
    reroot(1,-1);
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

