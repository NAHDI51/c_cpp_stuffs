#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void f() {
    string s = "aabbccddeeff";
    string t = s;
    reverse(t.begin(), t.end());

    vector<ll> h(t.size()+1), p(t.size());
    ll A = 9973, B = (int) 1e9+9;

    p[0] = 1, h[p.size()-1] = 1;
    for(int i = p.size()-2; i >= 0; i--) h[i] = ((h[i+1] * A) % B + t[i+1]) % B;
    for(int i = 1; i < p.size(); i++) p[i] = (p[i-1] * A) % B;

    auto hash = [&](vector<ll> haash, int l, int r) -> ll {
        return (haash[r+1] - (haash[l] * p[r-l+1]) % B + B) % B;
    };
    auto reverse_hash = [&] (int l, int r) -> ll {
        int l1 = t.size()-1-r, r1 = t.size()-1-l;
        return (h[l1] - (h[r1+1] * p[r-l-1]) % B + B) % B;
    };
    
    vector<ll> h1(s.size()+1);
    for(int i = 1; i < h1.size(); i++) h1[i] = ((h1[i-1] * A) % B + s[i-1]) % B;

    cout << hash(h1, 0, 11) << '\n';
    cout << reverse_hash(0, 11) << '\n';
}

int main() {
    f();
}