#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& a, int r, int c) {
    if(r == -1 || c == -1 || r >= a.size() || c >= a[0].size()) return;
    if(a[r][c] != 'O') return;
    a[r][c] = '#';

    dfs(a, r-1, c), dfs(a, r+1, c), dfs(a, r, c-1), dfs(a, r, c+1);
}
void solve(vector<vector<char>>& a) {
    int n = a.size(), m = a[0].size();

    for(int i = 0; i < n; i++) {
        if(a[i][0] == 'O') dfs(a, i, 0);
        if(a[n-1][0] == 'O') dfs(a, n-1, 0);
    }
    for(int i = 0; i < m; i++) {
        if(a[0][i] == 'O') dfs(a, 0, i);
        if(a[0][m-1] == 'O') dfs(a, 0, m-1);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '#') a[i][j] = 'O';
            else a[i][j] = 'X';
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> v(n, (n, vector<char>{}));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> v[i][j];

}