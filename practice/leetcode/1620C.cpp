#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vector<int> bs;
    bool f = false, pf = false;
    int t = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        if(f == false && pf == true) {
            bs.push_back(t);
            t = 0;
        }
        pf = f;
        if(s[i] == '*') {
            f = true;
            t += k;
        } else f = false;
    }
    if(f == true) bs.push_back(t);
    for(auto x : bs) cout << x << '\t';
    cout << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}