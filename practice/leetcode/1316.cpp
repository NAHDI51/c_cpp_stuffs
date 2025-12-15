#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int distinctEchoSubstrings(string s) {
    ll A = 9973, B = (int) 1e9+9;
    vector<ll> h(s.size()+1), p(s.size());
    h[0] = p[0] = 1;
    for(int i = 1; i < h.size(); i++)
        h[i] = ((h[i-1] * A) % B + s[i-1]) % B;
    for(int i = 1; i < p.size(); i++)
        p[i] = (p[i-1] * A) % B;
    
    auto hash = [&] (int l, int r) -> ll {
        return (h[r+1] - (h[l] * p[r-l+1]) % B + B) % B;
    };
    unordered_map<ll, bool> mp;

    for(int x = 1; x <= s.size()/2; x++) {
        for(int i = 0, j = i+x-1, p = j+1, q = p+x-1; q < s.size(); i++, j++, p++, q++) {
            if(/*!mp[hash(i, j)] && */hash(i, j) == hash(p, q)) {
                //if(s.substr(i, x) == s.substr(p, x)) {
                    mp[hash(i, j)] = true;
                //}
            } 
        }
    }

    return mp.size();
}

int main() {
    string s;
    cin >> s;
    cout << distinctEchoSubstrings(s) << '\n';
}