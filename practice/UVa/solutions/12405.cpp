#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin >> t;
int cases = 0;
while(t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int res = 0;
    int rng = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '.' && i > rng) rng = i+2, res++;
    }
    cout << "Case " << ++cases << ": " << res << '\n';
}
}