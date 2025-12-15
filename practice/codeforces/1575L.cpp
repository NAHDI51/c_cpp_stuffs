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

#define MN 200002
ll N;
pll A[MN];
int BIT[MN];
void upd(int idx, const int val) {
    for (; idx<MN; idx+=(idx&-idx)) BIT[idx] = max(BIT[idx], val);
}
int query(int idx) {
    int ret = 0;
    for (; idx>0; idx-=(idx&-idx)) ret = max(ret, BIT[idx]);
    return ret;
}
 
void solve() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> A[i].f;
        --A[i].f;
        A[i].s = i;
    }
    sort(A, A+N, [](const pll& a, const pll& b) {
        return a.f < b.f || (a.f == b.f && a.s > b.s);
    });
 
    int ans = 0;
    for (int i=0; i<N; ++i) {
        const int val = A[i].f;
        const int idx = A[i].s;
        if (idx < val) {
            continue;
        }
 
        const int new_val = query(idx - val + 1) + 1;
        upd(idx - val + 1, new_val);
        ans = max(ans, new_val);
        //cout << A[i].f+1 << ' ' << A[i].s+1 << '\n';
    }
 
    cout << ans << '\n';
}

int main() {
    FASTIO;
    solve();
}

