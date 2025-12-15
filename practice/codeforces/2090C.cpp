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

int ddx[] = {1,1,-1,-1};
int ddy[] = {1,-1,1,-1};

vpi co;

void pros() {
    vi arr(1000000, MAX);

    auto ind = [](ii a) -> int {
        return (a.f*1000+a.s);
    };
    auto uind = [](int x) -> ii {
        return {x/1000, x%1000};
    };
    for(int i = 0; i < 999; i += 3) {
        for(int j = 0; j < 999; j++) {
            forn(k, 4) {
                int x = i+ddx[k], y = j+ddy[k];
                if(x >= 0 && y >= 0 && x%3 != 0 && y%3 != 0) {
                    arr[ind({x,y})] = min(arr[ind({x,y})], i+j+1);
                }
            }
        }
    } 
    for(int j = 0; j < 999; j += 3) {
        for(int i = 0; i < 999; i++) {
            forn(k, 4) {
                int x = i+ddx[k], y = j+ddy[k];
                if(x >= 0 && y >= 0 && x%3 != 0 && y%3 != 0) {
                    arr[ind({x,y})] = min(arr[ind({x,y})], i+j+1);
                }
            }
        }
    } 
    forn(i, arr.sz()) {
        if(arr[i] != MAX) co.pb(uind(i));
    }
    sort(all(co), [&](ii& a, ii& b) {
        if(arr[ind(a)] == arr[ind(b)]) {
            if(a.f == b.f) return a.s < b.s;
            else return a.f < b.f;
        }
        else return arr[ind(a)] < arr[ind(b)];
    }
    );
    // forn(i, 30) cout << co[i].f << ' ' << co[i].s << ' ' << arr[ind(co[i])] << '\n';
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];

    vb vis(1000000, 0);

    auto ind = [](ii a) -> int {
        return (a.f*1000+a.s);
    };
    auto uind = [](int x) -> ii {
        return {x/1000, x%1000};
    };

    auto ok = [](ii a) -> bool{
        // Flag;
        // cout << a.f << "  " << a.s << '\n';
        if(((a.f % 3) == 1) && ((a.s % 3) == 1)) {
            // cout << a.f << "  " << a.s << '\n';
            // Flag;
            return true;
        }
        else return false;
    };

    int oind = 0, zind = 0;
    vpi ans;
    forn(i, n) {
        if(a[i] == 0) {
            // Flag;
            while(!(ok(co[zind]) && !vis[ind(co[zind])])) {
                // Flag;
                zind++;
            }
            // cout << ind(co[zind]) << '\n';
            vis[ind(co[zind])] = true;
            ans.pb(co[zind]);
        } else {
            while(vis[ind(co[oind])]) oind++;
            vis[ind(co[oind])] = true;
            ans.pb(co[oind]);
            zind = max(oind, zind);
        }
    }
    // cout << zind << '\n';
    forn(i, ans.sz()) cout << ans[i].f << ' ' << ans[i].s << '\n';
}

int main() {
    //Sublime
    // init();
    // FASTIO;
    pros();
    int t;
    cin >> t;
    while(t--) solve();
}

