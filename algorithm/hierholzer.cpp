#include <bits/stdc++.h>
using namespace std;

void hiezholder(vector<vector<int>> adj) {
    if(adj.empty()) return;

    stack<int> path;
    vector<int> cir;

    int cur = 0;
    path.push(cur);

    while(!path.empty()) {
        if(adj[cur].size()) {
            path.push(cur);
            int nxt = adj[cur].back();
            adj[cur].pop_back();
            cur = nxt;
        } else {
            cir.push_back(cur);
            cur = path.top(), path.pop();
        }
    }
    for(int i = cir.size()-1; i >= 0; i--)
        cout << cir[i] << ' ';
}

int main() {

}