#include <bits/stdc++.h>
using namespace std;


/*
#define MAX 100000000
vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int s) {
    vector<int> dist(adj.size());
    vector<int> parent(adj.size());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    for(int i = 0; i < dist.size(); i++) dist[i] = MAX;
    for(int i = 0; i < parent.size(); i++) parent[i] = i;

    dist[s] = 0;
    pq.push({dist[s], s});
    vector<bool> processed;

    while(!pq.empty()) {
        auto u = pq.top().second; 
        pq.pop();

        if(processed[u]) continue;
        processed[u] = true;

        for(auto e : adj[u]) {
            int v = e.first, w = e.second;
            if(dist[v] > (dist[u] + w)) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return parent;
}
*/

#define MAX 100000000
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

int main() {

}