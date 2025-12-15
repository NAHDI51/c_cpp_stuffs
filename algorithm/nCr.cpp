#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9+7;

ll nCr(int n,int k)
{
    ll ans=1;
    k= (k > n-k) ? n-k : k;

    for(int j=1 ; j<=k ; j++, n--) {
        if(n % j == 0) ans *= n / j;
        else if(ans % j == 0) ans = ans / j * n;
        else ans = (ans * n) / j;

        ans %= mod;
    }
    return ans;
}

int main() {
    cout << nCr(20, 5) << '\n';
}
