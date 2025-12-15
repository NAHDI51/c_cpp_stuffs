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
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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

ll dp[52][19][19][19][2];
int vis[52][19][19][19][2];
ll lim;
ll cur;

ll count(int pos, int c1, int c2, int c3, int tight, string& s) {
    if(pos == -1) {
        return (c1 > 0 && c1 == c2 && c2 == c3);
    }
    auto& ret = dp[pos][c1][c2][c3][tight];
    if(c1 >= lim || c2 >= lim || c3 >= lim) {
        ret = 0;
        return ret;
    }
    if(vis[pos][c1][c2][c3][tight] == cur) {
        return ret;
    }
    vis[pos][c1][c2][c3][tight] = cur;

    ret = 0;
    int lim = (tight) ? s[pos]-'0' : 9;

    for(int i = 0; i <= lim; i++) {
        ret += count(pos-1, c1+(i==3), c2+(i==6), c3+(i==9), tight && (i == lim), s);
        ret %= mod;
    }
    // cout << ret << ' ' << pos << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << tight << '\n';
    return ret;
}

void clear() {
    forn(i, 52) {
        forn(j, 19) {
            forn(k, 19) {
                forn(l, 19) {
                    forn(m, 2) {
                        dp[i][j][k][l][m] = -1;
                    }
                }
            }
        }
    }
}

bool oknum(string& s) {
    int c1, c2, c3;
    c1 = c2 = c3 = 0;
    forn(i, s.sz()) {
        if(s[i] == '3') c1++;
        if(s[i] == '6') c2++;
        if(s[i] == '9') c3++;
    }
    return(c1 > 0 && c1 == c2 && c2 == c3);
}

void solve() {
    string a, b;
    cin >> a >> b;

    reverse(all(a));
    reverse(all(b));

    // clear();
    lim = b.sz()/3+1;
    cur++;
    ll c1 = count(b.sz()-1, 0,0,0,1, b);

    // clear();
    lim = a.sz()/3+1;
    cur++;
    ll c2 = count(a.sz()-1, 0,0,0,1, a) - oknum(a);
    ll ans = c1 - c2;
    if(ans < 0) ans += mod;

    // cout << c1 << ' ' << c2 << ' ';
    cout << ans << '\n';
}

int main() {
    //Sublime
    // init();
    FASTIO;

    cur = 0;
    int t;
    cin >> t;
    while(t--) solve();
}

