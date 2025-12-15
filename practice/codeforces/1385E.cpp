#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using vb = vector<bool>;
using ii = pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using ll = long long;
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

#define SF cout << "Reached here.\n"

#define pb push_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert
#define maxN 200001

#define MAX 1000000000
#define MIN -MAX

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

#define W 0
#define G 1
#define B 2

stack<int> dag;
int col[maxN];
vi stmp;
int tim;

bool dfs(vii& adj, int u) {
    col[u] = G;
    bool ok = true;
    for(auto v : adj[u]) {
        if(col[v] == G) return false;
        //otherwise, BLACK OR WHITE, visit if white, don't if black
        else if(col[v] == W) ok &= dfs(adj, v);
    }
    col[u] = B;
    dag.push(u);

    tim++;
    stmp[u] = tim;
    return ok;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vii adjd(n);
    vpi edges;

    forn(i, m) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t) adjd[a-1].pb(b-1);
        else edges.pb({a-1, b-1});
    }

    memset(col, W, n*4);
    stmp.rsz(n, n);
    tim = 0;
    forn(i, n) if(!col[i] && !dfs(adjd, i)) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES\n";
    while(!dag.empty()) {
        for(auto v : adjd[dag.top()]) cout << dag.top()+1 << ' ' << v+1 << '\n';
        dag.pop();
    }
    for(auto e : edges) {
        if(stmp[e.s] > stmp[e.f]) swap(e.s, e.f);
        cout << e.f+1 << ' ' << e.s+1 << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}