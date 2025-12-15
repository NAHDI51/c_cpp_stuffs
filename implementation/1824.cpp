#include <bits/stdc++.h>
using namespace std;

int dp[3][500005];
int N;
#define MAX 1000000
int dynamic(int n, int lane, vector<int>& obs) {
    if(n == N) dp[lane][n] = 0;
    if((obs[n]-1) == lane) return MAX;
    if(dp[lane][n] != -1) return dp[lane][n];

    int one = (lane == 0) ? 0 : 1;
    int two = (lane == 1) ? 0 : 1;
    int three = (lane == 2) ? 0 : 1;

    return min({dynamic(n+1, 0, obs)+one, dynamic(n+1, 1, obs)+two, dynamic(n+1, 2, obs)+three});
}

int minSideJumps(vector<int>& obs) {
    memset(dp, -1, sizeof(dp));
    N = obs.size()-1;
    return dynamic(0, 1, obs);
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