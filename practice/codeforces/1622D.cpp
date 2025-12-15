#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 998244353;
//sq(N)
bool is_prime(int n) {
    if(n%2 == 0) return false;
    for(int i = 3; (i * i) <= n; i += 2)  
        if(n % i == 0) return false;
    return true;
}

int divisors(int n, int i) {
    int d = 0, po = i;
    while(po <= n) 
        d += (n / po), po *= i;

    return d;
}

//O(N * sq(N))
//Factorizes N using factorial formula
unordered_map<int, int> factorial(int n) {
    unordered_map<int, int> factors;
    if(n >= 2) factors[2] = divisors(n, 2);
    for(int i = 3 ; i <= n; i++) 
        if(is_prime(i)) factors[i] = divisors(n, i);

    return factors;
}

//log(A) * log(b)
ll modpow(int a, int b) {
    ll sm = 1, A = a;
    while(b) {
        if(b&1) sm *= A, sm %= mod;
        A *= A, A %= mod;
        b >>= 1;
    }
    return sm;
}

int nCr(int N, int K) {
    if(N == K || K == 0) return 1;
    else if(K < 0 || K > N) return 0;

    auto n = factorial(N);
    auto k = factorial(K);
    auto n_k = factorial(N-K);

    for(auto x : k) {
        int num = x.first, times = x.second;
        n[num] -= times;
    }
    for(auto x : n_k) {
        int num = x.first, times = x.second;
        n[num] -= times;
    }
    ll res = 1;
    for(auto x : n) {
        int num = x.first, times = x.second;
        res *= modpow(num, times);
        res %= mod;
    }
    return res;
}
/*
Strategy:
We go through indexes, calculate values for the flipped values of the bit, as all the values
with the current bit has already been calculated.
Keep this up, and we get our answer.
*/

ll solve(string s, int n, int k) {
    if(k == 0) return 1;
    ll res = 0;
    int i = 0, ones = 0;
    while(i != n && ones != k) if(s[i++] == '1') ones++;
    if(i == n && ones != k) return 1;
    i--;

    res += nCr(i+1, k);
    res %= mod;

    ones = 0;
    while(s[ones] != '1') ones++;
    int j = 0;

    for(i++; i < n; i++) {
        if(s[i] == '1') {
            j = ++ones;
            while(s[ones] == '0') ones++; //Find the next ones
            res += nCr(i-j, k);
        } else {
            res += nCr(i-j, k-1);
        }
        res %= mod;
    }
    return res;

}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    cout << solve(s, n, k) << '\n';
}