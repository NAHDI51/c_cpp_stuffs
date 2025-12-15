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

#define maxN (1<<18)

/*
1^0 = 0^1 = 1
1^1 = 0^0 = 0
*/

//Goes from most significatnt to the least significant bit. 
int a[maxN];
class trie {
vector<array<int,2>> t;
int sz;
int bt;
public:
trie(int n, int k) {
    t.pb({-1,-1});
    sz = 0; 
    bt = k;
}
void add(int a) {
    int v = 0;
    for(int i = bt; i >= 0; i--) {
        int c = a&(1<<i) ? 1 : 0;
        if(t[v][c] == -1) t[v][c] = ++sz, t.pb({-1,-1});
        v = t[v][c];
    }
}
//MinMax value of a[i]^x 
int q(int x, bool ok) {
    int v = 0;
    int ans = 0;
    for(int i = bt; i >= 0; i--) {
        int c = (x&(1<<i)) ? 1 : 0;
        if(t[v][0] == -1) v = t[v][1], ans += (c^1) ? (1<<i) : 0;
        else if(t[v][1] == -1) v = t[v][0], ans += (c^0) ? (1<<i) : 0;
        else {
            if(ok) v = t[v][!c], ans += (1<<i);
            else v = t[v][c];
        }
    }
    //cout << '\n';
    return ans;
}
};

void solve() {
    int l, r;
    cin >> l >> r;
    int n = r-l+1;
    int c = 17;
    forn(i, n) cin >> a[i];

    if(r-l == 0) {
        cout << (l^a[0]) << '\n';
        return;
    }
    while((r&(1<<c)) == 0) c--; 
    trie tr(n,c+1);
    forn(i, n) tr.add(a[i]);
    int ans = MAX;
    forn(i, n) {
        int x = l^a[i];
        if(tr.q(x, 0) == l && tr.q(x, 1) == r) ans = min(ans, x);
    }
    cout << ans << '\n';
}

int main() {
    FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

