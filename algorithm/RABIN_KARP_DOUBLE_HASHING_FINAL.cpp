
#include <bits/stdc++.h>

#define ll long long
void rabin_karp_double_hashing(string& s) {
    int n = s.size();
 
    // Two different base-mod pairs
    const ll a1 = 911382, b1 = 1000000007LL;
    const ll a2 = 972663, b2 = 1000000009LL;
 
    // Prefix hashes and powers for both hash functions
    vector<ll> h1(n+1, 0), p1(n+1, 1);
    vector<ll> h2(n+1, 0), p2(n+1, 1);
 
    for (int i = 0; i < n; i++) {
        h1[i+1] = (h1[i] * a1 + (s[i] - 'a' + 1)) % b1;
        p1[i+1] = (p1[i] * a1) % b1;
 
        h2[i+1] = (h2[i] * a2 + (s[i] - 'a' + 1)) % b2;
        p2[i+1] = (p2[i] * a2) % b2;
    }
 
    auto hash_pair = [&](int l, int r) -> pair<ll,ll> {
        ll x1 = (h1[r+1] - h1[l] * p1[r-l+1]) % b1;
        if (x1 < 0) x1 += b1;
 
        ll x2 = (h2[r+1] - h2[l] * p2[r-l+1]) % b2;
        if (x2 < 0) x2 += b2;
 
        return {x1, x2};
    };
}