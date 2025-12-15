#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

// Using segment tree
struct LCA {
    int n;                                   
    vector<ll> dist;                         
    vector<int> depth;                       
    vector<int> first;                       
    vector<int> euler;                       
    vector<int> seg;                         
    vector<int> hit;                         
    
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


//Using sparse table

#define maxN 1000
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

int dist(int u, int v) {
    return hit[u]+hit[v]-2*hit[lca(u,v)];
}

};

int main() {
    //cout << "reached here.\n";
    int n;
    //cout << "enter the number of vertices: ";
    cin >> n;
    vector<vi> adj(n);

    //cout << "enter the edges (Enter 0 0 to exit): \n";
    while(1) {
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;

        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    Lca ds(adj);

    while(1) {
        //cout << "enter the lcm queries (enter 0 0 to exit)): ";
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;

        //cout << "The following lca: " << ds.lca(a-1, b-1)+1 << '\n';
        cout << ds.dist(a-1,b-1) << ' ' << ds.lca(a-1,b-1)+1 << '\n';
    }
}