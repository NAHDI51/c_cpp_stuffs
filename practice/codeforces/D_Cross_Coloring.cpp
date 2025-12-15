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
#define maxN 
 
#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)
 
#define MAX 1000000000
#define MIN -MAX
 
#define clr(x, y) memset(x, y, sizeof(x))
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
 
#define mod 998244353LL
 
ll modpow(ll a, ll b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
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
 
void solve() {
    int n,m, Q;
    ll k;
    cin >> n >> m >> k >> Q;
    
    set<int> r, c;
    vi cq(Q), rq(Q);
    forn(i, Q) cin >> rq[i] >> cq[i];
    reverse(all(rq)), reverse(all(cq));

    int ans = 0;
    forn(i, Q) {
        //If the row has already been used, or out of space. Similarly, if the column has already
        //Been used or out of space.
 
        bool ok = false;
        //if(r.find(rq[i]) == r.end()) ok = true, r.ins(rq[i]);
        if(!r.count(rq[i])) ok = true, r.ins(rq[i]);
        //if(c.find(cq[i]) == c.end()) ok = true, c.ins(cq[i]);
        if(!c.count(cq[i])) ok = true, c.ins(cq[i]);
        if(ok) ans++;
        if(c.sz() == m || r.sz() == n) break;
    }
    cout << modpow(k, ans) << '\n';
}
 
int main() {
    int t;
    cin >> t;
    while((t--)) {
        solve();
    }
 
}