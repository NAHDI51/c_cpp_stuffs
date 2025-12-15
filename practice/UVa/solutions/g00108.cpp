#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<vector<int>> pref(n+1, vector<int>(n+1, 0));
    for(int i = 1; i < pref.size(); i++)
        for(int j = 1; j < pref.size(); j++)    
            pref[i][j] = a[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
    
    int mx = INT_MIN;
    for(int i = 1; i < pref.size(); i++) 
        for(int j = 1; j < pref.size(); j++)
            for(int k = i; k < pref.size(); k++)
                for(int l = j; l < pref.size(); l++)
                    mx = max(mx, pref[k][l] - pref[i-1][l] - pref[k][j-1] + pref[i-1][j-1]);

    cout << mx << '\n';
    return 0;
}