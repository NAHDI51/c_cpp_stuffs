#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int, int>> stamp;
int tim;

void dfs(int c) {
    tim++;
    visited[c] = true;
    stamp[c].first = tim;

    for(auto e : adj[c]) 
        if(!visited[e]) dfs(e);

    tim++;
    stamp[c].second = tim;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";

    adj.resize(n+1);
    visited.resize(n+1);
    stamp.resize(n+1);

    cin >> n;
    cout << "Enter the number of edges: ";
    while(1) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i < adj.size(); i++) sort(adj[i].begin(), adj[i].end());

    tim = 0;
    int component = 0;
    for(int i = 1; i < adj.size(); i++)
        dfs(i), component++;
    cout << "Total components: " << component << '\n';
}