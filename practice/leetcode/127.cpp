#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>& adj, int s, int t) {
    vector<int> dist(adj.size());
    vector<bool> vis(adj.size());
    
    queue<int> q;
    q.push(s);
    dist[s] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : adj[u]) {
            if(!vis[v]) {
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist[t];
}

int ladderLength(string bw, string ew, vector<string>& vert) {
    int s=vert.size(), t = s+1;
    for(int i = 0; i < vert.size(); i++) {
        if(bw == vert[i]) s = i;
        if(ew == vert[i]) t = i;
    }
    if(t == vert.size()+1) return 0;
    if(s == vert.size()) vert.push_back(bw);

    vector<vector<int>> adj(vert.size());
    for(int i = 0; i < vert.size()-1; i++) {
        for(int j = i+1; j < vert.size(); j++) {
            int dif = 0;
            for(int k = 0; k < vert[0].size(); k++)
                if(vert[i][k] != vert[j][k]) dif++;

            if(dif == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    return bfs(adj, s, t);
}

int main() {

}