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
        if(b&1) sm *= b;
        a *= a;
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
 
void solve() {
    ll n, m;
    cin >> n >> m;
    vll bits(64);
 
    ll sm = 0;
    forn(i, m) {
        int a;
        cin >> a;
        int k = 0;
        while(!(a&(1<<k))) k++;
        bits[k]++;
        sm += a;
    }
 
    ll ans = 0;
    if(sm < n) cout << -1 << '\n';
    else {
 
    forn(i, 63) {
        //Just expand the previously used bits.
        if(!(n&(1LL<<i))) {
            bits[i+1] += (bits[i]/2);
            bits[i] -= bits[i]/2;
        } else {
            if(bits[i]) {
                bits[i]--;
                bits[i+1] += bits[i]/2;
                bits[i] -= bits[i]/2;
            } else {
                int k = i;
                while(k < 64 && !bits[k]) k++;
                bits[i] += modpow(2, k-i);
                bits[k]--;
                bits[i]--;
                bits[i+1] += bits[i]/2;
                bits[i] -= bits[i]/2;
                ans += (k-i);
            }
            //cout << ans << '\n';
        }
    }
    cout << ans << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}