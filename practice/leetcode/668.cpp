#include <bits/stdc++.h>
using namespace std;

int findKthNumber(int m, int n, int k) {
    int lo = 1, hi = m*n;

    auto ok = [&m, &n, &k] (int key) -> bool {
        int ans = 0;

        pair<int, int> pos = {m, 1};
        while(pos.first > 0 && pos.second <= n) {
            while(pos.first != 0 && key < (pos.first*pos.second)) pos.first--;
            ans += pos.first;
            pos.second++;
        }
        return ans >= k;
    };
    
    /*
    while(lo <= hi) {
        int m = (lo+hi) / 2;
        if(ok(m)) ans = m, hi = m-1;
        else lo = m+1;
    }
    */
    int k = -1;
    for(int b = hi; b >= 1; b /= 2) {
        while(!ok(k+b)) k += b;
    }
    return k+1;
}

int main() {
    int n, m, k;
    cin >> m >> n >> k;
    cout << findKthNumber(m, n, k) << '\n';
}