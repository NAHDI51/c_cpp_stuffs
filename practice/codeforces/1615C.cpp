#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < a.size(); i++)

void solve() {
    int n;
    string a, b;
    cin >> n;
    cin >> a >> b;
    int ok1, ok0, f1, f0;  
    ok1 = ok0 = f1 = f0 = 0;

    forn(i, n) {
        if(a[i] == b[i]) {
            if(a[i] == '0') ok0++;
            else ok1++;
        } else {
            if(a[i] == '0') f0++;
            else f1++;
        }
    }
    //cout << ok0 << '\t' << ok1 << '\n';
    int mx = INT_MAX;
    int mxa = INT_MAX;
    int mxb = INT_MAX;
    if(((ok0+ok1) % 2 == 1) && (ok1 == ok0+1)) mxa = ok0+ok1;
    if(((f0+f1) % 2 == 0) && (f0 == f1)) mxb = f0+f1;

    mx = min(mxa, mxb);
    if(mx == INT_MAX) mx = -1;
    cout << mx << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

}