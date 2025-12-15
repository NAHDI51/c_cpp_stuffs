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

// #define mod 1000000007LL


#define maxN 100005
#define WH 0
#define GR 1
#define BL 2

bool got  = false;
void dfs(int u, vi& c, vi& col, vi&  cyc) {
    if(col[u] == GR) return;
    cyc.pb(u);
    col[u] = GR;
    dfs(c[u], c, col, cyc);
    col[u] = BL;
}

void ZAlgorithm(vi& s, vi& Z) {
    int n = s.size();
    Z.rsz(n);
    int L = 0, R = 0;
    for(int i = 1; i < n; i++) {
        if(i <= R) Z[i] = min(R-i+1, Z[i-L]);
        while(i+Z[i] < n && s[Z[i]] == s[i+Z[i]]) Z[i]++;
        if(i + Z[i] - 1 > R) L = i, R = i + Z[i] - 1;
    }
}

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = extgcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}

bool merge(ll a1, ll m1, ll a2, ll m2, ll &res, ll &mod) {
    ll x, y;
    ll g = extgcd(m1, m2, x, y);
    if((a2 - a1) % g != 0) return false;
    ll lcm_mod = (m1 / g) * m2;
    ll m2g = m2 / g;
    ll t = (((a2 - a1) / g) % m2g) * (x % m2g) % m2g;
    if(t < 0) t += m2g;
    __int128 tmp = (__int128)a1 + (__int128)m1 * (__int128)t;
    ll r = (ll)(tmp % (__int128)lcm_mod);
    if(r < 0) r += lcm_mod;
    res = r;
    mod = lcm_mod;
    return true;
}


void shifts(vi& a, vi& b, vi& shifts) {
    int n = a.sz();
    vi aa(2*n);
    forn(i, n) aa[i] = a[i], aa[i+n] = a[i];

    vi search;
    search.ins(search.end(), all(b));
    search.pb(MIN);
    search.ins(search.end(), all(aa));

    vi Z;
    ZAlgorithm(search, Z);

    forn(i, n) {
        if(Z[n+1+i] >= n) {
            shifts.pb((n-i)%n);
        }
    }
}

#define BAD cout << "IMPOSSIVEL" << '\n';

void solve() {
   int n;
   cin >> n;
   
   vi a(n+1), b(n+1), c(n+1);
   for1n(i, n) cin >> a[i];
   for1n(i, n) cin >> b[i];
   for1n(i, n) cin >> c[i];

   if(a == b) {
    cout << 0 << '\n';
    return;
   }

    vii cycs;
    vi col(n+1, WH);
    for1n(i, n) {
        if(col[i] == WH) {
            vi cur;
            dfs(i, c, col, cur); 
            cycs.pb(cur);
        }
    }
    
    vi pos(n);

    ll ck = 0, cmod = 1;
    forn(i, cycs.sz()) {
        vi cura, curb;
        forn(j, cycs[i].sz()) {
            cura.pb(a[cycs[i][j]]);
            curb.pb(b[cycs[i][j]]);
        }
        // auto sa = cura, sb = curb;
        // sort(all(sa)), sort(all(sb));
        // if(sa != sb) {
        //     BAD;
        //     return;
        // }
        // for(auto x : cura) cout << x << ' ';
        // cout << '\n';
        // for(auto x : curb) cout << x << ' ';
        // cout << '\n';
        vi shit;
        shifts(cura, curb, shit);
        if(shit.sz() == 0) {
            BAD;
            return;
        }

        ll nk = -1, nmod = -1;
        bool merged = false;
        for(ll s : shit) {
            ll res, mod;
            if(merge(ck, cmod, s, cycs[i].sz(), res, mod)) {
                nk = res; nmod = mod;
                merged = true;
                break; // pick first valid, always minimal k
            }
        }
        if(!merged) { 
            BAD;
            return;
        }
        ck = nk;
        cmod = nmod;
    }
    if(ck > MAX) cout << "DEMAIS\n";
    else cout << ck << '\n';
    
}

int main() {
    //Sublime
    // init();
    FASTIO;
    solve();
}

