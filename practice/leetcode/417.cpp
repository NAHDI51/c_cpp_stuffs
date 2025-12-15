#include <bits/stdc++.h>
using namespace std;

using vii = vector<vector<int>>;

bool dfs(vii& a, vii& reach, int r, int c, int& n, int& m, int& reach_r, int& reach_c) {
    if(r == -1 || c == -1 || r == n || c == m) return false;
    if(r == reach_r || c == reach_c) reach[r][c] = true;

    if(reach[r][c] != -1) return reach[r][c];

    reach[r][c] = false;
    
    if((r != 0) && (a[r][c] >= a[r-1][c])) 
        reach[r][c] |= dfs(a, reach, r-1, c, n, m, reach_r, reach_c);
    if(((r+1) != n) && (a[r][c] >= a[r+1][c])) 
        reach[r][c] |= dfs(a, reach, r+1, c, n, m, reach_r, reach_c);
    if((c != 0) && (a[r][c] >= a[r][c-1])) 
        reach[r][c] |= dfs(a, reach, r, c-1, n, m, reach_r, reach_c);
    if(((c+1) != m) && (a[r][c] >= a[r][c+1])) 
        reach[r][c] |= dfs(a, reach, r, c+1, n, m, reach_r, reach_c);

    return reach[r][c];
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();

    vii ra(n, vector<int>(m, -1));
    vii rp(n, vector<int>(m, -1));
    
    int rr_a = 0, rc_a = 0, rr_p = n-1, rc_p = m-1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(ra[i][j] != 1) dfs(a, ra, i, j, n, m, rr_a, rc_a);
            if(rp[i][j] != 1) dfs(a, rp, i, j, n, m, rr_p, rc_p);
        }
    }

    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            if(ra[i][j] == 1 && rp[i][j] == 1) ans.push_back({i, j});
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v[0].size(); j++)
            cin >> v[i][j];
    
    for(auto s : pacificAtlantic(v))
        cout << s[0] << '\t' << s[1] << '\n';
}