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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << a[n-1] - a[0] << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();   
    }
}