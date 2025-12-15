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

#define maxN 400001

/*
Keeping it as map?
*/
vector<unordered_map<int, int>> adj;

void solve() {
    int n, k;
    cin >> n >> k;

    adj.rsz(n);
    forn(i, n) adj[i].clear();

    forn(i, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a-1][b-1] = true, adj[b-1][a-1] = true;
    }

    queue<int> q;
    vi ans(n, MIN);
    vb vis(n);

    forn(i, n) {
        if(adj[i].sz() == 1) {
            q.push(i), ans[i] = 1;
            vis[i] = true;
        }
        /*
        cout << i << "  ";
        for(auto x : adj[i]) cout << x.first << ' ';
        cout << '\n';
        */
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        auto v = adj[u].begin()->first;
        
        if(!vis[v]) {
            adj[v].erase(u);
            ans[v] = max(ans[v], ans[u]+1);

            if(adj[v].sz() == 1) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    int t = 0;
    
    forn(i, n) {
        //cout << ans[i] << ' ';
        if(ans[i] > k) t++;
    }
    
    //cout << '\n';
    cout << t << '\n';

}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}

