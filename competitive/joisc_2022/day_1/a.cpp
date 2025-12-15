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
#define maxN 50000

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


/*
If it bidirectionally overlaps, we can return no. Otherwise, we can sort them based on preceding,
Both forward and reverse directions, then check if it overlaps.

Add the intervals of fd in a fenwick tree range query, and then check for each rd, if the sum if bigger
than 0. If it is, then return no.
*/

struct ftree {
vll bit;
int n;
public:
ftree() {
    bit.rsz(120002), n = 120002;
}
void update(int i, ll val) {
    for(; i < n; i += (i&-i)) bit[i] += val;
}
int query(int i) {
    ll sm = 0;
    for(; i >= 1; i -= (i&-i)) sm += bit[i];
    return sm;
}
int query(int l, int r) {
    return query(r) - query(l-1);
}
};

struct rtree {
ftree B1, B2; 

public:
rtree(){}
void add(int l, int r, int x) {
    B1.update(l, x);
    B1.update(r+1, -x);
    B2.update(l, x*(l-1));
    B2.update(r+1, -x*r);
}

int pq(int i) {
    return (B1.query(i)*i) - B2.query(i);
}

int query(int l, int r) {
    return pq(r) - pq(l-1);
}
};

class Lca {
private:
int sp[17][maxN];
int log[maxN];
vi euler, fir, hit;

void dfs(vector<vi>& adj, int v, int h = 1) {
    fir[v] = euler.size();
    euler.push_back(v);
    hit[v] = h;

    for(auto e : adj[v]) {
        if(fir[e] == -1) {
            dfs(adj, e, h+1);
            euler.push_back(v);
        }
    }
}

void build() {
    int n = euler.size();
    for(int i = 0 ;i < n; i++) sp[0][i] = euler[i];

    for(int j = 1; (1<<j) < n; j++) {
        for(int i = 0; i+(1<<j) < n; i++)
            sp[j][i] = (hit[sp[j-1][i]] < hit[sp[j-1][i+(1<<(j-1))]]) ? sp[j-1][i] : sp[j-1][i+(1<<(j-1))];
    }
    log[1] = 0;
    for(int i = 2; i < maxN; i++) log[i] = log[i/2]+1;
}

public:
Lca(vector<vi>& adj, int root = 0) {
    euler.reserve(adj.size()*2+1);
    fir.resize(adj.size(), -1);
    hit.resize(adj.size());

    dfs(adj, root);

    build();
}

int lca(int u, int v) {
    u = fir[u], v = fir[v];
    if(u > v) swap(u, v);

    int lg = log[v-u+1];
    auto one = sp[lg][u];
    auto two = sp[lg][v-(1<<lg)+1];
    return (hit[one] > hit[two]) ? two : one;
}

};

vii adj;
vpi q;

void task1(int n, int m) {
    Flag;
    vpi fd, rd;
    forn(i, m) {
        if(q[i].f < q[i].s) fd.pb({q[i].f, q[i].s});
        else rd.pb({q[i].s, q[i].f});
    }
    Flag;
    rtree rt;
    forn(i, fd.sz()) rt.add(fd[i].f, fd[i].s, 1);
    forn(i, rd.sz()) if(rt.query(rd[i].f, rd[i].s)) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    return;
}

void dfs(vi& parent, vb& vis, int u, int par = -1) {
    parent[u] = par;
    vis[u] = true;
    for(auto v : adj[u]) if(!vis[v]) dfs(parent, vis, v, u);
}

bool proc(int u, int l, vb& vis, vi& parent) {
    while(l != u) {
        if(vis[u]) return false;
        u = parent[u];
    }
    return true;
}

void task23(int m, int n) {
    vi per(m);
    vi parent(n);
    vb vis(n, false);
    dfs(parent, vis, 0);

    Lca lc(adj);
    forn(i, m) per[i] = i;

    while(1) {
        /*
        forn(i, per.sz())  cout << per[i] << ' ';
        cout << '\n';
        */
        forn(i, vis.sz()) vis[i] = false;
        forn(i, per.sz()) vis[q[per[i]].f] = true;

        bool ok = true;
        forn(i, per.sz()) {
            int l = lc.lca(q[per[i]].f, q[per[i]].s);
            //cout << q[per[i]].f << ' ' << q[per[i]].s << ' ' <<  l  << '\n';
            vis[q[per[i]].f] = false;
            if(!proc(q[per[i]].f, l, vis, parent)) {
                ok = false;
                break;
            }
            if(!proc(q[per[i]].s, l, vis, parent)) {
                ok = false;
                break;
            }
            if(vis[l]) {
                ok = false;
                break;
            }
            vis[q[per[i]].s] = true;
        }
        if(ok) {
            cout << "Yes\n";
            return;
        }
        if(!next_permutation(all(per))) break;
    }
    cout << "No" << '\n';
}

/*
check how many collisions happen for each of the nodes.
*/

void proc2(int u, int l, vi& bad, vi& parent, vi& Adj) {
    while(l != u) {
        if(bad[u] != -1) Adj.pb(bad[u]);
        u = parent[u];
    }
}

bool dfs2(vi& color, vii& Adj, int u) {
    color[u] = 1;

    bool ok = true;
    for(auto e : Adj[u]) {
        //cout << u << ' ' << e << '\n';
        if(!color[e]) {
            ok = (ok & dfs2(color, Adj, e));
        }
        if(color[e] == 1) {
            //Flag;
            return false;
        }
        //If color is black, no need to do anything
    }
    color[u] = 2;
    return ok;
}

void task456(int n, int m) {
    vii Adj(m);
    vi bad(n, -1);
    vi parent(n);
    vb vis(n);
    dfs(parent, vis, 0);

    forn(i, m) bad[q[i].f] = i;

    Lca lc(adj);
    forn(i, m) {
        int l = lc.lca(q[i].f, q[i].s);
        bad[q[i].f] = -1;
        proc2(q[i].f, l, bad, parent, Adj[i]), proc2(q[i].s, l, bad, parent, Adj[i]);
        if(bad[l] != -1) Adj[i].pb(bad[l]);
        bad[q[i].f] = i;
    }

    /*
    forn(i, m) {
        cout << i << "  ";
        for(auto e : Adj[i]) cout << e << ' ';
        cout << '\n';
    }
    */
    vi color(m);
    forn(i, m) {
        if(color[i] == 0) {
            if(!dfs2(color, Adj, i)) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}

void solve() {
    int n;
    cin >> n;

    adj = vii(n);
    forn(i,n-1) {
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1), adj[b-1].pb(a-1);
    }

    int m;
    cin >> m;
    q = vpi(m);
    forn(i, m) {
        int a, b;
        cin >> a >> b;
        q[i] = {a-1,b-1};
    }

    /*
    forn(i, n) {
        cout << i << "  ";
        for(auto e : adj[i]) cout << e << ' ';
        cout << '\n';
    }
    cout << '\n';
    forn(i, m) {
        cout << q[i].f << ' ' << q[i].s << '\n';
    }
    cout << '\n';
    */

    
    bool ok = true;
    if(n < 300 && m <= 6) {
        task23(m, n);
        return;
    }
    
    if(m <= 500) {
        task456(n, m);
        return;
    }

    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}

