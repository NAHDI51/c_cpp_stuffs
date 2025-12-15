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

#define maxN 200005 

int spf[maxN];

void sieve() {
    forn(i, maxN) spf[i] = 0;
    spf[1] = 0, spf[0] = 0;
    for(int i = 2; i < maxN; i++) {
        if(spf[i] == 0) {
            for(int j = i; j < maxN; j += i) {
                if(spf[j] == 0) spf[j] = i;
            }
        }
    }
}


class stree {
    int n;
    vi seg;
    public: 
    stree(int n) {
        this->n = n;
        seg.rsz(2*n);
    }
    void upd(int i, int val) {
        i += n;
        seg[i] = val;
        for(i >>= 1; i >= 1; i >>= 1)
            seg[i] = max(seg[i*2], seg[i*2+1]);
    }
    int sm(int a, int b) {
        a += n, b += n;
        int sm = 0;

        while(a <= b) {
            if(a%2 == 1) sm = max(sm, seg[a++]);
            if(b%2 == 0) sm = max(sm, seg[b--]);

            a >>= 1, b >>= 1;
        }
        return sm;
    }
};

vi occ;
vi cnt;
stree seg(0);

void getDiv(int num, vpi& fac, int cur) {
    if(cur == fac.sz()) {
        // count occurance can be done in that way.
        if(num != 1) {
            cnt[occ[num]]--;
            if(cnt[occ[num]] == 0) {
                seg.upd(occ[num], 0);
            }
            occ[num]++;
            cnt[occ[num]]++;
            if(cnt[occ[num]] == 1) {
                seg.upd(occ[num], occ[num]);
            }
        }
        return;
    }
    forn(i, fac[cur].s+1) {
        getDiv(num*(binpow(fac[cur].f, i)), fac, cur+1);
    }
}

void fac(int n) {
    vpi fac;
    while(n != 1) {
        int cur = spf[n];
        int cnt = 0;
        while(spf[n] == cur) cnt++, n /= spf[n];
        fac.pb({cur, cnt});
    }
    getDiv(1, fac, 0);
    
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];

    occ = vi(n+1);
    cnt = vi(n+1);
    seg = stree(n+1);

    forn(i, n) {
        fac(a[i]);
        cout << seg.sm(0, i) << ' ';
    }
    cout << '\n';
}

int main() {
    //Sublime
    // init();
    // FASTIO;

    sieve();
    int t;
    cin >> t;
    while(t--) solve();
}

