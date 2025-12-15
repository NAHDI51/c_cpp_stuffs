#include <bits/stdc++.h>
using namespace std;

void f(vector<pair<int, int>>& a) {
    map<pair<int, int>, int> indx;
    for(int i = 0; i < a.size(); i++) indx[a[i]] = i;
    sort(a.begin(), a.end());
    vector<int> dp(a.size());
    vector<int> sol(a.size());

    dp[0] = 1, sol[0] = -1;
    int mx = 1, mx_indx = 0;
    for(int i = 1; i < a.size(); i++) {
        dp[i] = 1, sol[i] = -1;
        for(int j = 0; j < i; j++) {
            if(a[i].first > a[j].second && a[i].second > a[j].second) {
                if(dp[j]+1 > dp[i]) {
                    dp[i] = dp[j+1], sol[i] = j;
                }
            }
        }
        if(mx < dp[i]) mx = dp[i], mx_indx = i;
    }
    cout << mx << '\n';
    int idx = mx_indx;
    while(idx != -1) {
        cout << indx[a[idx]]+1 << '\n';
        idx = sol[idx];
    }
}

/*
int main() {
    vector<pair<int,int>> vp;
    int i, j;
    while(scanf("%d %d", &i, &j) != 2) 
        vp.push_back({i, j});
    f(vp);
    return 0;
}
*/

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vp;
    while(n--) {
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    f(vp);
    return 0;
}