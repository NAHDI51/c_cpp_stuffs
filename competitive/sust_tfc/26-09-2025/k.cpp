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

#define double long double

#define x first
#define y second

void solve() {
    ii co1, co2;
    cin >> co1.f >> co1.s >> co2.f >> co2.s;

    int xl = min(co1.f, co2.f), xr = max(co1.f, co2.f);
    int yl = min(co1.s, co2.s), yr = max(co1.s, co2.s);
    vpi ps = {{xl, yl}, {xr, yl}, {xr, yr}, {xl, yr}};

    ii st1, st2;
    cin >> st1.f >> st1.s >> st2.f >> st2.s;

   auto intersect = [&](ii a, ii b, ii c, ii d) -> bool {
        auto ori = [&](ii p, ii q, ii r) -> int {
            ll val = (ll)(q.y - p.y) * (r.x - p.x) - (ll)(q.x - p.x) * (r.y - p.y);
            if (val == 0) return 0;
            return (val > 0 ? 1 : -1);
        };
        auto onseg = [&](ii p, ii q, ii r) {
            return min(p.x, r.x) <= q.x && q.x <= max(p.x, r.x) &&
                min(p.y, r.y) <= q.y && q.y <= max(p.y, r.y);
        };

        int o1 = ori(a, b, c), o2 = ori(a, b, d);
        int o3 = ori(c, d, a), o4 = ori(c, d, b);

        if (o1 != o2 && o3 != o4) return true;

        // IN the middle
        if (o1 == 0 && onseg(a, c, b)) return true;
        if (o2 == 0 && onseg(a, d, b)) return true;
        if (o3 == 0 && onseg(c, a, d)) return true;
        if (o4 == 0 && onseg(c, b, d)) return true;
        return false;
    };

    auto insideRect = [&](ii st) -> bool {
        return (xl <= st.x && st.x <= xr && yl <= st.y && st.y <= yr);
    };
    if(insideRect(st1) && insideRect(st2)) {
        cout << "STOP\n";
        return;
    }
    forn(i, 4) {
        if(intersect(st1, st2, ps[i], ps[(i+1)%4])) {
            cout << "STOP\n";
            return;
        }
    }
    cout << "OK\n";
}

int main() {
    //Sublime
    // init();
    // FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

