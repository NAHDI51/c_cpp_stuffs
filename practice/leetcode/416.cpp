#include <bits/stdc++.h>
using namespace std;

using vi=vector<int>;
using vii = vector<vi>;
bool canPartition(vector<int>& a) {
    int sm = 0;
    for(auto x : a) sm += x;

    if(sm%2) return false;
    bool dp[20002];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;

    for(int i = 0; i < a.size(); i++) {
        for(int j = 20001; j >= 0; j--) {
            if(dp[j]) dp[j+a[i]] = true;
        }
    }
    return dp[sm/2];
}

int main() {
    vector<int> a;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << canPartition(a) << '\n';
}