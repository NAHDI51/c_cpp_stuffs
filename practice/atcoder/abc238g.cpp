#include <bits/stdc++.h>
using namespace std;

//#pragma gcc optimize("0fast")

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

int len;

struct query {
public:
int l, r, idx;
bool operator<(query& b) {
    auto a = *this;
    if(a.l/len == b.l/len) return (a.l/len & 1) ? a.r < b.r : a.r > b.r;
    return ii(a.l,a.r) < ii(b.l,b.r);
}
};

int n, m;
int a[maxN];
int cnt = 0;
int c[1000001];
int spf[1000001];
vi fact[1000001];
query q[maxN];
bool ans[maxN];

void add(int i) {
    for(auto x : fact[a[i]]) {
        c[x]++;
        if(c[x] > 2) c[x] -= 3;
        if(c[x] == 1) cnt++;
        else if(c[x] == 0) cnt--; 
    }
}

void rmv(int i) {
    for(auto x : fact[a[i]]) {
        c[x]--;
        if(c[x] < 0) c[x] += 3;
        if(c[x] == 2) cnt++;
        else if(c[x] == 0) cnt--;
    }
}

void mo() {
    forn(i, n) add(i);
    int l = 0, r = n-1;
    forn(i, m) {
        while(l < q[i].l) rmv(l++);
        while(l > q[i].l) add(--l);
        while(r > q[i].r) rmv(r--);
        while(r < q[i].r) add(++r);
        ans[q[i].idx] = (cnt == 0) ? 1 : 0;
    }
    forn(i, m) {
        if(ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}

void solve() {
    cin >> n >> m;
    len = sqrt(n+0.0)+1;
    forn(i, n) cin >> a[i];
    forn(i, m) {
        cin >> q[i].l >> q[i].r;
        q[i].l--, q[i].r--;
        q[i].idx = i;
    }
    sort(q, q+m);
    mo();
}

int main() {
    spf[1] = 1;
    for(int i = 2; i <= 1000000; i++) {
        if(spf[i] != 0) continue;
        for(int j = i; j <= 1000000; j += i) {
            if(spf[j] == 0) spf[j] = i;
        }
    }
    for(int i = 2; i <= 1000000; i++) {
        fact[i].reserve(100);
        for(int j = i; j != 1; j /= spf[j]) 
            fact[i].pb(spf[j]);
    }
    FASTIO;
    solve();
}
