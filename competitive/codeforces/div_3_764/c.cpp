#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;
using vl = vector<ll>;
using vll = vector<vl>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using ii = pair<int ,int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using vb = vector<bool>;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < n; i++) {
        while(a[i] > n) a[i] /= 2;
        if(a[i] == 0) {
            cout << "NO";
            return;
        }
    }
    //Occur, number
    vi hsh(n+1);
    for(auto x : a) {
        hsh[x]++;
        //cout << x << '\t';
    }
    //cout << '\n';
    //for(auto x : hsh) cout << x << '\t';
    //cout << '\n';

    while(1) {
        //cout << "reched here.\n";
        if(hsh[0] > 0) {
            cout << "NO\n";
            return;
        }
        int i = 1;
        while(i != hsh.size() && hsh[i] == 1) i++;
        if(i == hsh.size()) {
            cout << "YES\n";
            return;
        }
        for(i = 1; i < hsh.size(); i++) {
            if(hsh[i] > 0) {
                hsh[i/2] += (hsh[i]-1);
                hsh[i] = 1;
            }
        }
    }
    return;
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();   
    }
}