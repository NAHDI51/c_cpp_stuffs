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

#define MAX 10000000000000000LL
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

#define maxN 5002

ll dp[maxN][maxN][2];

void solve() {
    ll x, y;
    int n;
    cin >> n >> x >> y;
    for1n(i, n) forn(j, n+1) forn(k, 2) dp[i][j][k] = MAX;

    string as,bs;
    cin >> as >> bs;
    vector<bool> a(n+1), b(n+1), c(n+1);

    for1n(i, n) a[i] = as[i-1]-'0', b[i] = bs[i-1]-'0';
    for1n(i, n) c[i] = a[i]^b[i];
    int cnt = 0;
    for1n(i, n) cnt += c[i];

    if(cnt %2) {
        cout << -1 << '\n';
        return;
    }

    dp[1][c[1]][c[1]] = 0;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            //Don't change
            if(c[i] == 1 && j > 0) dp[i][j][1] = min({dp[i][j][1], dp[i-1][j-1][0], dp[i-1][j-1][1]});
            else if(c[i] == 0) dp[i][j][0] = min({dp[i][j][0], dp[i-1][j][0], dp[i-1][j][1]});

            //change with the last
            if(c[i] == 1) {
                if(j < n) dp[i][j][0] = min(dp[i][j][0], dp[i-1][j+1][1]+x);
                if(0 < j) dp[i][j][0] = min(dp[i][j][0], dp[i-1][j-1][0]+x);
            } else {
                dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][1]+x);
                if(1 < j) dp[i][j][1] = min(dp[i][j][1], dp[i-1][j-2][0]+x);
            }
            //Change with anything else
            if(c[i] == 1) {
                //1 changing to 0
                if(j < n) dp[i][j][0] = min(dp[i][j][0], dp[i-1][j+1][0]+y);
                //0 changing to 1.
                if(0 < j) dp[i][j][0] = min(dp[i][j][0], dp[i-1][j-1][1]+y);
            } else {
                dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][0]+y);
                if(1 < j) dp[i][j][1] = min(dp[i][j][1], dp[i-1][j-2][1]+y);
            }
            /*
            if(dp[i][j][0] == MAX) cout << "Bad" << '\n';
            else cout << i << ' ' << j << ' ' << "0" << ' ' << dp[i][j][0] << '\n';
            if(dp[i][j][1] == MAX) cout << "Bad" << '\n';
            else cout << i << ' ' << j << ' ' << "1" << ' ' << dp[i][j][1] << '\n';
            */
        }
        //cout << '\n';
    }
    cout << dp[n][0][0] << '\n';
}

int main() {
    //Sublime
    init();
    FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}



