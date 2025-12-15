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

#define MAX 1000000005
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

void solve() {
    int n, m;
    cin >> m >> n;

    vii a(m, vi(n));
    forn(i, m) forn(j, n) cin >> a[i][j];

    /*
    WE add the row to our list iff we can add at least one new element to the list
    satisfying the criteria. but first, we need to check if we can add two elements 
    to the list with some number of the array, because the constraint is n-1.
    */
    auto ok = [&] (int mid) -> bool {
        vi cnt(m);
        forn(i, m) forn(j, n)  if(a[i][j] >= mid) cnt[i]++;

        bool okay = false;
        int val;
        forn(i, m) {
            if(cnt[i] > 1) okay = true, val = i;
        }
        if(!okay) return false;

        vb req(n);
        forn(i, n) if(a[val][i] >= mid) req[i] = true;

        //Now check if any new numbers satisfied the requirements.
        int shops = 1, t = cnt[val];
        forn(i, m) {            
            forn(j, n) {
                if(!req[j] && a[i][j] >= mid) shops++, t++, req[j] = true;
            }
        }
        if(t == n) return true;
        else return false;
    };

    int l = -1, r = 1e9+1;
    while(r-l > 1) {
        int m = (r+l)/2;
        if(ok(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}

