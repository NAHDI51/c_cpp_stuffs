 #include <bits/stdc++.h>
 using namespace std;

typedef long long ll;
void f() {
    string rev = "ffeeddccbbaa";
    string match = "aabbccddeeff";

    ll A = 9973, B = (int)1e9+9, hsh = 0;

    for(int i = 0 ; i< match.size(); i++) hsh = ((hsh * A) % B + match[i]) % B;

    vector<ll> h(rev.size()+1), p(rev.size()+1);
    h[h.size()-1] = 1, p[0] = 1;

    for(int i = 1; i < p.size() ; i++) p[i] = (p[i-1] * A) % B;
    for(int i = h.size()-2; i >= 0; i--) h[i] = ((h[i+1] * A) % B + rev[i+1]) % B;

    auto hash = [&] (int l, int r) -> ll {
        for(int i = 0; i < p.size(); i++) {
            ll st = ((h[l] - (h[r+1] * p[i]) % B + B) % B);
            cout << i << '\t' << st;
            if(hsh == st) cout << '\t' << "Matches.";
            cout << '\n';
        }
    };

    cout << hsh << '\n';
    cout << hash(0, 11) << '\n';
}
int main() {
    f();
}