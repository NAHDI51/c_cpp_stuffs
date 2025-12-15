#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void f() {
    string s = "aabbccddeeffffeeddccbbaa";
    ll A = 9973, B = (int)1e9+9;

    vector<ll> h(s.size()+1), rev_h(s.size()+1), p(s.size()), pr(s.size());
    h[0] = 1, rev_h[rev_h.size()-1] = 1, p[0] = 1, pr[pr.size()-1] = 1;

    for(int i = 1; i < h.size(); i++) 
        h[i] = ((h[i-1] * A) % B + s[i-1]) % B;
    for(int i = rev_h.size()-2; i >= 0; i--)
        rev_h[i] = ((rev_h[i+1] * A) % B + s[i+1]) % B;
    for(int i = 1; i < p.size(); i++)
        p[i] = (p[i-1] * A) % B;
    for(int i = pr.size()-2; i >= 0; i--)
        pr[i] = (pr[i+1] * A) % B;
    

    
    auto hash = [&] (int l, int r) -> ll {
        return (h[r+1] - (h[l] * p[r-l+1]) % B + B) % B;
    };
    auto rev_hash = [&] (int l, int r) -> ll {
        return (h[l] - (h[r+1] * pr[r-l+2]) % B + B) % B;
    };

    string t = "aabbccddeeff";
    ll th = 0;
    for(int i = 0; i < t.size(); i++)
        th = ((th * A) % B + t[i]) % B;
    
    cout << "Main hash value: " << th << '\n';
    cout << "Base hash value: " << hash(0, 11) << '\n';
    cout << "Palindrome hash value: " << rev_hash(12, 23) << '\n';
}

int main() {
    f();
}