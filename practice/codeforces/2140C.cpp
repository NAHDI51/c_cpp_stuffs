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


void solve() {
    int n;
    cin >> n;
    map<ll,int, greater<ll>> mp;
    map<ll,int, greater<ll>> mp2;

    vll a(n+1);
    ll sm = 0;
    for1n(i, n) {
        cin >> a[i];
        if(i%2 == 0) {
            mp[(2ll*a[i])+(ll)i]++;
            sm -= (ll) a[i];
        } else {
            // Flag;
            mp2[-(2ll*a[i])+(ll)i]++;
            // cout << mp2.sz() << '\n';
            // cout << -(2ll*a[i])+i << '\n';
            sm += (ll) a[i];
        }
    }
    ii ind = {-1,-1};
    auto rnd = (n%2) ? n : n-1;
    ll ans = rnd-1;
    for1n(i, n) {
        // cout << i << ' ' << mp2.sz() << ' ' << mp2.begin()->f << '\n'
        if(i%2 == 1) {
            // cout << mp.begin()->f << ' ' << ((2ll*a[i])+(ll)i) << ' ' << ans << '\n';
            if(mp.sz() != 0) ans = max(ans, mp.begin()->f-((2ll*a[i])+(ll)i));
            // cout << ans << '\n';
            ll st = (-(2ll*a[i]))+(ll)i;
            mp2[st]--;
            if(mp2[st] == 0) mp2.erase(st);
        } else {
            if(mp2.sz() != 0) ans = max(ans, mp2.begin()->f+((2ll*a[i])-(ll)i));

            ll st = (2ll*a[i])+(ll)i;
            mp[st]--;
            if(mp[st] == 0) mp.erase(st);
        }
        // cout << ans << ' ';
    }
    ll ret = ans + sm;
    // cout << ans << ' ' << ' ' << sm << ' ' << '\n';
    cout << ret << '\n';
}

int main() {
    //Sublime
    // init();
    // FASTIO;

    int t;
    cin >> t;
    while(t--) solve();
}

// 