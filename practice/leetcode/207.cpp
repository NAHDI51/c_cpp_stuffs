#include <bits/stdc++.h>
using namespace std;

using vi=vector<int>;
using vii = vector<vi>;

#define WHITE 0
#define GRAY  1
#define BLACK 2

bool dfs(vii& adj, vi& color, int u) {
    color[u] = GRAY;

    for(auto v : adj[u]) {
        if(color[v] = WHITE) 
            if(dfs(adj, color, v) == false)
                return false;
        else if(color[v] == GRAY)
            return false;
    }

    color[u] = BLACK;
}

bool canFinish(int n, vector<vector<int>>& edges) {
    vii adj(n);
    for(auto p : edges) adj[p.first].push_back(p.second);

    vi color(n);
    for(int i = 0; i < color.size(); i++) {
        if(color[i] != WHITE) {
            if(!dfs(adj, color, i)) return false;
        }
    }
    return true;
}

int main() {

}