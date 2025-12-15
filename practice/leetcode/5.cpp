#include <bits/stdc++.h>
using namespace std;
/*

typedef long long ll;
string longestPalindromicSubseq(string s) {
    if(s.size() == 1) return s;

    ll A = 9973, B = (int) 1e9+9;
    vector<ll> h(s.size()+1), p(s.size());
    p[0] = 1, h[0] = 1;
    for(int i = 1 ; i < s.size(); i++) 
        p[i] = (p[i-1] * A ) % B;
    
    for(int i = 1; i < h.size(); i++)
        h[i] = ((h[i-1] * A) % B + s[i-1]) % B;
    
    auto hash = [&](int l, int r) -> ll {
        return (h[r+1] - (h[l] * p[r-l+1]) % B + B) % B;
    };

    string ans = s.substr(0, 1);
    int hi = 1, l = 0;
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j <= i; j++) {
            int p = i+1, q = j-i+p;
            if(q < s.size()) 
                if(hash(j, i) == hash(p, q)) 
                    if(hi < (2 * i-j+1))
                        hi = 2 * (i-j+1), l = j;
            p++, q++;
            if(q < s.size())
                if(hash(j, i) == hash(p, q))
                    if(hi < (2*(i-j+1) + 1))
                        hi = (2 * (i-j+1)) + 1, l = j;
        }
    }
    return s.substr(l, hi);
}
*/



int longestPalindrome(string s) {
    return st()
}
int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << '\n';
}