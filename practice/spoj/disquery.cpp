#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using ii = pair<int ,int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;

#define maxN 20000
class lca {
private:
int spmin[18][maxN], spmax[18][maxN], log[maxN];
vector<int> euler, first;

void dfs(vpii& adj, int u) {
    first[u] = euler.size();
    euler.push_back(u);

    for(auto v : adj[u]) {
        if(first[v.x] == -1) {
            dfs(adj, v.x);
            euler.push_back(u);
        }
    }
}

void build(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        spmin[0][i] = arr[i];
        spmax[0][i] = arr[i];
    }
    for(int j = 1; (1<<j) < arr.size(); j++) {
        for(int i = 0; i+(1<<j) < arr.size(); i++) {
            spmin[j][i] = min(spmin[j-1][i], spmin[j-1][i+(1<<(j-1))]);
            spmax[j][i] = max(spmax[j-1][i], spmax[j-1][i+(1<<(j-1))]);
        }
    }
    log[1] = 0;
    for(int i = 2; i < maxN; i++)
        log[i] = log[i/2]+1;
}

public:
lca(vpii& adj, int root = 0) {
    euler.reserve(2*adj.size());
    first.resize(adj.size(), -1);
    dfs(adj, root);

    vector<int> arr(euler.size()-1);
    for(int i = 0; i < euler.size()-1; i++) {
        for(auto v : adj[euler[i]])
            if(v.x == euler[i+1]) arr[i] = v.y;
    }  
    build(arr);
}

void query(int u, int v) {
    u = first[u], v = first[v];
    if(u > v) swap(u, v);
    v--;

    auto lg = log[v-u+1];
    int one = min(spmin[lg][u], spmin[lg][v-(1<<lg)+1]);
    int two = max(spmax[lg][u], spmax[lg][v-(1<<lg)+1]);
    cout << one << ' ' << two << '\n';
}
};

int main() {
    int n;
    cin >> n;
    vpii adj(n);
    n--;
    while(n--) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a-1].push_back({b-1, w});
        adj[b-1].push_back({a-1, w});
    }
    cout << "reached here.\n";
    lca ans(adj);
    cout << "reached here.\n";
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        ans.query(a-1, b-1);
    }
}