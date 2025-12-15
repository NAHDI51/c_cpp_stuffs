#include <bits/stdc++.h>
using namespace std;

//Top down (O(N))
/*
int dp[3][500005];
int N;
#define MAX 1000000
int dynamic(int n, int lane, vector<int>& obs) {
    if(n == N) dp[lane][n] = 0;
    if((obs[n]-1) == lane) return MAX;
    if(dp[lane][n] != -1) return dp[lane][n];

    int one = (lane == 0) ? 0 : 1;
    int two = (lane == 1) ? 0 : 1;
    int thr = (lane == 2) ? 0 : 1;

    dp[lane][n] = MAX;
    if(obs[n] != 1) dp[lane][n] = min(dp[lane][n], dynamic(n+1, 0, obs)+one);
    if(obs[n] != 2) dp[lane][n] = min(dp[lane][n], dynamic(n+1, 1, obs)+two);
    if(obs[n] != 3) dp[lane][n] = min(dp[lane][n], dynamic(n+1, 2, obs)+thr);
    return dp[lane][n];
}

int minSideJumps(vector<int>& obs) {
    memset(dp, -1, sizeof(dp));
    N = obs.size()-1;
    return dynamic(0, 1, obs);
}
*/

//Bottom Up
#define MAX 1000000
int minSideJumps(vector<int>& obs) {
    int first = 1, second = 0, third = 1;
    for(int i = 1; i < obs.size(); i++) {
        int tmp1 = first, tmp2 = second, tmp3 = third;

        if(obs[i] == 1) first = MAX;
        else first = min({tmp1, tmp2+1, tmp3+1});

        if(obs[i] == 2) second = MAX;
        else second = min({tmp1+1, tmp2, tmp3+1});

        if(obs[i] == 3) third = MAX;
        else third = min({tmp1+1, tmp2+1, tmp3});
    }
    return min({first, second, third});
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
    cout << minSideJumps(a) << '\n';
}