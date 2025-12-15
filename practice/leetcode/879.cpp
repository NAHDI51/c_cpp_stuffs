#include <bits/stdc++.h>
using namespace std;

//TLE
/*
#define maxN 102
const int mod = (int)1e9+9;
int knapsack[maxN][maxN];
int profitableSchemes(int n, int minProfit, vector<int>& g, vector<int>& p) {
    //Pick 0 elements to make 0.
    knapsack[0][0] = 1;
    for(int i = 1; i <= g.size(); i++) {
        for(int j = 0; j <= n; j++) {
            knapsack[i][j] = knapsack[i-1][j];  //We exclude the element.
            if(j >= g[i-1]) knapsack[i][j] = max(knapsack[i][j], knapsack[i-1][j-g[i-1]]+p[i-1]);   //otherwise, we include and add the profit
        }
    }
    int maxProfit = knapsack[g.size()][n];

    //dp[i][j][k] represents the number of ways we can make k profit with j weights using some of the first i elements.
    vector<vector<vector<int>>> dp(g.size()+1, vector<vector<int>>(n+1, vector<int>(maxProfit+1, 0)));

    //Of course making 0 prof with 0 weight and using 0 elements will yield 1 value.
    dp[0][0][0] = 1;
    for(int i = 1; i <= g.size(); i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k <= maxProfit; k++) {
                dp[i][j][k] = dp[i-1][j][k]%mod, dp[i][j][k] %= mod;
                if(j>=g[i-1] && k>=p[i-1]) dp[i][j][k] += dp[i-1][j-g[i-1]][k-p[i-1]]%mod;
                dp[i][j][k] %= mod;
            }
        }
    }
    int cnt = 0;
    for(int i = minProfit; i <= maxProfit; i++) 
        for(int j = 0; j <= n; j++)
            cnt += dp[g.size()][j][i]%mod, cnt %= mod;

    return cnt;
}
*/
//ACCEPTED
#define maxN 102
#define maxProf 2301
const int mod = (int)1e9+7;
int knapsack[maxN][maxN];
int profitableSchemes(int n, int minProfit, vector<int>& g, vector<int>& p) {
    //Pick 0 elements to make 0.
    
    knapsack[0][0] = 1;
    for(int i = 1; i <= g.size(); i++) {
        for(int j = 0; j <= n; j++) {
            knapsack[i][j] = knapsack[i-1][j];  //We exclude the element.
            if(j >= g[i-1]) knapsack[i][j] = max(knapsack[i][j], knapsack[i-1][j-g[i-1]]+p[i-1]);   
            //otherwise, we include and add the profit
        }
    }
    int maxProfit = knapsack[g.size()][n];

    //dp[i][j][k] represents the number of ways we can make k profit with j weights using some of the first i elements.
    //vector<vector<vector<int>>> dp(g.size()+1, vector<vector<int>>(n+1, vector<int>(maxProfit+1, 0)));
    int dp[maxN][maxN][maxProf];

    //Of course making 0 prof with 0 weight and using 0 elements will yield 1 value.
    dp[0][0][0] = 1;
    for(int i = 1; i <= g.size(); i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k <= maxProfit; k++) {
                dp[i][j][k] = dp[i-1][j][k];
                if(j>=g[i-1] && k>=p[i-1]) dp[i][j][k] += dp[i-1][j-g[i-1]][k-p[i-1]];
                dp[i][j][k] %= mod;
            }
        }
    }
    int cnt = 0;
    for(int i = minProfit; i <= maxProfit; i++) 
        for(int j = 0; j <= n; j++)
            cnt += dp[g.size()][j][i], cnt %= mod;

    return cnt;
}

int main() {
    int n, k, mn;
    cin >> k >> mn >> n;
    vector<int> g(n), p(n);
    for(int i = 0; i < n; i++) cin >> g[i];
    for(int i = 0; i < n; i++) cin >> p[i];
    cout << profitableSchemes(k, mn, g, p) << '\n';
}