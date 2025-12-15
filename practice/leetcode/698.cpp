#include <bits/stdc++.h>
using namespace std;

bool canPartitionKSubsets(vector<int>& a, int k) {
    if(k == 1) return true;

    int n = a.size();
    int bit = 0;
    for(int i = 0; i < n; i++) bit |= (1<<i);
    
    bool dp[16][1<<16];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i < (1<<n); i++) dp[0][i] = true;

    for(int i = 1; i < k; i++) {
        for(int j = 1; j < )
    }
}

int main() {
}