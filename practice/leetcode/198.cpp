#include <bits/stdc++.h>
using namespace std;

//O(N^2)
/*
int rob(vector<int>& a) {
    vector<int> dp(a.size());
    dp[0] = a[0], dp[1] = a[1];

    for(int i = 2; i < a.size(); i++) {
        for(int j = 0; j <= i-2; j++) 
            dp[i] = max(dp[i], dp[j]+a[i]);
    }
    return dp.back();
}
*/

//O(N)
int rob(vector<int>& a) {
    if(a.size() == 1) return a[0];
    if(a.size() == 2) return max(a[0], a[1]);

    vector<int> dp(a.size());
    dp[0] = a[0], dp[1] = a[1];
    int mx = a[0], vmx = max(dp[0], dp[1]), j = 0;

    for(int i = 2; i < a.size(); i++) {
        dp[i] = mx + dp[0];
        if(mx != vmx && j-i >= 1) mx = vmx, j = i;
    }
    return ans;
}

int main() {

}