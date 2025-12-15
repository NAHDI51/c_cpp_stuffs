#include <bits/stdc++.h>
using namespace std;

map<vector<int>, int> dp;
int removeBoxes(vector<int> b) {
    if(b.size() == 0) return 0;
    if(dp.find(b) != dp.end()) return dp[b];

    dp[b] = 0;
    int j;
    for(int i = 0; i < b.size(); i++) {
        j = i;
        while(i < b.size()-1 && b[i+1] == b[i]) i++;

        vector<int> v;
        for(int k = 0; k < b.size(); k++) {
            if(j <= k && k <= i) continue;
            v.push_back(b[k]);
        }

        dp[b] = max(dp[b], ((i-j+1) * (i-j+1)) + removeBoxes(v));
    }
    return dp[b];
}

int main() {
    vector<int> v;
    int n;
    cin >> n;;
    while(n--) {
        int m;
        cin >> m;
        v.push_back(m);
    }
    cout << removeBoxes(v) << '\n';
}