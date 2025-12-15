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

#define mod 998244353LL
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

lll gcd(lll a, lll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

lll lcm(lll a, lll b, lll lim) {
    lll ret = a*b / gcd(a,b);
    if(ret > lim) return -1;
    else return ret;
}

#define maxN 

void go(int num, int cur, vi& cr, vpi& divs, map<int,vi>& dvs) {
    if(cur == divs.sz()) {
        dvs[num] = cr;
        return;
    }
    for(int i = 0; i <= divs[cur].s; i++) {
        if(i == 0) {
            go(num, cur+1, cr, divs, dvs);
        }
        else {
            cr.pb(divs[cur].f);
            go(num * (int)pow(divs[cur].f, i), cur+1, cr, divs, dvs);
            cr.pbb();
        }
    }
}

void getDiv(int n, map<int,vi>& dvs) {
    vpi pr;
    for(int i = 2; i*i <= n; i++) {
        int cnt = 0;
        while(n%i == 0) {
            cnt++;
            n /= i;
        }
        pr.pb({i, cnt});
    }
    if(n > 1) pr.pb({n, 1});
    vi cr;
    go(1, 0, cr, pr, dvs);
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vll a(n);
    forn(i, n) cin >> a[i];

    forn(i, n-1) {
        if(a[i] % a[i+1]) {
            cout << 0 << '\n';
            return;
        }
    }
    map<int,vi> dvs;
    getDiv(a[0], dvs);

    auto count = [&](int d, int n) -> ll {
        auto cur = dvs[d];

        int cnt = 0;
        for(int i = 1; i < (1<<cur.sz()); i++) {
            int cl = 1, bits = 0;
            forn(j, cur.sz()) {
                if(i&(1<<j)) {
                    cl *= cur[j];
                    bits++;
                }
            }
            if(bits%2) cnt += (n/cl);
            else cnt -= (n/cl);
        }
        return n - cnt;
    };
    // for(auto [x,y] : dvs) {
    //     cout << x << "  ";
    //     for(auto z : y) cout << z << ' ';
    //     cout << '\n';
    // }

    ll ans = 1;
    // cout << ans << '\n';
    for(int i = 1; i < n; i++) {
        ll rn = count(a[i-1] / a[i], m / a[i]);
        ans *= rn;
        ans %= mod;
    }
    cout << ans << '\n';
}

int main() {
    //Sublime
    // init();
    // FASTIO;

    int t;
    cin >> t;
    while(t--) solve();
}

