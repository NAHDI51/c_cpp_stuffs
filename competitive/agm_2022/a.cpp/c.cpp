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
#define maxN 100000

#define lb(a, val) lower_bound(all(a), val);
#define ub(a, val) upper_bound(all(a), val);

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

//Perform dfs from each of the exit points of the level, in default it's {1,1}.
//We assume the next level will start in the same block as teleported.

void dfs(vii& a, vbb& vis, priority_queue<int, vi, greater<int>>& pq, int r, int c) {
    if(r == -1 || r == vis.sz() || c == vis[0].sz() || c == -1 || a[r][c] == -9) return;
    if(vis[r][c]) return;

    vis[r][c] = true;
    if(a[r][c] > 0) pq.push(a[r][c]);

    forn(i, 4) dfs(a, vis, pq, r+dx[i], c+dy[i]);
}

//What if we store the coordinates of the cells on the ascending order, then try to reach them out
/*
Store the coordinates of the monsters in ascending order.
See if it is reachable from the current position, where monster will become an obstacle
If sm < monster.
If yes, add sm, and continue your search
If no, pop the element.

Then check if you can reach the next level portal. If no, return, if yes, ascend to the next level.
*/

int sm;

void dfs(vii& a, vbb& vis, set<vi>& s, int r, int c) {
    if(r == -1 || r == vis.sz() || c == -1 || c == vis[0].sz() || a[r][c] == -9) return;
    if(vis[r][c]) return;
    if(a[r][c] > sm) {
        if(!s.count({a[r][c], r, c})) s.ins({a[r][c], r, c});
        return;
    }
    if(a[r][c] > 0) sm += a[r][c];

    vis[r][c] = true;
    forn(i, 4) dfs(a, vis, s, r+dx[i], c+dy[i]);
}

//For each of the monsters you could not defeat yet, store and try with them again.

void solve() {
    int n, m, q;
    cin >> q >> n >> m;

    vector<vector<vector<int>>> a(q, vii(n, vi(m)));
    forn(i, q) forn(j, n) forn(k, m) cin >> a[i][j][k];
    vpi pos(q);
    pos[0] = {0, 0};
    forn(i, q-1) forn(j, n) forn(k, m) if(a[i][j][k] == -1) pos[i+1] = {j, k};

    //dfs on the points.
    sm = 1;
    forn(t, q) {
        vbb vis(n, vb(m));
        set<vi> s;

        dfs(a[t], vis, s, pos[t].f, pos[t].s);

        while(!s.empty()) {
            if(!vis[(*s.begin())[1]][(*s.begin())[2]]) dfs(a[t], vis, s, (*s.begin())[1], (*s.begin())[2]);
            s.erase(s.begin());
        }   
        //if(t != q-1 && !vis[pos[t+1].f][pos[t+1].s]) break;
    }
    cout << sm << '\n';
}

int main() {
    solve();
}

