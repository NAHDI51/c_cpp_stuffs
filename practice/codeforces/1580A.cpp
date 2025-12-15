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

#define mod 1000000007LL

ll modpow(ll a, ll b) {
    ll sm = 1;
    while(b) {
        if(b&1) sm *= b, sm %= mod;
        a *= a, a &= mod;
        b >>= 1;
    }
    return sm;
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

void init() {
   FASTIO;
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
}

/*
Why tf does a 1700 problem feel so tough T____T
Maybe I've grown old and noob after all.

*/

void solve() {
    int n, m;
    cin >> n >> m;

    vs a(n, string(m, '0'));
    forn(i, n) forn(j, m) cin >> a[i][j];

    vii rs(n, vi(m)), cs(n, vi(m)), pref(n, vi(m));

    forn(i, n) {
        cs[i][0] = (a[i][0]-48);
        for1n(j, m-1) cs[i][j] = cs[i][j-1]+(a[i][j]-48);
    }
    forn(i, m) {
        rs[0][i] = (a[0][i]-48);
        for1n(j, n-1) rs[j][i] = rs[j-1][i]+(a[j][i]-48);
    }


    pref[0][0] = (a[0][0]-48);
    for1n(i, n-1) pref[i][0] = pref[i-1][0] + (a[i][0]-48);
    for1n(i, m-1) pref[0][i] = pref[0][i-1] + (a[0][i]-48);
    for1n(i, n-1) for1n(j, m-1) pref[i][j] = (a[i][j]-48) + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];

    auto smc = [&](int i, int r, int l) -> int{
        return cs[i][r] - cs[i][l-1];
    };
    auto smr = [&] (int i, int r, int l) -> int {
        return rs[r][i] - rs[l-1][i];
    };
    auto sm3 = [&](int l, int r, int x, int y) -> int {
        return pref[l][r] - pref[x-1][r] - pref[l][y-1] + pref[x-1][y-1];
    };

    int ans = MAX;
    
    for(int i = 0; i < n; i++) {
        for(int j = i+4; j < n; j++) {
            //smr will require subtraction. Which is j-1-i-1+1 = (j-i-1) * 2
            //smc will require subtraction, which is basically 2*2 in this case.

            int best = sm3(j-1, 2, i+1, 1) - smr(0, j-1, i+1) - smr(3, j-1, i+1) - smc(i, 2, 1) - smc(j, 2, 1) 
                + ((j-i-1) << 1) + 4;

            ans = min(ans, best);

            for(int k = 4; k < m; k++) {
                //Two candidates, one calculates the smallest rectangle yet, one creates the lowest rectangle from the existing.
                int one = sm3(j-1, k-1, i+1, k-2) - smr(k-3, j-1, i+1) - smr(k, j-1, i+1) - smc(i, k-1, k-2)
                        - smc(j, k-1, k-2) + ((j-i-1) << 1) + 4;

                //undo the last column, add the latest column
                int two = best + (2*smr(k-1, j-1, i+1)) + !(a[j][k-1]-48) + !(a[i][k-1]-48) - smr(k, j-1, i+1);

                best = min(one, two);
                ans = min(ans, best);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
   init();

    int t;
    cin >> t;
    while((t--)) {
        solve();
    }

}

