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
#include <cstring>

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
    int n;
    cin >> n;
    vii adj(n+1);

    forn(i, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vii ans;
    vi vis(n+1);
    if(n == 2) {
        cout << "1\n1" << '\n';
        return;
    }
    function<void(int,int,vi&)> path = [&](int u, int p, vi& st) {
        if(u == n) {
            for(auto x : st) vis[x] = 2;
        }
        for(auto v : adj[u]) {
            if(v != p) {
                st.pb(v);
                path(v,u,st);
                st.pbb();
            }
        }
    };
    function<void(int,int)> dfs = [&](int u, int p) {
        // cout << u << ' ' << p << '\n';
        if(adj[u].sz() > 1 && vis[adj[u][adj[u].sz()-1]] == 2) {
            swap(adj[u][adj[u].sz()-1], adj[u][adj[u].sz()-2]);
        }
        int next = -1;
        // if(vis[adj[u][adj[u].sz()-1]] != 2) ans.pb({2,adj[u][adj[u].sz()-1]});
        // if(vis[adj[u][adj[u].sz()-1]] == 2) next = adj[u][adj[u].sz()-1];
        for(int i = adj[u].sz()-1; i >= 0; i--) {
            int x = adj[u][i];
            if(x == p) continue;
            if(vis[x] == 2) {
                next = x;
                continue;
            }
            ans.pb({1});
            dfs(x,u);
            ans.pb({1});
            ans.pb({2,x});
        }
        // cout << "DE: " << u << ' ' << next << '\n';
        if(next != -1) {
            ans.pb({1});
            ans.pb({2,u});
            dfs(next,u);
        } else if(vis[u] == 2) {
        } else {
            
        }
    };
    vi cur;
    cur.pb(1);
    path(1,-1,cur);
    // for1n(i, n) cout << vis[i] << ' ';
    // cout << '\n';
    dfs(1,-1);
    cout << ans.sz() << '\n';
    for(auto x : ans) {
        for(auto y : x) cout << y << ' ';
        cout << '\n';
    }  

}

int main() {
    //Sublime
    // init();
    FASTIO;

    int t;
    cin >> t;
    while(t--) solve();
}

