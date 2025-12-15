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

ll m, d;
ll binpow(ll a, ll b) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a, res %= m;
        a *= a, a %= m;
        b >>= 1;
    }
    res %= m;
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
ll dp[2002][2002][2][3];

ll count(int pos, ll rem, bool tight, int oe, string& s) {
    if(pos == -1) return oe > 0 && rem == 0;
    auto& ret = dp[pos][rem][tight][oe];
    if(ret != -1) return ret;

    ret = 0;
    int lim = tight ? s[pos]-'0' : 9;

    for(ll i = 0; i <= lim; i++) {
        int noe = oe;
        if(!oe && i > 0) noe++;
        if(oe == 1) noe = 2;
        else if(oe == 2) noe = 1;

        if(oe == 1 && i != d) continue;
        if(oe == 2 && i == d) continue;

        bool ntight = tight && i == lim;
        int npos = pos-1;
        ll nrem = (rem + (i * binpow(10ll, pos))%m)%m;

        ret += count(npos, nrem, ntight, noe, s);
        ret %= mod;
    }
    // cout << ret << ' ' << pos << ' ' << rem << ' ' << started << ' ' << tight << '\n';
    return ret;
}

ll inter(string& a) {
    reverse(all(a));
    memset(dp, -1, sizeof(dp));
    return count(a.sz()-1, 0, 1, 0, a);
}

bool oknum(string& a) {
    bool ok = true;
    ll rem = 0;
    for(ll i = 0; i < a.sz(); i++) {
        ll cur = a[i]-'0';
        if(i%2 && cur != d) {
            return false;
        }
        if(i%2 == 0 && cur == d) {
            return false;
        }
        rem += cur * binpow(10ll, i);
        rem %= m;
    }
    return rem == 0;
}

void solve() {
    cin >> m >> d;
    string a, b;
    cin >> a >> b;

    ll c2 = -oknum(a);
    c2 += inter(a);
    ll c1 = inter(b);
    ll ans = c1 - c2;
    if(ans < 0) ans += mod;

    // cout << c1 << ' ' << c2 << '\n';
    cout << ans << '\n';
}

int main() {
    //Sublime
    // init();
    FASTIO;

    solve();
}

