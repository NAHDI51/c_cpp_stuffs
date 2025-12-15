#include <bits/stdc++.h>
using namespace std;

int tim = 0;
void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& stamp, int v) {
    tim++;
    visited[v] = true;

    for(auto e : adj[v])
        if(!visited[e]) dfs(adj, visited, stamp, e);
    
    tim++;
    stamp[tim] = v;
}

void dfs2(vector<vector<int>>& adj, vector<int>& comp, int component, vector<bool>& visited, int v) {
    visited[v] = true;
    for(auto e : adj[v])
        if(!visited[e]) dfs2(adj, comp, component, visited, e);
    comp[v] = component+1;
}

vector<vector<int>> kosaraju(vector<vector<int>>& adj) {
    vector<int> stamp(10000);
    vector<bool> visited(adj.size());

    for(int i = 1; i < visited.size(); i++)
        if(!visited[i]) dfs(adj, visited, stamp, i);
    
    vector<vector<int>> adj2(adj.size());
    for(int i = 1; i < adj.size(); i++) {
        for(int j = 0; j < adj[i].size(); j++)
            adj2[adj[i][j]].push_back(i);
    }
    for(int i = 0; i < adj2.size(); i++) sort(adj2[i].begin(), adj2[i].end());

    for(int i = 0; i < visited.size(); i++) visited[i] = false;
    int component = 0;

    vector<int> comp(adj.size());
    for(int i = stamp.size()-1; i > 0; i--) {
        if(stamp[i] && !visited[stamp[i]]) {
            dfs2(adj2, comp, component, visited, stamp[i]);
            component++;
        }
    }
    vector<vector<int>> scc(component+1);

    for(int i = 1; i < comp.size(); i++) 
        scc[comp[i]].push_back(i);
    
    for(int i = 0; i < scc.size(); i++) sort(scc[i].begin(), scc[i].end());

    return scc;
}

int main() {
    vector<vector<int>> adj;

    int n;
    cout << "enter the number of vertices in the graph: ";
    cin >> n;
    adj.resize(n+1);

    cout << "enter the edges (Enter zz to exit): '\n";
    while(1) {
        string s;
        cin >> s;
        if(s == "zz") break;

        adj[(int)(s[0]-112)].push_back((int)(s[1]-112));
    }
    for(int i = 1; i < adj.size(); i++) sort(adj[i].begin(), adj[i].end());

    tim = 0;
    auto ans = kosaraju(adj);
    for(int i = 1; i < ans.size(); i++) {
        cout << i << '\t';
        for(int j = 0; j < ans[i].size(); j++)
            cout << (char) (ans[i][j]+112) << ' ';
        cout << '\n';
    }
    return 0;
}