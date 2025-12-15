#include <bits/stdc++.h>
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


ll nCr(ll n, ll r) {
    ll ans = 1;
    r = min(r, n-r);

    for(int j = 1; j <= r; j++, n--) {
        if(!(n%j)) ans *= n/j;
        else if(!(ans%j)) ans = (ans/j) * n;
        else ans = (ans*n)/j;
        ans %= mod;
    }
    return ans;
}

vi fact(ll n) {
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

#define maxN 100000

int best = 0;
vi a;
int n;

int cnt(int l, int r) {
    int cur = 0;
    fore(i, l, r) if(abs(a[i]) == 2) cur++;
    return cur;
}

ii f(ii ans, int x, int y) {
    ii cur = ans;
    int fst = -1, lst = -1;
    bool sign = false;

    fore(i, x, y) {
        if(a[i] < 0) {
            sign ^= 1;
            if(fst == -1) fst = i;
            lst = i;
        }
    }
    int curc = cnt(x, y);
    if(sign) {
        int xc = cnt(x, fst);
        int yc = cnt(lst, y);

        if(best <= curc - xc) {
            best = curc-xc;
            cur = {fst+1, n-y-1};
        }
        if(best <= curc-yc) {
            best = curc-yc;
            cur = {x, n-lst};
        }
    } else {
        if(best <= curc) {
            best = curc;
            cur = {x, n-y-1};
        }
    }
    return cur;
}

void solve() {
    best = 0;
    cin >> n;
    a = vi(n);
    forn(i, n) cin >> a[i];

    deque<int> dq;
    dq.pb(-1);
    forn(i, n) if(a[i] == 0) dq.pb(i);
    dq.pb(n);

    int x;
    int y = dq.front(); dq.pop_front();

    ii ans;
    while(!dq.empty()) {
        x = y;
        if(!dq.empty()) y = dq.front(), dq.pop_front();
        ans = f(ans, x+1, y-1);
    }
    cout << ans.f << ' ' << ans.s << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}

