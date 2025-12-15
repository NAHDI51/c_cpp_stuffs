#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using vb = vector<bool>;
using vbb  = vector<vb>;
using ii = pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using table = unordered_map<unsigned long, int>;

#define f first
//#define s second

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
#define maxN 200003

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define clr(x, y) memset(x, y, sizeof(x))

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
        if(b&1) sm *= b, sm %= mod;
        a *= a, a &= mod;
        b >>= 1;
    }
    return sm;
}

ll nCr(ll n, ll r) {
    ll ans = 1;
    r = min(r, n-r);

    for(int j = 1; j <= r; j++, n--) {
        if(!(n%j)) ans *= n/j;
        else if(!(ans%j)) ans = (ans/j) * n;
        else ans = (ans*n)/j;
        ans %= mod;
    }
    return ans;
}

vi fact(ll n) {
    vi fac;
    while(n%2 == 0) n /= 2, fac.pb(2);
    for(int i = 3; i * i <= n; i += 2) 
        while(n%i == 0) fac.pb(i), n /= i;
    if(n > 1) fac.pb(n);
    return fac;
}

//For any matching representation, cut it out, because that number will cause overcount.

//Every number will either reach a dead end or zero.
unordered_map<ll,bool> mp;
bool dfs(ll val) {
    if(val == 0) return false;
    if(mp.find(val) != mp.end()) return true;

    bool ok = false;
    if(val&1) ok |= dfs(val>>1LL);
    else if(val%4 == 0) ok |= dfs(val>>2LL);
    return ok;
}

//Let dp[i] denote the number of ways we can make numbers such that it is smaller than 2^i+1.
//dp[i] = The number of ways we can make i-1 and i-2
//Naturally, dp[0] = 1, because that one number is 0.
//To remove the redundants, just make the numbers smaller using the method mentioned, and check if it 
//Already exists. If the number becomes zero, or we reach a conclusion, we return true.
//Otherwise, base[i]++, where i = the highest 2^i such that the answer is smaller.
//dp[p-1] is the answer, because that means we have the number of numbers smaller than 2^p.

ll dp[maxN];
void solve() {
    int n, p;
    cin >> n >> p;
    vll a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));

    memset(dp, 0, sizeof(dp));
    ll base[64]{};
    forn(i, n) {
        //Leftmost bit power size.
        int t;
        rof(k, 63) if(a[i]&(1LL<<k)) {
            t = k;
            break;
        }
        if(!dfs(a[i])) {
            mp[a[i]] = true, base[t]++;
        }
    }

    dp[0] = base[0];
    dp[1] = base[1] + dp[0];
    for(int i = 2; i < p; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        if(i < 64) dp[i] += base[i];
        dp[i] %= mod;
    }
    ll ans = 0;
    forn(i, p) 
        ans += dp[i], ans %= mod;
    
    cout << ans << '\n';
}
//Takeaway: The number of ways we can make a string s = number of performance we can do, for all the dps.
//

int main() {
    solve();

}
