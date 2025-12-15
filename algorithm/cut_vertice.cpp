#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using ii = pair<int, int>;

vi stamp;
vi low;
vector<bool> vis;
int tim = 0;
int child = 0;
vi art;
vector<ii> bridge;

void dfs(vii& adj, int s, int root, int prev) {
    stamp[s] = prev++;
    low[s] = stamp[s];
    vis[s] = true;

    for(auto e : adj[s]) {
        if(e != prev) {
            if(!vis[e]) {
                if(s == root) child++;
                dfs(adj, e, root, s);

                if(stamp[s] <= low[e]) art.push_back(s);
                if(stamp[s] < low[e]) bridge.push_back({s, e});
            } else 
                low[s] = min(low[s], low[e]);
        }
    }
}

pair<vi, vector<ii>> find(vector<vector<int>>& adj) {
    vector<int> vis;
    stamp.resize(adj.size());
    low.resize(adj.size());

    for(int i = 0; i < adj.size(); i++) {
        if(!vis[i]) {
            child = 0;
            if(child > 1) art.push_back()
        }
    }
}


int main() {

}