#include <bits/stdc++.h>
using namespace std;

using vi=vector<int>;
using vii = vector<vi>;
int dp[50001];

int dfs(vii& adj, vi& w, int u) {
    if(dp[u] != -1) return dp[u];
    dp[u] = 0;

    for(auto v : adj[u]) 
        dp[u] = max(dp[u], dfs(adj, w, v));
    return dp[u] = dp[u]+w[u];
}

int minimumTime(int n, vector<vector<int>>& edges, vector<int>& w) {
    vii adj(n);
    for(auto t : edges) 
        adj[t[0]-1].push_back(t[1]-1);
    
    memset(dp, -1 , sizeof(dp));
    for(int i = 0; i < adj.size(); i++) {
        if(dp[i] == -1) dfs(adj, w, i);
    }

    int mx = INT_MIN;
    for(int i = 0; i < n; i++) 
        mx = max(mx, dp[i]);
    return mx;
}

int main() {

}