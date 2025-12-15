#include <bits/stdc++.h>
using namespace std;

int maxScoreSightseeingPair(vector<int>& a) {
    int mx = 0;
    int hi = a[0];
    for(int i = 1; i < a.size(); i++) {
        mx = max(mx, hi+a[i]-i);
        hi = max(hi, a[i]+i);
    }
    return mx;
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
    cout << maxScoreSightseeingPair(a) << '\n';
}