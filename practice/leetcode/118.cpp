#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int n) {
    vector<vector<int>> ans(n);
    ans[0] = {1};
    for(int i = 1 ; i < n; i++) {
        ans[i].resize(ans[i-1].size() + 1);
        ans[i][0] = 1;
        for(int j = 1; j < ans[i].size()-1; j++) 
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];

        ans[i][ans[i].size()-1] = 1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for(auto x : generate(n)) {
        for(auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}