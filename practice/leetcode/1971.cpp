#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;

void dfs(vii& adj, vi& visited, int u) {
    visited[u] = true;
    for(auto v : adj[u])
        if(!visited[v]) dfs(adj, visited, v);
}

bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    vii adj(edges.size());
    for(auto e : edges) adj[e[0]].push_back(e[1]);
    vi visited(adj.size());

    dfs(adj, visited, start);
    return visited[end];
}

int main() {x

}