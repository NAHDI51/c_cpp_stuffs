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

int dp[524290]{};
vii adj(524290);

void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;

    int sm = 1<<(k-1), c=0;

    for1n(i, k) {
        if(i == 1) continue;
        forn(j, 1<<(k-i)) {
            adj[sm+j].pb(c), adj[sm+j].pb(c+1);
            adj[c].pb(sm+j), adj[c+1].pb(sm+j);
            c += 2;
        }
        sm += (1<<(k-i));
    }
    forn(i, 1<<(k-1)) {
        if(s[i] == '?') dp[i] = 2;
        else dp[i] = 1;
    }
    for(int i = 1<<(k-1); i < (1<<k)-1; i++) {
        if(s[i] == '0') dp[i] = dp[adj[i][0]];
        else if(s[i] == '1') dp[i] = dp[adj[i][1]];
        else dp[i] = dp[adj[i][0]]+dp[adj[i][1]];

        //cout << i << "  " << adj[i][0] << ' ' << adj[i][1] << ' ' << adj[i].back() << ' ' << '\n';
    }
    auto add = [&](int i, char c) -> void {
        s[i] = c;
        if(i < (1<<(k-1))) {
            if(s[i] == '?') dp[i] = 2;
            else dp[i] = 1;
            i = adj[i].back();
        }
        int p_i = i;
        while(p_i <= i) {
            //cout << i << "  ";
            p_i = i;
            if(s[i] == '?') {
                //cout << 1 << ' ';
                dp[i] = dp[adj[i][0]]+dp[adj[i][1]];
            }
            else if(s[i] == '0') {
                //cout << 2 << ' ';
                dp[i] = dp[adj[i][0]];
            }
            else {
                //cout << 3 << ' ';
                dp[i] = dp[adj[i][1]];
            }
            i = adj[i].back();
        }
        //cout << '\n';
    }; 

    int q;
    cin >> q;
    forn(i, q) {
        int t;
        char c;
        cin >> t >> c;
        if(k == 1) {
            if(c == '?') cout << 2 << '\n';
            else cout << 1 << '\n';
        }
        else {
            add(t-1, c);
            cout << dp[(1<<k)-2] << '\n';
        }
    }
}

int main() {
    solve();
}

