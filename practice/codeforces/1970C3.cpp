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

#define MAX 1000000000ll
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

#define RON 0
#define HER 1

void solve() {
    int n, t;
    cin >> n >> t;
    vii adj(n+1);
    forn(i,n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    map<int,int> roots;
    forn(i, t) {
        int rt;
        cin >> rt;
        roots[rt] = i;
    }
    vi dp(n+1), udp(n+1), a(n+1);
    vector<vii> pref(n+1), suf(n+1);
    vii child(n+1);

    function<void(int,int,bool)> dfs = [&](int u, int p, bool col) {
        a[u] = col;
        dp[u] = a[u]^1;
        for(auto v : adj[u]) {
            if(v != p) {
                child[u].pb(v);
                dfs(v,u,col^1);
                if(a[u] == dp[v]) dp[u] = a[u];
            }
        }
        int k = child[u].sz();
        pref[u].rsz(k), suf[u].rsz(k);
        forn(i, k) {
            pref[u][i].rsz(2);
            pref[u][i][dp[child[u][i]]]++;
            if(i > 0) forn(j, 2) pref[u][i][j] += pref[u][i-1][j];
        }
        rof(i, k) {
            suf[u][i].rsz(2);
            suf[u][i][dp[child[u][i]]]++;
            if(i < k-1) forn(j, 2) suf[u][i][j] += suf[u][i+1][j];
        }
    };
    function<void(int,int)> reroot = [&](int u, int past) {
        udp[u] = a[u]^1;
        if((a[u] == dp[u]) || (a[u] == past)) udp[u] = a[u];
        int k = child[u].sz();

        forn(i, k) {
            bool npast = a[u]^1;
            if((a[u] == past) || (i > 0 && pref[u][i-1][a[u]]) || (i < k-1 && suf[u][i+1][a[u]])) npast = a[u];
            reroot(child[u][i], npast);
        }
    };
    dfs(1,-1,0);
    reroot(1,-1);
    vi ans(t);
    for1n(i, n) {
        if(roots.find(i) != roots.end()) {
            int ind = roots[i];
            int cur = udp[i];
            if(a[i] == 1) cur ^= 1;
            ans[ind] = cur;
        }
        // cout << udp[i] << ' ';
    }
    forn(i, t) {
        if(ans[i] == RON) cout << "Ron\n";
        else cout << "Hermione\n";
    }
}

int main() {
    //Sublime
    // init();
    // FASTIO;
    solve();
}

