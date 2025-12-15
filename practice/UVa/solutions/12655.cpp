#include <bits/stdc++.h>
using namespace std;

//ALGORITH
/*
1. Find the Maximum Spanning tree of the given graph
2. Spanning tree will give us the tree with maximum edges.
3. Create an LCA of the spanning tree
4. Answer the queries using LCA
*/

#define forn(i, n) for(int i = 0; i < n; i++)
#define forr(i, n) for(int i = n; i >= 0; i--)

using vi = vector<int>;
using vii = vector<vi>;
using vpii = vector<vector<pair<int ,int>>>;

vpii spantree(int n, vii& edges) {
    vi anc(n), size(n);
    for(int i = 0; i < n; i++) anc[i] = i, size[i] = 1;

    auto find = [&] (int a) -> int {
        while(a != anc[a]) a = anc[a];
        return a;
    };
    auto same = [&] (int a, int b) -> int {
        return find(a) == find(b);
    };
    auto join = [&] (int a, int b) -> int {
        a = find(a), b = find(b);
        if(size[a] < size[b]) swap(a, b);
        size[a] += size[b];
        anc[b] = a;
        //cout << "Reached here.\n";
    };

    sort(edges.begin(), edges.end(), greater<vi>{});

    vpii ans(n);    
    for(int i = 0; i < edges.size(); i++) {
        auto a = edges[i][1], b = edges[i][2];
        auto w = edges[i][0];
        if(!same(a, b)) {
            join(a, b);
            ans[a].push_back({b, w});
            ans[b].push_back({a, w});
        }
    }
    return ans;
}

#define maxN 20010

class ds {
private:
int sparse[16][2*maxN];
int log[maxN];
int dp[16][maxN];
int parent[maxN];
vi eu, ht, fir;

void dfs(vpii& adj, int u, int hgt = 1, int prev = 0) {
    fir[u] = eu.size();
    eu.push_back(u);
    ht[u] = hgt;
    parent[u] = prev;

    for(auto s : adj[u]) {
        auto v = s.first;
        if(fir[v] == -1) {
            dfs(adj, v, hgt+1, u);
            eu.push_back(u);
        }
    }
}

public:
ds(int n, vpii& adj, int root = 0) {
    eu.reserve(n*2);
    ht.resize(n);
    fir.resize(n, -1);

    dfs(adj, root);

    int m = eu.size();
    for(int i = 0; i < m; i++) sparse[0][i] = eu[i];

    for(int j = 1; (1<<j) < m; j++) {
        for(int i = 0; i + (1<<j) < m; i++) {
            sparse[j][i] = (ht[sparse[j-1][i]] < ht[sparse[j-1][i+(1<<(j-1))]]) ? sparse[j-1][i] : sparse[j-1][i+(1<<(j-1))];
        }
    }
    log[1] = 0;
    for(int i = 2; i < 40050; i++) log[i] = log[i/2]+1;

    int mx = 0;
    for(auto x : ht) mx = max(x, mx);
    //Let dp[i][j] be the lowest value edge in the range {i, (1<<j)th ancestor of i}

    for(int i = 0; i < n; i++) {
        if(parent[i] == -1) continue;
        int j = 0;
        for(j = 0; j < adj[parent[i]].size(); i++) {
            if(adj[parent[i]][j].first == i) break;
        }
        dp[0][i] = adj[parent[i]][j].second;
    }
    for(int j = 1; (1<<j) <= mx; j++) {
        for(int i = 0; i < n; i++) {
            if((1<<j) > ht[i]) continue;
            //dp[j][i] = min(dp[j-1][i], )
        }
    }
}

int lca(int u, int v) {
    u = fir[u], v = fir[v];
    if(u > v) swap(u, v);

    auto lg = log[v-u+1];
    auto one = sparse[lg][u];
    auto two = sparse[lg][v-(1<<lg)+1];
    return (ht[one] < ht[two]) ? one : two;
}

int query(){}

};

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vii edges;
    while(M--) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a-1, b-1});
    }
    auto adj = spantree(N, edges);
    auto ans = ds(N, adj);

    while(1) {
    }
}
/*
7 6 10
1 2 5
2 5 3
2 6 4
1 3 10
1 4 11
4 7 5

*/