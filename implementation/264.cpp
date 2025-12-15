#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n) {
    vector<int> dp({1, 2, 3, 4, 5});
    if(n <= 5) return dp[n-1];

    for(int i = 5; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), dp.back()/2) - dp.begin();
        while(dp[it]*2 < dp.back()) it++;
        dp.push_back(dp[it] * 2);
    }
    return dp.front();
}

int main() {

}