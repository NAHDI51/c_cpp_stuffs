#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// O(NloglogN)
vector<long long> prs;
void sieve() {
    vector<int> isPrime(100001, true);
    for(int i = 2; i < 25000; i++) {
        if(isPrime[i]) {
            prs.push_back(i);
            for(int j = i; j < 25000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
/*
x, y => 1, x, y, x*y
x^3 => 1, x, x^2, x^3 
x, y prime numbers

//Binary search
2,3,5,7,11,13,17,19,23,29...
d 
least prime => 2+d

1, 2, 2+d, (2 * (2+d))

N * logN
*/

/*
f(x) => true, false;

lo = 1, hi = inf
mid = (lo + hi) / 2

if(f(mid) == true) {
    ans = mid, hi = mid - 1;
} else {
    lo = mid+1;
 }
f(1) f(2) f(3),... f(k).. => false
f(k+1) f(k+2) f(k+3)... f(inf) => true
*/

void solve() {
    long long d;
    cin >> d;
    long long mn = 1000000000000000ll;

    for(int i = 0; i < prs.size(); i++) {
        if(prs[i]-1 < d) continue;
        // Case 2
        mn = min(mn, (long long) pow(prs[i], 3));

        // Case 1
        int it = lower_bound(prs.begin(), prs.end(), prs[i]+d) - prs.begin();

        // cout << prs[i] << ' ' << prs[it] << '\n';
        if(it != prs.size()) mn = min(mn, (long long) prs[i] * prs[it]);
    }
    cout << mn << '\n';
}
int main() {
    sieve();
    int t;
    cin >> t;
    while(t--) solve();
}