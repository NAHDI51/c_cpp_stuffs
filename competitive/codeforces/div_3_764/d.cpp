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
    int a, b , c;
    cin >> a >> b >> c;
    if((b+(b-a)) % c == 0) cout << "YES" << '\n';
    else if((b-(c-b)) % a == 0) cout << "YES" << '\n';
    else if(((c-a) % 2) && ((a + ((c-a)/2)) % b == 0)) cout << "YES" << '\n';
    else cout << "NO";
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();   
    }
}