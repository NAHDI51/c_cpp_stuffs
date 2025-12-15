#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using vb = vector<bool>;
using ii = pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using table = unordered_map<unsigned long, int>;

#define f first
#define s second

#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, a, b) for(int i = a; i <= b; i++)
#define for1n(i, n) for(int i = 1; i <= n; i++)
#define rof(i, n) for(int i = n-1; i >= 0; i--)
#define rofe(i, a, b) for(int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
#define dsc(type) greater<type>

#define Flag cout << "Reached here.\n"

#define pb push_back
#define pbb pop_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert
#define maxN 

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 1000000000
#define MIN -MAX

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

#define mod 1000000007LL

ll modpow(ll a, ll b) {
    ll sm = 1;
    while(b) {
        if(b&1) sm *= a, sm %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return sm;
}

ll nCr(ll n, ll k) {
    ll ans=1, sm = 1;

    for(int j = 1 ; j <= k ; j++ , n--) {
        if(n%j==0) ans*=n/j;
        else if(ans%j==0) ans=ans/j*n;
        else ans=(ans*n)/j;
        ans %= mod;
        if(j%2 == 0) sm += ans, sm %= mod;
    }
    return sm;
}

void solve(){
    ll n, k;
    cin >> n >> k;

    if(k == 0) {
        cout << 1 << '\n';
        return;
    }
    vvll dp(k, vll(2));
    //ways to turn on even number of one bit on a string of length n.
    ll ways = modpow(2LL, n-1);

    //Number of ways to place an even number of one bit.
    dp[0][1] = ways;

    //One exceptional even way to win being in the lead.
    if(n%2 == 0) dp[0][0] = 1, dp[0][1] -= 1;
    //One odd way
    if(n%2 == 1) dp[0][1]++;

    dp[0][0] %= mod, dp[0][1] %= mod;

    ll p = modpow(2LL, n) % mod;
    for(int i = 1; i < k; i++) {
        dp[i][0] = ((p*dp[i-1][0]) % mod);
        dp[i][1] = ((ways * dp[i-1][1]) % mod);
        //One even way to lead win leads us to use the previously calculated equal values.
        if(n%2 == 0) dp[i][0] += dp[i-1][1], dp[i][1] -= dp[i-1][1];
        else if(n%2 == 1) dp[i][1] += dp[i-1][1];

        dp[i][0] %= mod, dp[i][1] %= mod;
    }
    cout << dp[k-1][0] << ' ' << dp[k-1][1] << '\n';
    cout << ((dp[k-1][0] + dp[k-1][1]) % mod) << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}