#include <bits/stdc++.h>
using namespace std;

double dp[1<<16];
#define MAX 1000000000

double dist(pair<int, int>& a, pair<int, int>& b) {
    return sqrt(((a.first - b.first) * (a.first-b.first)) + ((a.second-b.second) * (a.second-b.second)));
}
double f(vector<pair<int, int>>& vp) {
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i < 1<<vp.size(); i++) {
        if(__builtin_popcount(i) % 2) continue;
        dp[i] = MAX;
        for(int j = 0; j < vp.size()-1; j++) {
            for(int k = j+1; k < vp.size(); k++) {
                if((i&(1<<j)) && (i&(1<<k))) {
                    dp[i] = min(dp[i], dp[i^(1<<j)^(1<<k)] + dist(vp[j], vp[k]));
                }
            }
        }
    }
    return dp[(1<<vp.size()) -1];
}


int main() {
    bool trig = true;
    int cnt = 0;
    while(trig) {
    int n;
    cin >> n;
    if(n == 0) break;
    n *= 2;
    vector<pair<int, int>> vp;
    while(n--) {
        string s;
        pair<int, int> m;
        cin >> s >> m.first >> m.second;
        vp.push_back(m);
    }
    printf("Case %d: %.2lf\n", ++cnt, f(vp));
    }
}