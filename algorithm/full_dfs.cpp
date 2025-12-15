#include <bits/stdc++.h>
using namespace std;

int tim;
vector<bool> visited;
vector<int> color;
vector<int> parent;
vector<pair<int, int>> stamp;

#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(vector<vector<int>>& adj, int v) {
    tim++;
    visited[v] = true;
    stamp[v].first = tim;
    color[v] = GRAY;

    for(auto e : adj[v]) {
        if(!visited[e]) parent[e] = v; dfs(adj, e);
    }
    
    tim++;
    stamp[v].second = tim;
    color[v] = BLACK;
}
void dfs_start(vector<vector<int>>& adj) {
    visited.resize(adj.size());
    color.resize(adj.size());
    parent.resize(adj.size());
    stamp.resize(adj.size());
    tim = 0;

    for(int i = 0; i < adj.size(); i++) {
        color[i] = WHITE;
        parent[i] = i;
        stamp[i] = {0, 0};
        visited[i] = false;x
    }

    for(int i = 0; i < adj.size(); i++) 
        if(!visited[i]) dfs(adj, i);
    return;
}

int main() {

}