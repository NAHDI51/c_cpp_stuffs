#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

// Using segment tree
/*
class Lca {
private:
vi euler, first, height;
vb vis;
vi seg;
int size;

void dfs(vector<vi>& adj, int v, int h = 1) {
    vis[v] = true;
    first[v] = euler.size();
    euler.push_back(v);
    height[v] = h;

    for(auto e : adj[v]) 
        if(!vis[e]) {
            dfs(adj, e, h+1);
            euler.push_back(v);
        }
}

void build(vi& v) {
    size = v.size();
    height.push_back(INT_MAX);
    seg.assign(2*size, height.size()-1);
    for(int i = 0 ; i < v.size(); i++) update(i, v[i]);
}

void update(int i, int val) {
    i += size;
    seg[i]= val;
    for(i /= 2; i >= 1; i /= 2) 
        seg[i] = (height[seg[i*2]] > height[seg[i*2+1]]) ? seg[i*2+1] : seg[i*2];
}

int query(int l, int r) {
    l += size, r += size;
    int sm = INT_MAX;
    int ans = height.size()-1;
    while(l <= r) {
        if(l%2 == 1) {
            if(sm > height[seg[l]])
                sm =height[seg[l]], ans = seg[l];
            l++;
        } 
        if(r%2 == 0) {
            if(sm > height[seg[r]])
                sm = height[seg[r]], ans = seg[r];
            r--;
        }
        l /= 2, r /= 2;
    }
    return ans;
}

public:

Lca(vector<vi>& adj, int root = 0) {
    euler.reserve(2*adj.size());
    first.resize(adj.size());
    height.resize(first.size());
    vis.resize(first.size());
    dfs(adj, root);
    
    build(euler);
    cout << "Size of euler: " << euler.size() << '\n';
    for(int i = 0; i < euler.size(); i++) cout << euler[i] << ' ';
    cout << '\n';
    for(int i = 0; i < euler.size(); i++) cout << height[euler[i]] << ' ';
    cout << '\n';
}

int lca(int u, int v) {
    u = first[u], v = first[v];
    if(u > v) swap(u, v);
    return query(u, v);
}
};
*/


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