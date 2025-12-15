#include  <bits/stdc++.h>
using namespace std;

int dp[10000][100];
bool f(vector<int>& a, int k) {
    for(int i = 0; i < a.size(); i++) 
        for(int j = 0; j < k; j++)
            dp[i][j] = 0;

    auto rnd = [&k](int n) -> int {
        return ((n % k) + k) % k;
    };
    dp[0][rnd(a[0])] = true, dp[0][rnd(-a[0])] = true;

    for(int i = 1; i < a.size(); i++) {
        for(int j = 0; j < k; j++) {
            dp[i][j] |= dp[i-1][rnd(j-a[i])];
            dp[i][j] |= dp[i-1][rnd(j+a[i])];
        }
    }
    return dp[a.size()-1][0];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        vector<int> a;
        cin >> n >> k;
        while(n--) {
            int m;
            cin >> m;
            a.push_back(m);
        }
        if(f(a, k)) cout << "Divisible\n";
        else cout << "Not divisible\n";
    }
}