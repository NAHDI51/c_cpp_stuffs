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

#define MAX 10000000000000ll
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

class segment_tree {
    int n;
    vpl seg;
    public: 
    segment_tree(int n) {
        this->n = n;
        seg.rsz(2*n, {MAX, 0});
    }
    void upd(int i, pair<ll,ll> val) {
        i += n;
        seg[i] = val;
        for(i >>= 1; i >= 1; i >>= 1) {
            if(seg[i].f == seg[i*2].f) {
                seg[i].s += seg[i*2].f;
            }
            if(seg[i].f == seg[i*2+1].f) {
                seg[i].s += seg[i*2+1].s;
            }
            if(seg[i].f > seg[i*2].f || seg[i].f > seg[i*2+1].f) {
                seg[i].f = min(seg[i*2].f, seg[i*2+1].f);
                seg[i].s = 0;

                if(seg[i].f == seg[i*2].f) {
                    seg[i].s += seg[i*2].f;
                }
                if(seg[i].f == seg[i*2+1].f) {
                    seg[i].s += seg[i*2+1].s;
                }
            }
            seg[i].s %= mod;
        }
    }
    pll sm(int a, int b) {
        a += n, b += n;
        pll sm = {MAX,0};

        while(a <= b) {
            if(a%2 == 1){
                if(sm.f == seg[a].f) {
                    sm.s += seg[a].s;
                } else if(sm.f > seg[a].f) {
                    sm = seg[a];
                }
                a++;
            }
            if(b%2 == 0) {
                if(sm.f == seg[b].f) {
                    sm.s += seg[b].s;
                } else if(sm.f > seg[b].f) {
                    sm = seg[b];
                }
                b--;
            }
            sm.s %= mod;
            a >>= 1, b >>= 1;
        }
        return sm;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    ll mx = 0;
    vll a(n+1), b(m+1);
    for1n(i, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
        a[i] += a[i-1];
    }
    for1n(i, m) cin >> b[i];
    if(mx > b[1]) {
        cout << -1 << '\n';
        return;
    }

    auto psm = [&] (int l, int r) -> ll {
        return a[r] - a[l-1];
    };
    // sort(all(b));
    auto get = [&](int r, int req) -> int {
        int lo = 1, hi = r;
        int ans = -1;
        while(lo <= hi) {
            // cout << lo << ' ' << hi << '\n';
            int m = lo + (hi-lo) / 2;
            if(psm(m,r) <= req) ans = m, hi = m-1;
            else lo = m+1;
        }
        return ans;
    };

    vpll dp(n+1, vpl(m+1, {MAX,0}));
    vpl dpmn(n+1, {MAX,0});

    segment_tree tr(n+1);
    dp[1][1] = {m-1,1};
    dpmn[1] = dp[1][1];
    tr.upd(1, dpmn[1]);
    tr.upd(0, {0,1});

    for(int i = 2; i <= n; i++) {
        auto c = get(i, b[1]);
        if(c != -1) {
            // cout << c << ' ' << i << ' ' << 1 <<' ' << tr.sm(c-1, i-1) << '\n';
            auto s = tr.sm(c-1, i-1);
            dp[i][1] = {s.f + (m-1), s.s};
            dpmn[i] = dp[i][1];
        }
        dpmn[i].s %= mod;
        tr.upd(i, dpmn[i]);
    }

    for(int j = 2; j <= m; j++) {
        for1n(i, n) {
            auto c = get(i, b[j]); 
            // if(c != -1) cout << c << ' ' << i << ' ' << b[j] << ' ' << psm(c, i) << '\n';
            if(c != -1) {
                // cout << c << ' ' << i << ' ' << j <<' ' << tr.sm(c, i-1) << '\n';
                auto s = tr.sm(c-1,i-1);
                if(dp[i][j].f == s.f+(m-j)) {
                    dp[i][j].s += s.s;
                } else if(dp[i][j].f > s.f+(m-j)) {
                    dp[i][j] = {s.f+(m-j), s.s};
                }
                if(dpmn[i].f == dp[i][j].f) {
                    dpmn[i].s += dp[i][j].s;
                } else if(dpmn[i].f > dp[i][j].f) {
                    dpmn[i] = dp[i][j];
                }
                dp[i][j] %= mod;
                dpmn[i] %= mod;
                tr.upd(i, dpmn[i]);
            }
        }
        // cout << '\n';
    }
    /*
    for1n(i, n) {
        for1n(j, m) {
            cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
        cout << '\n';
    }
    */
    cout << dpmn[n].f << ' ' << dpmn[n].s << '\n';
}

int main() {
    //Sublime
    // init();
    // FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

