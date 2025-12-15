#include <bits/stdc++.h>
using namespace std;

//Let dp[i][j] be 
int dp[1001][1001];
int maximumScore(vector<int>& a, vector<int>& p) {
    dp[0][0] = 0;
    for(int i = 0; i < p.size(); i++) {
        for(int j = 0; j < p.size(); j++) {
            dp[i+1][j] = dp[i][j] + (a[i] * p[i+j]);
            dp[i][j+1] = dp[i][j] + (a[a.size()-1-j] * p[i+j]);
        }
    }
    int mx = INT_MIN;
    for(int i = 0; i <= a.size(); i++) 
        mx = max(mx, dp[i][a.size()-i]);
    return mx;
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
    int m;
    cin >> m;
    vector<int> p
    cout << maximumScore()
}