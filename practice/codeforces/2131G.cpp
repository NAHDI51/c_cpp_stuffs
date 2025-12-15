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

#define maxN 200

ll fact[maxN];
ll dp[maxN]; 

void fct() {
    fact[1] = 1;
    for(ll i=2; i < maxN; i++) {
       fact[i] = fact[i-1]*i;
       fact[i] %= mod;
       // cout << fact[i] << ' ';
    }
    // cout << '\n';
}

void calc() {
    dp[0] = 1;
    for(ll i = 1; i < maxN; i++) {
        dp[i] = i * binpow(dp[i-1],2);
        dp[i] %= mod;
        // cout << dp[i] << ' ';
    }
    // cout << '\n';
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vll a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));

    auto bits = [](ll n) -> string {
        string s;
        while(n) {
            s += (n&1) ? '1' : '0';
            n >>= 1;
        }
        return s;
    };

    ll ans = 1;
    forn(i, n) {
        if(k == 0) {
            cout << ans << '\n';
            return;
        }
        ans *= a[i];
        ans %= mod;
        k--;
        // cout << a[i] << ' ' << (binpow(2,a[i])-1) << '\n';
        if(a[i] > 30 || (binpow(2,a[i]-1)-1) > k) {
            
            break;
        }
        ans *= dp[a[i]-1];
        ans %= mod;
        k -= (binpow(2,a[i]-1)-1);
        // cout << a[i] << ' ' << k << ' ' << (binpow(2,a[i])-1) << '\n';
    }
    // cout << '\n';
    // cout <<"K: " << ans << ' ' << k << '\n';
    auto s = bits(k);
    // cout << s << '\n';
    if(s.sz() > 0) {
        // cout << s.sz()  << ' ' << s << '\n';
        for(ll i = s.sz()-1; i >= 0; i--) {
            // ll segs = ((ll) (i+1ll) * (dp[i])) % mod;
            if(s[i] == '1') ans *= ((i+1) * (dp[i]))%mod;
            ans %= mod;
            // cout << ans << '\n';
        }
    }
    cout << ans << '\n';
}

int main() {
    //Sublime
    // init();
    // FASTIO;
    fct();
    calc();

    int t;
    cin >> t;
    while(t--) solve();
}

