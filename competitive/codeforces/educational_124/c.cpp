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
#define maxN 100000

#define lb(a, val) lower_bound(all(a), val);
#define ub(a, val) upper_bound(all(a), val);

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 100000000000LL
#define MIN -MAX

#define clr(x, y) memset(x, y, sizeof(x))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

#define mod 1000000007LL

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

int gcd(int a, int b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

/*
1/4. 2/3 only 2 wired connections. 
1/2, 1/3, 3/4, 2/4 are the only 3 wired connections. 
*/

ll ck(int x, vll& a, vll& b) {
    ll mn = MAX;
    forn(i,a.sz()) mn = min(mn, abs(a[x]-b[i]));
    return mn;
}

void solve() {
    int n;;
    cin >> n;

    vll a(n), b(n);
    forn(i,n)cin >> a[i];
    forn(i, n) cin >> b[i];

    ll one, two , thr, four;
    one = abs(a[0]-b[0]), two = abs(a[0]-b[n-1]);
    thr = abs(a[n-1]-b[0]), four = abs(a[n-1]-b[n-1]);

    ll a1 = ck(0,a,b), a2 = ck(n-1,a,b);
    ll b1 = ck(0,b,a), b2 = ck(n-1,b,a);

    auto mn = MAX;
    mn = min(initializer_list<ll>{
        one+four, two+thr, one+two+a2, one+thr+b2, 
        thr+four+a1, two+four+b1, a1+a2+b1+b2,
        one+a2+b2, four+a1+b1, two+a2+b1, thr+a1+b2
    });
    cout << mn << '\n';
}

//g++ -std=c++11 c.cpp -o c

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}

