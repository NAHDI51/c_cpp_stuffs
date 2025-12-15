

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

#define mod 1000000007LL

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

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

    for(ll j = 1 ; j <= k ; j++ , n--) {
        if(n%j==0) ans*=n/j;
        else if(ans%j==0) ans=ans/j*n;
        else ans=(ans*n)/j;
        ans %= mod;
        if(j%2 == 0) {
            //cout << j << ' ' << ans;
            //cout << '\n';
            sm += ans, sm %= mod;
        }
    }
    ///cout << '\n';
    return sm;
}

void solve(){
    ll n, k;
    cin >> n >> k;

    if(k == 0) {
        cout << 1 << '\n';
        return;
    }

    //nCr values till the highest evven numnber that does not divide it.
    //Why doesn't nCr summationw work?
    auto ways = modpow(2LL, n-1) /*nCr(n, n/2*2)*/;

    //Number of ways we can place any bits.
    auto power = modpow(2LL, n);

    if(n%2) {
        //Basically the number of ways to draw them in one bit, and their all possible combinations.
        cout << (modpow(ways+1, k) % mod) << '\n';
    } else {
        //We have all the possivble number of ways to draw, plus their combinations.
        auto ans = modpow(ways-1, k);
        ans %= mod;
        //Winning number = all the numbers following the struture,
        forn(i, k) {
            ans += ((modpow(ways-1, k-i-1) * modpow(power, i)) % mod);
            ans %= mod;
        }
        cout << ans << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}