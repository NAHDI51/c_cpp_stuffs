#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <initializer_list>
#include <tuple>

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

#define maxN 1000005

class dsu {
    vi sz, par;

    public:
    dsu(int n) {
        sz.rsz(n+1), par.rsz(n+1);
        forn(i, n+1) sz[i] = 1, par[i] = i;
    }
    int find(int v) {
        if(v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    void join(int a, int b) {
        a = find(a), b = find(b);
        if(a != b) {
            if(a < b) swap(a,b);
            par[b] = a; 
            sz[a] += sz[b];
        }
    }
};

using alist=vector<vector<pair<int,ll>>>;
/*
class Lca {
    vll dist;
    vi eu, hit, first;
    int n;
    vi seg;

    void dfs(int u, int p, alist& adj, ll dt, int h) {
        // cout << u << ' ' << p << '\n';
        eu.pb(u);
        dist[u] = dt;
        hit[u] = h;
        first[u] = eu.sz();
        
        for(auto v : adj[u]) {
            if(v.f != p) {
                dfs(v.f, u, adj, dt+v.s, h+1);
                eu.pb(u);
            }
        }
    }

    void upd(int i, int val) {
        i += n;
        seg[i] = val;
        for(i >>= 1; i >= 1; i >>= 1) {
            seg[i] = (hit[seg[i*2]] < hit[seg[i*2+1]]) ? seg[i*2] : seg[i*2+1];
        }
    }
    int query(int a, int b) {
        a += n, b += n;
        int mn = MAX, ans = -1;
        while(a <= b) {
            if(a == b && a == 0) continue;
            // cout << a << ' ' << b << '\n';
            if(((a%2) == 1)) {
                if(hit[a] < mn) 
                    mn = hit[a], ans = seg[a];
                a++;
            }
            if(((b%2) == 0)) {
                if(hit[b] < mn)
                    mn = hit[b], ans = seg[b];
                b--;
            }
            a >>= 1, b >>= 1;
        }
        return ans;
    }

    void build(vi& eu) {
        seg.rsz(n*2+2);
        forn(i, eu.sz()) upd(i, eu[i]);
    }
    public: 
    Lca(alist& adj) {
        n = maxN;
        dist.rsz(n), hit.rsz(n);
        first.rsz(n);

        dfs(1, 1, adj, 0,1);
        build(eu);
    }
    int lca(int u, int v) {
        u = first[u], v = first[v];
        if(u > v) swap(u,v);
        return query(u,v);
    }
    ll distance(int u, int v) {
        return dist[u] + dist[v] - (2ll * dist[lca(u,v)]);
    }
};
*/

struct LCA {
    int n;                                   // number of nodes
    vector<ll> dist;                         // dist[u] = distance from root
    vector<int> depth;                       // depth[u] = depth in tree
    vector<int> first;                       // first occurrence of node in euler
    vector<int> euler;                       // euler tour of nodes
    vector<int> seg;                         // segment tree over euler indices
    vector<int> hit;                         // hit[u] = depth[u] (shortcut)
    
    LCA(const vector<vector<pair<int,ll>>> &adj, int root = 1) {
        n = adj.size() - 1;
        dist.assign(n+1, 0);
        depth.assign(n+1, 0);
        first.assign(n+1, -1);

        // build euler tour
        dfs(root, -1, 0, 0, adj);

        // build segment tree
        int m = euler.size();
        seg.assign(4*m, -1);
        build(1, 0, m-1);
    }

    void dfs(int u, int p, ll d, int h, const vector<vector<pair<int,ll>>> &adj) {
        dist[u] = d;
        depth[u] = h;
        first[u] = (int)euler.size();
        euler.push_back(u);

        for (auto [v, w] : adj[u]) {
            if (v == p) continue;
            dfs(v, u, d+w, h+1, adj);
            euler.push_back(u); // return to u
        }
    }

    void build(int node, int l, int r) {
        if (l == r) {
            seg[node] = euler[l];
        } else {
            int mid = (l+r)/2;
            build(node*2, l, mid);
            build(node*2+1, mid+1, r);
            int left = seg[node*2], right = seg[node*2+1];
            seg[node] = (depth[left] < depth[right] ? left : right);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return -1;
        if (ql <= l && r <= qr) return seg[node];
        int mid = (l+r)/2;
        int left = query(node*2, l, mid, ql, qr);
        int right = query(node*2+1, mid+1, r, ql, qr);
        if (left == -1) return right;
        if (right == -1) return left;
        return (depth[left] < depth[right] ? left : right);
    }

    int lca(int u, int v) {
        int L = first[u], R = first[v];
        if (L > R) swap(L, R);
        return query(1, 0, (int)euler.size()-1, L, R);
    }

    ll distance(int u, int v) {
        int a = lca(u,v);
        return dist[u] + dist[v] - 2*dist[a];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    alist adj(n+1);
    vb mark(m);

    vvll eg;
    forn(i, m) {
        int a, b, w;
        cin >> a >> b >> w;
        eg.pb({a,b,w});
    }
    
    sort(all(eg), [](vll& a, vll& b) {
        return a[2] < b[2];
    });
    dsu ds(n);
    int ind = 0;
    for(auto a : eg){
        if(ds.find(a[0]) != ds.find(a[1])) {
            // Flag;
            mark[ind] = 1;
            ds.join(a[0],a[1]);
            adj[a[0]].pb({a[1],a[2]});
            adj[a[1]].pb({a[0],a[2]});
        }
        ind++;
    }
    /*
    for1n(i, n) {
        for(auto x : adj[i]) {
            cout << i << ' ' << x.f << ' ' << x.s << '\n';
        }
    }
    */ 
    LCA lc(adj);

    ind = 0;
    for(auto a : eg) {
        if(!mark[ind] && a[2] < lc.distance(a[0],a[1])) {
            cout << "No\n";
            return;
        }
        ind++;
    }
    cout << "Yes\n";
    return;

}

int main() {
    //Sublime
    // init();
    // FASTIO;
    solve();
}

