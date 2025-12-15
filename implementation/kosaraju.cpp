#include <bits/stdc++.h>
using namespace std;

void dfs1(stack<int>& st, vector<vector<int>>& adj, vector<bool>& visited, int v) {
    visited[v] = true;
    for(auto e : adj[v]) if(!visited[e]) dfs1(st, adj, visited, e);
    st.push(v);
}

void dfs2(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component, int v) {
    visited[v] = true;
    component.push_back(v);
    for(auto e : adj[v]) if(!visited[e]) dfs2(adj, visited, component, e);
}

vector<vector<int>> kosaraju(vector<vector<int>>& adj) {
    stack<int> st;
    vector<bool> visited(adj.size());

    for(int i = 0; i < adj.size(); i++) if(!visited[i]) dfs1(st, adj, visited, i);

    vector<vector<int>> adj2(adj.size());
    for(int i = 0; i < adj.size(); i++) {
        for(int j = 0; j < adj[i].size(); j++)
            adj2[adj[i][j]].push_back(i);
    }
    for(int i = 0; i < adj2.size(); i++) sort(adj2[i].begin(), adj2[i].end());
    for(int i = 0; i < adj.size(); i++) visited[i] = false;


    vector<vector<int>> scc;
    while(!st.empty()) {
        vector<int> component;
        int v = st.top();
        st.pop();
        if(!visited[v]) {
            dfs2(adj2, visited, component, v);
            scc.push_back(component);
        }
    }
    for(int i = 0; i < scc.size(); i++) sort(scc[i].begin(), scc[i].end());
    return scc;
}

int main() {
    int n;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;
    vector<vector<int>> adj(n);

    cout << "Enter the edges (Enter zz to exit):\n";;
    while(1) {
        string s;
        cin >> s;
        if(s == "zz") break;
        adj[s[0]-113].push_back(s[1]-113);
    }
    for(int i = 0; i < adj.size(); i++) sort(adj[i].begin(), adj[i].end());
    

    auto ans = kosaraju(adj);
    for(int i = 0; i < ans.size(); i++) {
        cout << i+1 << '\t';
        for(int j = 0; j < ans[i].size(); j++)
            cout << (char) (ans[i][j]+113) << ' ';
        cout << '\n';
    }
}