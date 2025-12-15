#include <bits/stdc++.h>
using namespace std;

void f(vector<vector<vector<int>>> v) {
    vector<vector<vector<int>>> pref(v.size()+1, vector<vector<int>>(v[0].size()+1, vector<int>(v[0][0].size()+1, 0)));
    for(int i = 1; i < pref.size(); i++)
        for(int j = 1; j < pref[0].size(); j++)
            for(int k = 1; k < pref[0][0].size(); k++) {
                pref[i][j][k] = v[i-1][j-1][k-1] +
                                pref[i-1][j][k] + pref[i][j-1][k] + pref[i][j][k-1] -
                                pref[i-1][j-1][k] - pref[i-1][j][k-1] - pref[i][j-1][k-1] +
                                pref[i-1][j-1][k-1];
            }
    
    auto query = [&pref](array<int, 3> p1, array<int, 3> p2) -> int {
        //Making one based
        p1[0]++, p1[1]++, p1[2]++;
        p2[0]++, p2[1]++, p2[2]++;
        return pref[p2[0]][p2[1]][p2[2]] - pref[p1[0]-1][p2[1]][p2[2]] - pref[p2[0]][p1[1]-1][p2[2]] -
               pref[p2[0]][p2[1]][p1[2]-1] + pref[p1[0]-1][p1[1]-1][p2[2]] + pref[p1[0]-1][p2[1]][p1[2]-1] +
               pref[p2[0]][p1[1]-1][p1[2]-1] - pref[p1[0]-1][p1[1]-1][p1[2]-1];
    };
}

int main() {
    vector<vector<vector<int>>> v;
    int a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i < a; i++)
        for(int j = 0; j < b; j++)
            for(int k = 0; k < c; k++)
                cin >> v[i][j][k];
    f(v);
}