#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& a) {
    sort(a.begin(), a.end());
    int cnt = 0, end = a[0][1];
    for(int i = 1; i < a.size(); i++) {
        //If overlapping
        if(a[i][0] < end) 
            cnt++, end = min(end, a[i][1]);
        else end = a[i][1];
    }
    return cnt;
}

int main() {
    vector<vector<int>> a;
    int n;
    cin >> n;

    while(n--) {
        int m, p;
        cin >> m >> p;
        a.push_back({m,p});
    }
    cout << eraseOverlapIntervals(a) << '\n';
}