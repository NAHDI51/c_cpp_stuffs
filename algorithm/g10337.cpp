#include <bits/stdc++.h>
using namespace std;

#define mx 100000000
int main() {
    int n;
    cin >> n;
    while(n--) {
        int dp[1002][12];
        int off[1002][12];
        int x;
        cin >> x;
        x /= 100;
        memset(dp, 0, sizeof(dp));
        memset(off, 0, sizeof(off));
        for(int i = 0; i < 12; i++) off[0][i] = off[x+1][i] = mx;
        for(int i = 1; i <= x; i++) off[i][0] = off[i][11] = mx;
        for(int i = 1; i <= 10; i++)
            for(int j = 1; j <= x; j++)
                cin >> off[j][i];
        for(int i = 0; i < 12; i++) dp[0][i] = mx;
        dp[0][1] = 0;

        for(int i = 1; i <= x; i++) 
            for(int j = 1; j <= 10; j++)
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]});
        
        cout << dp[x][1] << '\n';
    }
    return 0;
}