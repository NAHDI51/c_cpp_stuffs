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
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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


#define maxN 

void solve() {
    ll n;
    cin >> n;
    vii adj(n+1);
    vb isleaf(n+1), hasleaf(n+1), good(n+1);
    forn(i, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    ll leaf = 0;

    if(n == 2) {
        cout << 0 << '\n';
        return;
    }
    function<void(int,int)> dfs2 = [&](int u, int p) -> void {
        if(adj[u].sz() == 1) isleaf[u] = true;
        if(u == 19) {
            // for(auto v: adj[u]) cout << v << ' ';
            // cout << '\n';
        }

        if(adj[u].sz() == 1) good[u] = false;
        for(auto v : adj[u]) {
            if(v != p) {
                dfs2(v,u);
            }
            if(u == 8) {
                // cout << u << ' ' << v << ' ' << hasleaf[v] << ' ' << isleaf[v] << '\n';
            }
            if(adj[v].sz() == 1) {
                hasleaf[u] = true;
            }
        }
    };
    dfs2(1, -1);
    int c2 = 0;

    vb canp(n+1);
    for1n(i, n) {
        if (!isleaf[i] && !hasleaf[i]) {
            canp[i] = true;
            c2++;
        }
    }
    ll ans = 0;
    for1n(i, n) if(isleaf[i]) ans++;

    // cout << ans << '\n';
    ans = ans * (n-ans);
    ll cx = 0;
   for1n(u,n) {
        good[u] = true;
        if(adj[u].sz() == 1) good[u] = false;
        for(auto v : adj[u]) {
            if(u == 4) {
                // cout << u << ' ' << v << ' ' << hasleaf[v] << ' ' << isleaf[v] << '\n';
            }
            if(!isleaf[v] && !hasleaf[v]) good[u] = false;
        }
        if(good[u]) cx++;
   }
   /*
    for1n(i, n) cout << canp[i] << ' ';
    cout << '\n';
    for1n(i, n) cout << good[i] << ' ';
    cout << '\n';
    for1n(i, n) cout << hasleaf[i] << ' ';
    cout << '\n';
    for1n(i, n) cout << isleaf[i] << ' ';
    cout << '\n';
   */
   // cout << c2 << '\n';
   
   // --- Corrected counting for good nodes ---
    // --- M-centric counting for remaining pairs ---

    ll ans2 = 0;
    for1n(m, n) {
        if(isleaf[m] || !hasleaf[m]) continue;
        int cnt = 0;
        for(auto v : adj[m]) {
            if(!isleaf[v]) {
                cnt++; 
            }
        }
        ans2 += max(cnt-1, 0);
    }
    ans2 *= c2;
    // ll ans2 = num_q * num_p;
    // ans += num_p * num_q;
    // cout << ans2 << '\n';
    // cout << leaf << ' ' << ans << '\n';
    // cout << ans << ' ' << ans2 << '\n';
    // cout << cx << ' ' << num_q << ' ' << num_p << ' ' << c2 << '\n';
    cout << ans + ans2 << '\n';
}

int main() {
    //Sublime
    // init();
    FASTIO;

    int t;
    cin >> t;
    while(t--) solve();
}

