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

#define maxN 

#define WHITE 0 
#define GRAY 1
#define BLACK 2

void solve() {
    int n, m;
    cin >> n >> m;
    vii adj(n+1);
    vi col(n+1);

    forn(i, m) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    bool found = false;

    function<void(int,vi&)> dfs = [&](int u, vi& stk) {
        if(found) return;

        if(col[u] == BLACK) return;
        if(col[u] == GRAY) {
            found = true;
            int ind = find(all(stk), u) - stk.begin();
            cout << stk.sz()-ind << '\n';
            fore(i, ind, stk.sz()-1) cout << stk[i] << ' ';
            cout << '\n';
            return;
        }
        col[u] = GRAY; 
        for(auto v : adj[u]) {
            stk.pb(v);
            dfs(v, stk);
            stk.pbb();

            if(found) return;
        }
        col[u] = BLACK;
    };
    for1n(i, n) {
        if(col[i] == WHITE) {
            vi stk;
            stk.pb(i);
            dfs(i, stk);
            if(found) break;
        }
    }
    if(!found) cout << "IMPOSSIBLE\n";
}

int main() {
    //Sublime
    // init();
    // FASTIO;

    solve();
}

