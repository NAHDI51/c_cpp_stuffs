#include <bits/stdc++.h>
using namespace std;

/*
5
1 2
2 3
3 4
4 1
1 4
*/

void dfs1(vector<vector<int>>& adj, vector<bool>& visited, int v, stack<int>& st) {
    visited[v] = true;
    for(auto e : adj[v]) if(!visited[e]) dfs1(adj, visited, e, st);
    st.push(v);
}

void dfs2(vector<vector<int>>& adj, vector<bool>& visited, int v, vector<int>& component) {
    visited[v] = true;
    component.push_back(v);
    for(auto e : adj[v]) if(!visited[e]) dfs2(adj, visited, e, component);
}

vector<vector<int>> kosaraju(vector<vector<int>> adj, vector<vector<int>> adj2) {
    vector<bool> visited(adj.size());
    stack<int> st;
    for(int i = 0; i < adj.size(); i++) if(!visited[i]) dfs1(adj, visited, i, st);

    for(int i = 0; i < visited.size(); i++) visited[i] = false;
    vector<vector<int>> scc;

    while(!st.empty()) {
        int v = st.top();
        st.pop();
        if(!visited[v]) {
            vector<int> component;
            dfs2(adj2, visited, v, component);
            scc.push_back(component);
        }
    }
    return scc;
}

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    vector<int> in_deg(edges.size());
    bool trig = false;

    //Turning them into zero indexed
    for(int i = 0; i < edges.size(); i++) 
        edges[i][0]--, edges[i][1]--;

    int bad_ver;
    for(auto e : edges) {
        in_deg[e[1]]++;
        if(in_deg[e[1]] > 1) {
            trig = true;
            bad_ver = e[1];
        }
    }
    vector<vector<int>> adj(in_deg.size());
    vector<vector<int>> adj2(adj.size());
    for(auto e : edges) {
        adj[e[0]].push_back(e[1]);
        adj2[e[1]].push_back(e[0]);
    }
    auto scc = kosaraju(adj, adj2);

    vector<int> ans;
    if(trig) {
        vector<int> incident(2);
        int id = 0;
        for(auto e : edges) 
            if(e[1] == bad_ver) incident[id++] = e[0];

        vector<int> comp(adj.size());
        for(int i = 0; i < scc.size(); i++) {
            for(int j = 0; j < scc[i].size(); j++)
                comp[scc[i][j]] = i;
        }
        if(comp[incident[0]] == comp[bad_ver]) ans = {incident[0], bad_ver};
        else if(comp[incident[1]] == comp[bad_ver]) ans = {incident[1], bad_ver};
        else ans = {incident[1], bad_ver};

    } else {
        vector<int> cycle;
        for(auto cc : scc) if(cc.size() > 1) cycle = cc;

        vector<bool> in_component(adj.size());
        for(auto c : cycle) in_component[c] = true;

        for(auto e : edges) {
            if(in_component[e[0]] && in_component[e[1]])
                ans = {e[0], e[1]};
        }
    }
    ans[0]++, ans[1]++;
    return ans;
}

int main() {
    vector<vector<int>> v;
    int n;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    auto s = findRedundantDirectedConnection(v);
    for(auto e : s)cout << e << '\t';
    cout << '\n';
}