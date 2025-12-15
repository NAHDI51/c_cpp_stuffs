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

using ld = long double;

#define PI 3.14159265358979323846264338327950288

ld abs(ii a) {
    return sqrt((a.f*a.f) + (a.s*a.s));
}
ld dot(ii a, ii b) {
    return (a.f * b.f) + (a.s * b.s);
}
ld deg(ld rad) {
    return (rad * 180.00) / PI;
}

#define pdd pair<double, double>

// Function to find the line given two points
vector<ld> eqs(pdd P, pdd Q)
{
    double a = Q.second - P.second;
    double b = P.first - Q.first;
    double c = a * (P.first) + b * (P.second);

    // ax - by - c = 0
    if (b < 0) {
        return {a,-b,-c};
    }
    // ax. + by - c = 0
    else {
        return {a,b,-c};
    }
}

int sign(vector<ld> eq, pdd c) {
    return (c.f * eq[0]) + (c.s * eq[1]) + eq[2];
}

ld angle(ii a, ii b, ii c) {
    ii ab = ii{b.f-a.f,b.s-a.s};
    ii bc = ii{c.f-b.f,c.s-b.s};
    // cout << ab.f << ' ' << ab.s << ' ' << ' ' << bc.f << ' ' << bc.s << '\n';
    auto e = sign(eqs(pdd{a.f,a.s}, pdd{b.f, b.s}), pdd{c.f,c.s});
    ld ans = deg(acos(dot(ab, bc) / (abs(ab) * abs(bc))));
    if(e < 0) ans = 360 - ans;
    // cout << a.f << ' ' << a.s << ' ' << ' ' << c.f << ' ' << c.s << ' ' << ' ' << ans << '\n';
    return ans;
}



ll calc(vpi& c, vpi& l, int ind) {
    vector<ld> angs;

    angs.pb(0);
    for1n(i, l.sz()-1) {
        // cout << angle(l[0])
        angs.pb(angle(l[0], c[ind], l[i]));
    }
    angs.pb(360);
    for1n(i, l.sz()-1) {
        angs.pb(angle(l[0], c[ind], l[i]) + 360);
    }
    sort(all(angs));
    for(auto x : angs) cout << x << ' ';
    cout << '\n';
    
    ll mx = 0;
    for(int i = 0; i < l.sz(); i++) {
        ll cur = 0;
        for(int j = 0; j <= i; j++) {
            int now = upper_bound(all(angs), angs[j] + 180) - 1 - angs.begin();
            cur += max(0, (now - i));

            // cout << j << ' ' << i << ' ' << now << ' ' << cur << ' ' << angs[j] << ' ' << angs[j] + 180 << '\n';
        }
        mx = max(mx, cur);
    }
    return mx;
}


void solve() {
    int n, m;
    cin >> n >> m;
    vpi c(n), l(m);
    forn(i, n) cin >> c[i].f >> c[i].s;
    forn(i, m) cin >> l[i].f >> l[i].s;

    // cout << c[0].f << ' ' << c[0].s << '\n';
    // forn(i, l.sz()) cout << l[i].f << ' ' << l[i].s << '\n';
    
    ll mx = 0;
    for(int i = 0; i < n; i ++) {
        mx = max(mx, calc(c, l, i));
    }
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

