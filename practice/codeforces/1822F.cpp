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

#define MAX 100000000000000000ll
#define MIN -MAX

#define mod 1000000007LL

#define clr(x, y) memset(x, y, sizeof(x))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};


void solve() {
    int n;
    ll k, c;
    cin >> n >> k >> c;
    vii adj(n+1);
    vii child(n+1);
    vvll pref(n+1), suf(n+1);
    vll dist(n+1);

    forn(i, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }

    function<ll(int,int,ll)> dfs = [&] (int u, int p, ll h) -> ll {
        dist[u] = 0;
        for(auto v : adj[u]) {
            if(v != p) {
                child[u].pb(v);
                dist[u] = max(dist[u], dfs(v,u,h+1)+k);
            }
        }
        int K = child[u].sz();
        pref[u].rsz(K), suf[u].rsz(K);
        forn(i, K) {
            pref[u][i] = dist[child[u][i]];
            if(i > 0) pref[u][i] = max(pref[u][i-1], pref[u][i]);
        }
        rof(i, K) {
            suf[u][i] = dist[child[u][i]];
            if(i < K-1) suf[u][i] = max(suf[u][i], suf[u][i+1]);
        }
        // cout << dist[u] << ' ' << u << '\n';
        return dist[u];
    };
    dfs(1,-1,0);
    ll mx = dist[1];
    // ll dp(n+1);
    // cout << mx << '\n';
    function<void(int,ll,ll)> reroot = [&](int u, ll so_far, ll h) -> void {

        int K = child[u].sz();
        forn(i, K) {
            auto v = child[u][i];
            ll from_parent = max({so_far, (i>0) ? pref[u][i-1]+k : MIN, (i < K-1) ? suf[u][i+1]+k : MIN});
            ll cur = from_parent+k;
            ll crmx = max(dist[v], cur);
            mx = max(mx, crmx - (h+1)*c);
            reroot(v, cur, h+1);
        }
    };
    reroot(1,0,0);
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

