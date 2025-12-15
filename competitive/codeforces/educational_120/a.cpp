#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using vb = vector<bool>;
using ii = pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;

int main() {
    int t;
    cin >> t;
    while(t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if(((a == b) && (c%2 == 0)) || ((b == c) && (a%2 == 0)) || ((c == a) && (b%2 == 0))) cout << "YES\n";
    else if(abs(a-b) == c) cout << "YES\n";
    else if(abs(b-c) == a) cout << "YES\n";
    else if(abs(c-a) == b) cout << "YES";
    else cout << "NO\n";
    }
}