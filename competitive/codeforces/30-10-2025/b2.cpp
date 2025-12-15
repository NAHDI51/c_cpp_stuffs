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
    int n;
    cin >> n;
    vs grid(n);
    forn(i,n) cin >> grid[i];

    auto outrng = [&](int x, int y) {
        return x < 0 || x >= n || y < 0 || y >= n;
    };

    // Check for illegal triple-streak in input (cannot remove black cells)
    forn(i,n) forn(j,n) {
        if(grid[i][j] == '#') {
            if(i+2 < n && grid[i+1][j] == '#' && grid[i+2][j] == '#') {
                cout << "NO\n"; return;
            }
            if(j+2 < n && grid[i][j+1] == '#' && grid[i][j+2] == '#') {
                cout << "NO\n"; return;
            }
        }
    }

    vector<vb> vis(n, vb(n,false));
    int cnt_black = 0;

    // Find all black cells count & first black to DFS from
    int sx = -1, sy = -1;
    forn(i,n) forn(j,n) {
        if(grid[i][j] == '#') {
            cnt_black++;
            if(sx == -1) sx = i, sy = j;
        }
    }

    if(cnt_black == 0) { // can paint a single cell black
        cout << "YES\n";
        return;
    }

    // DFS to check connectivity + count components
    function<void(int,int)> dfs = [&](int x,int y) {
        vis[x][y] = true;
        forn(k,4) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(outrng(nx,ny)) continue;
            if(grid[nx][ny] != '#') continue;
            if(!vis[nx][ny]) dfs(nx,ny);
        }
    };

    dfs(sx,sy);

    int connected_cnt = 0;
    forn(i,n) forn(j,n) if(grid[i][j] == '#' && vis[i][j]) connected_cnt++;

    if(connected_cnt != cnt_black) {
        cout << "NO\n";
        return;
    }

    // Check degree constraint: each cell must have <=2 neighbors
    auto deg = [&](int x,int y) {
        int d = 0;
        forn(k,4) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(!outrng(nx,ny) && grid[nx][ny] == '#') d++;
        }
        return d;
    };

    int endpoints = 0;
    forn(i,n) forn(j,n) if(grid[i][j] == '#') {
        int d = deg(i,j);
        if(d > 2) { // branching → impossible
            cout << "NO\n";
            return;
        }
        if(d == 1) endpoints++;
    }

    // Valid: 0 endpoints = closed cycle allowed only if size >= 2 (else triple-block forbidden earlier)
    // Valid: 2 endpoints = simple path
    // Other counts invalid
    if(endpoints == 0 || endpoints == 2) {
        cout << "YES\n";
    } else cout << "NO\n";
}

int main() {
    //Sublime
    // init();
    FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

