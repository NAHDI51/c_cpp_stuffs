#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

using ll = long long;
using lll = __int128;
using vlll = vector<lll>;
using vvlll = vector<vlll>;

// O(1) for 2x2 matrix
vvlll matrix_mul(vvlll a, vvlll b) {
    if(a.empty() || b.empty()) return {};
    if(a[0].size() != b.size()) return {};

    vvlll arr(a.size(), vlll(b[0].size()));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b[0].size(); j++) {
            for(int k = 0; k < a[0].size(); k++) {
                arr[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return arr;
}

vvlll matpow(vvlll& a, ll b) {
    // initially identity matrix
    vvlll res = {
        {1,0},
        {0,1}
    };
    while(b) {
        if(b&1) res = matrix_mul(res, a);
        a = matrix_mul(a, a); 
        b >>= 1;
    }
    return res;
}

lll fib(ll n) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    vvlll iden = {
        {1,1},
        {1,0}
    };
    vvlll defo = {
        {1},
        {0}
    };
    auto matans = matrix_mul(matpow(iden, n-1), defo);
    return matans[0][0];
}

void print128(lll a) {
    string s; 
    while(a) {
        s += '0' + (a%10);
        a /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    int n;
    cin >> n;
    print128(fib(n));
    cout << '\n';
}