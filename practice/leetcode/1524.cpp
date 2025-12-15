#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9+7);
int numOfSubarrays(vector<int>& a) {
    int odds = 0, evens = 1, t_sum = 0;
    long ans = 0;

    for(int i = 0; i < a.size(); i++) {
        t_sum += a[i];
        if(t_sum%2) ans += evens, odds++;
        else ans += odds, evens++;
        ans %= mod;
    }
    return ans;
}

int main() {
    int n;
    vector<int> a;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << numOfSubarrays(a) << '\n';
}