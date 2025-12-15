#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <initializer_list>
#include <tuple>
using namespace std;
using ll = long long;
const int mod = 998244353;

// Fast modular exponentiation
ll modpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a, res %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int mid = k / 2; // first character must appear > mid times

        // We'll track for each of the k residue positions:
        // if we fix position i % k to 0 or 1, does it conflict?
        vector<int> val(k, -1); // -1 = ?, 0 or 1 = fixed

        bool possible = true;
        for(int i = 0; i < n; i++) {
            if(s[i] != '?') {
                int c = s[i] - '0';
                int pos = i % k;
                if(val[pos] == -1) val[pos] = c;
                else if(val[pos] != c) possible = false;
            }
        }

        if(!possible) {
            cout << 0 << "\n";
            continue;
        }

        // Count free positions
        int free_pos = 0;
        for(int i = 0; i < k; i++)
            if(val[i] == -1) free_pos++;

        // The total number of ways is 2^free_pos
        ll ans = modpow(2, free_pos);
        cout << ans << "\n";
    }
    return 0;
}
