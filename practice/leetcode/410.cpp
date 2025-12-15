#include <bits/stdc++.h>
using namespace std;

int dp[1002][52];
int a[1002];
int dynamic(int n, int k) {
    if(n == 0) return INT_MAX;
    if(k == 1) return a[n] - a[0];
    if(dp[n][k] != -1) return dp[n][k];

    dp[n][k] = INT_MAX;
    for(int i = n; i >= 1; i--) dp[n][k] = min(dp[n][k], max(a[n]-a[i-1], dynamic(i-1, k-1)));
    return dp[n][k];
}

int splitArray(vector<int>& arr, int m) {
    memset(dp, -1, sizeof(dp));
    a[0] = arr[0];
    for(int i = 1; i <= arr.size(); i++) a[i] = a[i-1] + arr[i-1];
    return dynamic(arr.size(), m);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    while(n--) {
        int m;
        cin >> m;
        v.push_back(m);
    }
    cout << splitArray(v, k) <<'\n' ;
}