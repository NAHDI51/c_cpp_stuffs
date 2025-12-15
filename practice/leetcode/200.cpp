#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<bool>>& visited, vector<vector<char>>& a, int r, int c) {
    if((r == -1) || (c == -1) || (r == a.size()) || (c == a[0].size())) return;
    if(a[r][c] != '1' || visited[r][c]) return;
    visited[r][c] = true;

    dfs(visited, a, r+1, c), dfs(visited, a, r-1, c), dfs(visited, a, r, c+1), dfs(visited, a, r, c-1);
}

int numIslands(vector<vector<char>>& a) {
    vector<vector<bool>> visited(a.size(), (a[0].size(), vector<bool>{}));

    int components = 0;

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[0].size(); j++) {
            if((a[i][j] == '1') && !visited[i][j]) {
                dfs(visited, a, i, j), components++;
            }
        }
    }
    return components;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n, (m, vector<char>{}));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> adj[i][j];
    cout << numIslands(adj) << '\n';
}