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
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
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


/*
dp[pos][inv][started][tight][cnt_state]
*/

#define ways first
#define inv second

using vll = vector<long long>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vvvvll = vector<vvvll>;
pll dp[16][150][2][2];
int n;

pll solve(vi cnt_st, int pos, int inv, int started, int tight, string& ss) {
    if(pos == -1) return {1, inv};
    if(dp[pos][inv][started][tight] != pll{-1,-1}) {
        return dp[pos][inv][started][tight];
    }
    auto& ret = dp[pos][inv][started][tight];
    ret = {0,0};

    int lim = (tight) ? (ss[pos]-'0') : 9;

    int inc = 0;
    for(int i = 0; i <= lim; i++) {
        int nstarted = (started || i > 0);
        int ntight = (tight && i == lim);
        int ninv = 0;
        for(int d = i-1; d >= 0; d--) ninv += cnt_st[d];
        int npos = pos-1;

        vi n_cnt_st = cnt_st;
        if(nstarted) n_cnt_st[i]++;
        else n_cnt_st = vi(10);

        if(nstarted && i == lim) {
            auto cur = solve(n_cnt_st, npos, ninv, nstarted, ntight, ss);
            ret.ways += cur.ways;
            ret.inv += cur.inv;
        } else if()

    }  
    
    
    forn(i, 10) cout << cnt_st[i] << ' ';
    cout << "  ";
    cout << ret.ways << ' ' << ret.inv << ' ' << ' ' << pos << ' ' << lim << ' ' << inv << ' ' << started << ' ' << tight << '\n';
    
    return ret;
}

void clear(int n) {
    forn(i, n+1) {
        forn(j, 150+1)
            forn(k, 2) forn(l, 2) dp[i][j][k][l] = {-1, -1};
        }
}

void solve() {
    ll l, r ;
    cin >> l >> r ;
    l--;

    auto sl = to_string(l);
    auto sr = to_string(r);

    n = sr.sz()+1;
    reverse(all(sl)), reverse(all(sr));

    vector<int> vr (10);
    clear(sr.sz()+1);
    auto [way1, cnt1] = solve(vr, sr.sz()-1, 0, 0, 1, sr);

    clear(sl.sz()+1);
    auto [way2, cnt2] = solve(vr, sl.sz()-1, 0, 0, 1, sl);
    cout << cnt1 << ' ' << cnt2 << ' ' << cnt1 - cnt2 << '\n';

    // cout << brute(r) << ' ' << brute(l) << ' ' << brute(r) - brute(l) << '\n';
}

int main() {
    //Sublime
    // init();
    FASTIO;
    int t;
    cin >> t;
    int cnt = 1;
    while(t--) {
        cout << "Case " << cnt++ << ": ";
        solve();
    }
}

