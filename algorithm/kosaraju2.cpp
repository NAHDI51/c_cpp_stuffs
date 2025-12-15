#include <bits/stdc++.h>
using namespace std;

stack<int> st;
vector<int> component;
void dfs1(vector<vector<int>>& adj, vector<bool>& visited, int& v) {
    visited[v] = true;
    for(auto e : adj[v])
        if(!visited[v]) dfs1(adj, visited, e);
    st.push(v);
}

void dfs2(vector<vector<int>>& adj, vector<bool>& visited, int& v) {
    visited[v] = true;
    component.push_back(v);

    for(auto e : adj[v])
        if(!visited[e]) dfs2(adj, visited, e);
}

vector<vector<int>> kosaraju(vector<vector<int>>& adj, vector<vector<int>> adj2) {
    vector<bool> visited(adj.size());

    for(int i = 1; i < adj.size(); i++) 
        if(!visited[i]) dfs1(adj, visited, i);
    
    /*
    vector<vector<int>> adj2(adj.size());
    for(int i = 1; i < adj.size(); i++) {
        for(int j = 0; j < adj[i].size(); j++)
            adj2[adj[i][j]].push_back(i);
    }
    for(int i = 1; i < adj2.size(); i++) sort(adj2[i].begin(), adj2[i].end());
    */
    for(int i = 0; i < visited.size(); i++) visited[i] = false;

    vector<vector<int>> components;
    while(!st.empty()) {
        int v = st.top();
        st.pop();
        
        if(!visited[v]) {
            component = vector<int>{};
            dfs2(adj2, visited, v);
            sort(component.begin(), component.end());
            components.push_back(component);
        }
    }
    return components;
}   

int main() {
    vector<vector<int>> adj;
    vector<vector<int>> adj2;

    int n;
    cout << "enter the number of vertices in the graph: ";
    cin >> n;
    adj.resize(n+1);
    adj2.resize(n+1);

    cout << "enter the edges (Enter zz to exit): '\n";
    while(1) {
        string s;
        cin >> s;
        if(s == "zz") break;

        adj[(int)(s[0]-112)].push_back((int)(s[1]-112));
        adj2[(int)(s[1]-112)].push_back((int)(s[0]-112));
    }
    for(int i = 1; i < adj.size(); i++) sort(adj[i].begin(), adj[i].end());

    auto ans = kosaraju(adj, adj2);
    for(int i = 0; i < ans.size(); i++) {
        cout << i+1 << '\t';
        for(int j = 0; j < ans[i].size(); j++)
            cout << (char) (ans[i][j]+112) << ' ';
        cout << '\n';
    }
    return 0;
}