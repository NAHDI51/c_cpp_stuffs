#include <bits/stdc++.h>
using namespace std;

// ---- Function types ----
// combine: merge parentDP and childDP
// finalize: adjust DP after all children processed
using CombineFunc = function<int(int,int,int,int)>;
using FinalizeFunc = function<int(int,int,int)>;

// Run tree DP with a chosen root
vector<int> treeDP(int root, const vector<vector<int>>& graph,
                   const vector<int>& defaultVal,
                   CombineFunc combine,
                   FinalizeFunc finalize = [](int nodeDP, int node, int parentEdge){ return nodeDP; }) 
{
    int n = graph.size();
    vector<int> DP(n);

    function<int(int,int)> dfs = [&](int node, int parent) {
        int nodeDP = defaultVal[node];
        for (int i = 0; i < (int)graph[node].size(); i++) {
            int nei = graph[node][i];
            if (nei == parent) continue;
            int neiDP = dfs(nei, node);
            nodeDP = combine(nodeDP, neiDP, node, i);
        }
        int parent_eind = (parent == -1 ? -1 : 
                           (int)(find(graph[node].begin(), graph[node].end(), parent) - graph[node].begin()));
        DP[node] = finalize(nodeDP, node, parent_eind);
        return DP[node];
    };

    dfs(root, -1);
    return DP;
}

// Brute-force rerooter (O(n^2))
tuple<vector<int>, vector<vector<int>>, vector<vector<int>>> 
rerooter(const vector<vector<int>>& graph,
         const vector<int>& defaultVal,
         CombineFunc combine,
         FinalizeFunc finalize = [](int nodeDP, int node, int parentEdge){ return nodeDP; })
{
    int n = graph.size();
    vector<int> rootDP;
    map<pair<int,int>, int> edgeDP;

    for (int root = 0; root < n; root++) {
        auto DP = treeDP(root, graph, defaultVal, combine, finalize);
        rootDP.push_back(DP[root]);
        for (int nei : graph[root]) {
            edgeDP[{root, nei}] = DP[nei];
        }
    }

    vector<vector<int>> forwardDP(n), reverseDP(n);
    for (int node = 0; node < n; node++) {
        for (int nei : graph[node]) {
            forwardDP[node].push_back(edgeDP[{node, nei}]);
            reverseDP[node].push_back(edgeDP[{nei, node}]);
        }
    }

    return {rootDP, forwardDP, reverseDP};
}
