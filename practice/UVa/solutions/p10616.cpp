#include <bits/stdc++.h>
using namespace std;

int db;
int M;
int dp[25][210][20];
int f(vector<int>& a, int sm, int k, int m) {
    //What if k > a.size() & m != M)
    if(m == M && sm == 0) return 1;
    if(m == M && sm != 0) return 0;
    if(k == a.size()) return 0;
    if(dp[sm][k][m] != -1) return dp[sm][k][m];

    dp[sm][k][m] = f(a, sm, k+1, m) + f(a, (sm+a[k])%db, k+1, m+1);
    return dp[sm][k][m];
}

/*
TESTCASE
10 2
1 2 3 4 5 6 7 8 9 10
5 1
5 2

5 1
2 3 4 5 6
6 2

0 0
*/

int main() {
    int t = 0;
    while(1) {
        int n, q;
        cin >> n >> q;
        if(n == 0 && q == 0) break;
        vector<int> a;
        while(n--) {
            int m;
            cin >> m;
            a.push_back(m);
        }
        cout << "SET " << ++t << ":\n";
        for(int i = 1; i <= q; i++) {
            int d, m;
            cin >> d >> m;
            db = d;
            M = m;
            memset(dp, -1, sizeof(dp));
            cout << "QUERY " << i << ": " << f(a, 0, 0, 0) << '\n';
        }
    }
    return 0;
}