#include <bits/stdc++.h>
using namespace std;

#define MAX 100000000
vector<vector<int>> floyd_warshal(vector<vector<int>>& adj) {
    vector<vector<int>> ans(adj.size(), (adj.size(), vector<int>{}));
    for(int i = 0 ;i < adj.size(); i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            if(adj[i][j]) ans[i][j] = adj[i][j];
            else if(i == j) ans[i][j] = 0;
            else ans[i][j] = MAX;
        }
    }

    for(int k = 0; k < adj.size(); k++) {
        for(int i = 0; i < adj.size(); i++)
            for(int j = 0; j < adj.size(); j++)
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
    }
    return ans;
}

int main() {

}