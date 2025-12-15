#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int u) {
    stack<int> st;
    st.push(u);

    while(!st.empty()) {
        if(adj[u].size()) {
            st.push(u);
            auto v = adj[u].back();
            adj[u].pop_back();
            v = u;
        } else {
            visited[u] = true;
            st.pop();
        }
    }
}

int main() {
    
}