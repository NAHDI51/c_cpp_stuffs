#include <bits/stdc++.h>
using namespace std;

int smallestDistancePair(vector<int>& a, int key) {
    sort(a.begin(), a.end());
    int lo = 0, hi = a[a.size()-1] - a[0];

    auto ok = [&a, &key] (int dif) -> bool {
        int ans = 0;
        for(int i = 1, j = 0; i < a.size(); i++) {
            while(j < i && (a[i] - a[j]) > dif) j++;
            ans += (i-j);
        }
        return ans >= key;
    };
    int ans = 0;
    while(lo <= hi) {
        int m = (lo+hi) / 2;
        if(ok(m)) ans = m, hi = m-1;
        else lo = m+1;
    }
    return ans;
}

int main() {
    vector<int> a;
    int n, k;
    cin >> n >> k;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << smallestDistancePair(a, k) << '\n';
}