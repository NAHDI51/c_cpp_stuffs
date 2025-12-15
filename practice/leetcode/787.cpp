#include <bits/stdc++.h>
using namespace std;

using vi=vector<int>;
using vii = vector<vi>;
using ii=pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
#define MAX 10000000

int findCheapestPrice(int n, vector<vector<int>>& edges, int s, int t, int k) {
    vpii adj(n);
    for(auto e : edges) adj[e[0]].push_back({e[1], e[2]});
    
    vi path(n);
    vi dist(n, MAX);
    vi vis(n);

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    dist[s] = 0;
    path[s] = 0;

    while(!pq.empty()) {
        auto u = pq.top().second;
        if(vis[n]) continue;
        vis[n] = true;

        for(auto x : adj[u]) {
            int v = x.second, w = x.first;
            if(dist[v] > dist[u]+w && path[u] <= k) {
                dist[v] = dist[u]+w;
                path[v] = path[u]+1;
                pq.push({dist[v], v});
            }
        }
    }
    return (dist[t] == MAX) ? -1 : dist[t];
}

int main() {

}