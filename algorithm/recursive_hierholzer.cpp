#include <bits/stdc++.h>
using namespace std;

void euler_path(vector<vector<int>>& adj, int u, vector<int>& circuit) {
    if(!adj[u].empty()) {
        auto v = adj[u].back();
        adj[u].pop_back();
        euler_path(adj, v, circuit);
    }
    circuit.push_back(u);
}

int main() {

}