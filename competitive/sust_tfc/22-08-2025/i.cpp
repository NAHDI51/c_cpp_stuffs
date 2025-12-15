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

#define PI 3.14159

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

#define MAX 1000000000000000000ll
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

#define maxN 
/*
vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int s) {
    vector<bool> visited(adj.size());
    vector<int> dist(adj.size());
    vector<int> parent(adj.size());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 0; i < adj.size(); i++) {
        visited[i] = false;
        dist[i] = MAX;
        parent[i] = i;
    }

    dist[s] = 0;
    pq.push({dist[s], s});

    while(!pq.empty()) {
        int a = pq.top().second;
        pq.pop();

        if(visited[a]) continue;
        visited[a] = true;

        for(auto x : adj[a]) {
            auto b = x.first, w = x.second;
            if(dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w, pq.push({dist[b], b});
                parent[b] = a;
            }
        }
    }
    return parent;
}
*/

void dijkstra(map<ii, vector<pair<pair<int,int>, ll>>>& adj, int n, int m, ii s, ii t, ll T) {
    map<ii, bool> vis;
    map<ii, ll> dist;
    priority_queue<pair<ll, ii>> pq;

    for1n(i, n) {
        for1n(j, m) {
            vis[{i,j}] = false;
            dist[{i,j}] = MAX;
        }
    }
    dist[s] = 0;
    pq.push({-dist[s], s});

    while(!pq.empty()) {
        auto a = pq.top().s;
        pq.pop();

        if(vis[a]) continue;
        vis[a] = true;

        for(auto x : adj[a]) {
            auto b = x.f;
            auto w = x.s;

            if(dist[b] > dist[a]+w) {
                dist[b] = dist[a]+w;
                pq.push({-dist[b],b});
            }
        }
    }
    cout << dist[t] << '\n';
    if(dist[t] > T) {
        cout << -1 << '\n';
    } else {
        cout << dist[t] << '\n';
    }
    return;
}

void solve() {
    int n, m;
    cin >> n >> m;

    ii st;
    cin >> st.f >> st.s;
    ii ed; 
    cin >> ed.f >> ed.s;

    ll T;
    cin >> T;

    vvll b(n+1, vll(m+1)), jam(n+1, vll(m+1));

    for1n(i, n) for1n(j, m) cin >> b[i][j];
    for1n(i, n) for1n(j, m) cin >> jam[i][j];

    map<ii, vector<pair<pair<int,int>, ll>>> adj;
    for1n(i, n) {
        for1n(j, m) {
            ll r = 0, sm = 0;

            //Train
            for(int k = j-1; k >= 1; k--) {
                sm++;
                adj[{i,j}].pb({{i,k}, sm+b[i][k]});
            }
            sm = 0;
            for(int k = j+1; k <= m; k++) {
                sm++;
                adj[{i,j}].pb({{i,k}, sm+b[i][k]});
            }
            sm = 0, r = 0;
            //Buses
            for(int k = i-1; k >= 1; k--) {
                sm++;
                r += jam[k][j];
                adj[{i,j}].pb({{k,j}, sm+b[k][j]+r});
            }
            sm = 0, r = 0;
            for(int k = i+1; k <= n; k++) {
                sm++;
                r += jam[k][j];
                adj[{i,j}].pb({{k,j}, sm+b[k][j]+r});
            }
        }
    }
    /*
    for1n(i, n) {
        for1n(j, m) {
            for(int k = 0; k < adj[{i,j}].size(); k++) {
                // cout << adj[{i,j}][k].s << ' ';
            }
            cout << '\n';
        }
    }
        */
    dijkstra(adj, n, m, st, ed, T);
}

int main() {
    //Sublime
    // init();
    FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

