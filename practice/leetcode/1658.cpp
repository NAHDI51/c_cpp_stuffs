#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& a, int x) {
    vector<int> pref(a.size()+1);
    pref[0] = 0;
    int sm = 0;
    for(int i = 1 ; i < pref.size(); i++) pref[i] = pref[i-1] + a[i-1], sm += a[i-1];
    int i = 0, j = 1;
    int ans = INT_MAX;

    while(i < j && j < pref.size()) {
        if((sm - (pref[j] - pref[i])) == x) ans = min(ans, (int)((a.size()-j) + (i-0))), j++;
        else if((sm - (pref[j] - pref[i])) < x) i++;
        else j++;
    }
    return (ans == INT_MAX) ? -1 : ans;
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
    cout << minOperations(a, k) << '\n';
}