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

vi factorize(ll n) {
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

#define maxN 102 

vi adj[maxN];
//dp[i][j] total number of nodes with height j on the ith subtree
int dp[maxN][maxN];
void dfs(int u, int p, int i = 0, int j = 0) {
    if(p != -1) dp[i][j]++;
    for(int it = 0; it < adj[u].sz(); it++) {
        int v = adj[u][it];
        if(v == p) continue;
        if(p == -1) dfs(v, u, it, j+1);
        else dfs(v, u, i, j+1);
    }
}

//Counts the number of k length sequences.
ll f(vi& occ, int k) {
    ll len[k+1];
    clr(len, 0);
    len[0] = 1;
    //Take the total sequence of 1 less length, and insert it with the options we have.
    forn(i, occ.sz()) 
        for(int j = k; j >= 1; j--) 
            len[j] += (len[j-1]*occ[i] % mod), len[j] %= mod;
    
    return len[k];
}

void solve() {
    int n, k;
    cin >> n >> k;
    forn(i, n) adj[i] = vi{};

    forn(i,n-1) {
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1), adj[b-1].pb(a-1);
    }

    if(k == 2) {
        cout << n * (n-1) / 2 << '\n';
        return;
    }

    ll ans  = 0;
    //How many subtrees of each height when the root is i 
    forn(i, n) {
        clr(dp, 0);
        dfs(i, -1);

        //Subtrees of the same height
        forn(i, n) {
            //Count as the number of subsequences for the nodes with the same height.
            vi occ;
            forn(j, n) if(dp[j][i] != 0) occ.pb(dp[j][i]);
            ans += f(occ, k), ans %= mod;
        }
    }
    cout << ans << '\n';
    
}

int main() {
    //FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

