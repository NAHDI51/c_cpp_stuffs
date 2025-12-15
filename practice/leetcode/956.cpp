#include <bits/stdc++.h>
using namespace std;

/*
//TLE (N*(sum^2))
bool dp[5001][5001];
int tallestBillboard(vector<int>& a) {
    int sm = 0;
    for(auto x : a) sm += x;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    for(int k = 0; k < a.size(); k++) {
        for(int i = sm/2; i >= 0; i--) {
            for(int j = sm/2; j >= 0; j--) {  
                if(dp[i][j]) dp[i+a[k]][j] = true, dp[i][j+a[k]] = true;
            }
        }
    }
    int mx = 0;
    for(int i = 0; i < 5001; i++) if(dp[i][i]) mx = max(mx, i);
    return mx;
}
*/

//Dif recording approach
int tallestBillboard(vector<int>& a) {
    int sm = 0;
    for(auto x : a) sm += x;

    //Let dp[i][j] be the highest num A such that A-B = diff, that has been found in the first i elements.
    int dp[21][5001];
    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;
    
    //Either choose the increased difference, or choose previously calculated difference
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j <= sm; j++) {
 
            if(dp[i][j] == -1) continue;

            //THe longer becomes longer
            if(j+a[i] <= sm) dp[i+1][j+a[i]] = max(dp[i][j]+a[i], dp[i][j+a[i]]);
            //We add to shorter and it still remains shorter
            if(a[i] < j) dp[i+1][j-a[i]] = max(dp[i][j], dp[i][j-a[i]]);
            //We add to shorter and make it logner.
            else dp[i+1][a[i]-j] = max(a[i]+dp[i][j]-j, dp[i][a[i]-j]);
        }
    }
    return dp[a.size()][0];
}


int main() {
    vector<int> v;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        v.push_back(m);
    }
    cout << tallestBillboard(v) << '\n';
}