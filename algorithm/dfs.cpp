#include <bits/stdc++.h>
using namespace std;

#define lim 1000
int paren[lim];
int tim = 0;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int c) {
    //cout << tim << '\n';
    tim++;
    visited[c] = true;
    paren[tim] = c;
    for(auto e : adj[c]) {
        if(visited[e] == 0) {
            dfs(e);
        }
    }
    tim++;
    paren[tim] = c;
}

int main() {
    cout << "Enter the number of vertices: ";
    int n;
    cin >> n;

    adj.resize(n+1);
    visited.resize(n+1);
    cout << "Enter the edges (enter (0, 0) to end this): \n";
    while(1) {
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        adj[a].push_back(b);
    }
    for(int i = 0; i < adj.size(); i++) sort(adj[i].begin(), adj[i].end());
    cout << "Enter the vertex to search from: ";
    int c;
    cin >> c;
    tim = 0;
    memset(paren, 0, sizeof(paren));
    dfs(c);
    for(int i = 0; i <= tim; i++)
        cout << paren[i] << ' ';
    cout << '\n';
}