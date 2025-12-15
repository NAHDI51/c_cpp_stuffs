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
using ll = long long;
using pll = pair<ll,ll>;

#define forn(i, n) for(int i = 0; i < n; i++)
#define for1n(i, n) for(int i = 1; i <= n; i++)
#define all(x) x.begin(), x.end()
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

#define MAX 1000000000ll
#define MIN -MAX

#define WH 0
#define GR 1
#define BL 2

ll gcdll(ll a, ll b) {
    while(b) { ll t = a % b; a = b; b = t; }
    return a;
}

ll lcmll(ll a, ll b) {
    if(a == 0 || b == 0) return 0;
    ll g = gcdll(a,b);
    __int128 t = (__int128)(a / g) * (__int128)b;
    if(t > ( (__int128) ( (unsigned long long)LLONG_MAX ) )) return LLONG_MAX;
    return (ll)t;
}

void dfs(int u, vi& c, vi& col, vi& cyc) {
    if(col[u] == GR) return;
    cyc.push_back(u);
    col[u] = GR;
    dfs(c[u], c, col, cyc);
    col[u] = BL;
}

void ZAlgorithm(vi& s, vi& Z) {
    int n = (int)s.size();
    Z.assign(n, 0);
    int L = 0, R = 0;
    for(int i = 1; i < n; i++) {
        if(i <= R) Z[i] = min(R - i + 1, Z[i - L]);
        while(i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) Z[i]++;
        if(i + Z[i] - 1 > R) { L = i; R = i + Z[i] - 1; }
    }
}

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

bool merge(ll a1, ll m1, ll a2, ll m2, ll &res, ll &mod) {
    ll x, y;
    ll g = extgcd(m1, m2, x, y);
    if((a2 - a1) % g != 0) return false;
    __int128 lcm128 = (__int128)(m1 / g) * (__int128)m2;
    ll lcm_mod;
    if(lcm128 > ( (__int128)LLONG_MAX )) lcm_mod = LLONG_MAX;
    else lcm_mod = (ll)lcm128;
    ll m2g = m2 / g;
    ll diff = (a2 - a1) / g;
    ll xm = x % m2g;
    ll t = ( (__int128)( (diff % m2g + m2g) % m2g ) * (xm % m2g) ) % m2g;
    if(t < 0) t += m2g;
    __int128 tmp = (__int128)a1 + (__int128)m1 * (__int128)t;
    ll r;
    if(lcm128 > (__int128)LLONG_MAX) {
        __int128 tr = tmp % lcm128;
        if(tr < 0) tr += lcm128;
        if(tr > (__int128)LLONG_MAX) r = LLONG_MAX;
        else r = (ll)tr;
    } else {
        r = (ll)(tmp % (__int128)lcm_mod);
        if(r < 0) r += lcm_mod;
    }
    res = r;
    mod = lcm_mod;
    return true;
}

void shifts(vi& a, vi& b, vi& shifts) {
    int n = (int)a.size();
    vi aa(2*n);
    for(int i = 0; i < n; ++i) { aa[i] = a[i]; aa[i+n] = a[i]; }
    vi search;
    search.insert(search.end(), b.begin(), b.end());
    search.push_back(MIN);
    search.insert(search.end(), aa.begin(), aa.end());
    vi Z;
    ZAlgorithm(search, Z);
    for(int i = 0; i < n; ++i) {
        if(Z[n + 1 + i] >= n) shifts.push_back((n - i) % n);
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
    if(a == b) { cout << 0 << '\n'; return; }
    vii cycs;
    vi col(n+1, WH);
    for1n(i, n) {
        if(col[i] == WH) {
            vi cur;
            dfs(i, c, col, cur);
            cycs.push_back(cur);
        }
    }
    sort(cycs.begin(), cycs.end(), [](const vi &x, const vi &y){ return x.size() > y.size(); });
    unordered_set<ll> ks;
    ks.reserve(1024);
    ks.insert(0);
    ll cur_mod = 1;
    for(size_t idx = 0; idx < cycs.size(); ++idx) {
        vi &cyc = cycs[idx];
        vi cura, curb;
        for(int j = 0; j < (int)cyc.size(); ++j) { cura.push_back(a[cyc[j]]); curb.push_back(b[cyc[j]]); }
        vi shit;
        shifts(cura, curb, shit);
        if(shit.empty()) { BAD; return; }
        ll len = (ll)cyc.size();
        bool anyMerged = false;
        unordered_set<ll> nks;
        nks.reserve(max((size_t)1, ks.size() * max((size_t)1, shit.size())));
        for(ll rn : ks) {
            for(ll s : shit) {
                ll res, mod;
                if(merge(rn, cur_mod, s, len, res, mod)) {
                    anyMerged = true;
                    if(res <= MAX) nks.insert(res);
                }
            }
        }
        if(!anyMerged) { BAD; return; }
        if(nks.empty()) { cout << "DEMAIS" << '\n'; return; }
        ks.swap(nks);
        cur_mod = lcmll(cur_mod, len);
        if(cur_mod <= 0) cur_mod = LLONG_MAX;
    }
    ll ans = LLONG_MAX;
    for(ll r : ks) if(r < ans) ans = r;
    if(ans > MAX) cout << "DEMAIS" << '\n'; else cout << ans << '\n';
}

int main() {
    FASTIO;
    solve();
    return 0;
}
