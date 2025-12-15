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
    ll k;
    cin >> k;

    auto dsm = [](ll l, ll r) -> ll {
        return (r-l+1) * (ll) (to_string(r).length());
    };
    auto qrsm = [](ll n) -> ll {
        ll ans = 0;
        ll po = 1;
        ll nm = n;
        while(n) {
            ll tm = n/10;
            ll rem = n%10;
            ll s1 = rem*(rem-1)/2;
            ll past = (nm%po)+1ll;
            ans += (tm*45ll)*po + (s1)*(po) + (rem * past);
            po *= 10;
            n /= 10;
        }
        return ans;
    };
    auto rsm = [&](ll l, ll r) -> ll{
        return qrsm(r) - qrsm(l-1);
    };
    ll sm = 0;
    ll i = 0;
    while(k) {
        ll lo = pow(10, i), hi = pow(10,i+1)-1;
        ll cnt = dsm(lo,hi);
        if(cnt <= k) {
            sm += rsm(lo,hi);
            k -= cnt;
        } else {
            auto l = lo;
            while(lo < hi) {
                ll mid = lo + (hi-lo) / 2;
                if(dsm(l,mid) > k) hi = mid;
                else lo = mid+1;
            }
            sm += rsm(l,lo-1);
            k -= dsm(l,lo-1);
            auto c = to_string(lo);
            // cout << k << ' ' << l << ' ' << lo << '\n';
            int ind = 0;
            while(k) {
                // Flag;
                sm += c[ind]-'0';
                ind++;
                k--;
            }
        }
        i++;
    }
    cout << sm << '\n';
}

int main() {
    //Sublime
    // init();
    // FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

