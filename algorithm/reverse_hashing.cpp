#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void f() {
    string s = "abcdefghij";
    string t = "jihgfedcba";

    ll A = 9973, B = (int) 1e9+9;
    vector<ll> hr(s.size()+1), p(s.size());
    hr[hr.size()-1] = 1, p[0] = 1;

    for(int i = hr.size()-2; i >= 0; i--)
        hr[i] = ((hr[i+1] * A) % B + s[i]) % B;
    for(int i = 1; i < p.size(); i++)
        p[i] = (p[i-1] * A) % B;
    
    ll hs = 0;
    for(int i  =0; i < t.size(); i++)
        hs = ((hs * A) % B + t[i]) % B;
    
    auto hash = [&] (int l, int r) -> ll {
        return (hr[l] - (hr[r+1] * p[l - r + 1]) % B + B) % B;
    };
    cout << hs << '\n';
    cout << hash(0, 9) << '\n';

}

int main() {
    f();
}