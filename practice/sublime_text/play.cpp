#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

#define maxN 1010

ll pref[maxN][maxN];

ll sum(int hs, int hb, int ws, int wb) {
    return pref[hb][wb]-pref[hb][ws-1]-pref[hs-1][wb]+pref[hs-1][ws-1];
}

void solve() {
    ll n, qu;
    cin >> n >> qu;
    vpl a(n+1);
    vvll q(qu+1);
    ll mxx = 0, mxy = 0;

    for1n(i, n) {
        ll x,y;
        cin >> x >> y;
        a[i] = {x,y};
        mxx = max(mxx,x), mxy = max(mxy,y);
    }
    for1n(i, qu) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        q[i] = {x1,y1,x2,y2};
        mxx = max(mxx, x2), mxy = max(mxy, y2);
    }
    forn(i, mxx+2) forn(j, mxy+2) pref[i][j] = 0;
    for1n(i, n) pref[a[i].f][a[i].s] += (a[i].f*a[i].s);
    for1n(i, mxx+1) for1n(j, mxy+1) pref[i][j] += pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
    for1n(i, qu) cout << sum(q[i][0]+1, q[i][2]-1, q[i][1]+1, q[i][3]-1) << '\n';
}

int main() {
    //Sublime
    init();
    FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

