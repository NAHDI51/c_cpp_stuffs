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

string bits(ll x) {
    if(x < 0) return {};
    string s;
    while(x) {
        s += (x&1ll) ? '1' : '0';
        x >>= 1ll;
    }
    return s;
}

/*
void go(vvll& dp, string& s, int pos, bool tight) {
    if(pos == 0) {
        if(tight )
    }
}
    */



vector<ll> cbits(ll r) {
    if(r < 0) return {};
    vector<ll> d;
    for(ll i = 0; (1ll<<i) <= r; i++) {
        // Flag;
        // cout << i << 
        ll cyc = 1ll << (i+1);
        ll fll = (r+1) / cyc;
        ll rem = (r+1) % cyc;
        ll cnt = (fll * (1ll<<i)) + max(0ll, rem - (1ll<<i));
        d.pb(cnt);
    }
    return d;
}

void solve() {
    ll l, r ;
    cin >> l >> r;
    auto dr = cbits(r);
    auto dl = cbits(l-1);

    
    if(l == r) {
        cout << l << ' ' << r << ' ' << l << '\n';
        return;
    }
    
    string s = bits(l), t = bits(r);
    // cout << s << ' ' << t << '\n';
    ll andd = 0, orr = 0, xorr = 0;
    reverse(all(s)), reverse(all(t));
    if(s.sz() == t.sz()) {
        // Flag;
        for(ll i = 0; i <= s.sz()-1; i++) {
            // cout << andd << '\n';
            //Flag;
            // cout << s[i] << ' ' << t[i] << ' ' <<  i << '\n';
            if(s[i] == t[i]) {
                andd += (s[i] == '1') ? (1ll<<((ll)s.sz()-1ll-i)) : 0;
            }
            else {
                break;
            }
        }
    } else {
        andd = 0;
    }
    /*    
    cout << r << '\n';
    forn(i, dr.sz()) {
        cout << i << ' ' << dr[i] << '\n';
    }
    cout << '\n';
    forn(i, dl.sz()) {
        cout << i << ' ' << dl[i] << '\n';
    }
    cout << '\n';
    */
   ll ind = 0;
   for(ll i = 0; i < min(dl.sz(), dr.sz()); i++) {
        ll sz = dr[i] - dl[i];
        if(sz > 0) {
            orr += (1ll<<i);
        }
        if(sz > 0 && sz%2) {
            xorr += (1ll<<i);
        }
        ind++;
   }
   for(int i = ind; i < dr.sz(); i++) {
        ll sz = dr[i];
        if(sz>0) {
            orr += (1ll<<i);
        }
        if(sz > 0 && sz%2) {
            xorr += (1ll<<i);
        }
   }
   cout << andd << ' ' << orr << ' ' << xorr << '\n';
}

int main() {
    //Sublime
    // init();
    FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

