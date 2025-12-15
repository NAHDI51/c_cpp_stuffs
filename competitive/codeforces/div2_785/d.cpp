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
using pll = pair<ll,ll>;
using vpl = vector<pll>;
using vpll = vector<vpl>;

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
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

#define pb push_back
#define pbb pop_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert

#define lb(a, val) lower_bound(all(a), val);
#define ub(a, val) upper_bound(all(a), val);

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 1000000000
#define MIN -MAX

#define mod 1000000007LL

#define clr(x, y) memset(x, y, sizeof(x))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

ll binpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a, res %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return res;
}

vi fct(ll n) {
    vi fac;
    while(n%2 == 0) n /= 2, fac.pb(2);
    for(int i = 3; i * i <= n; i += 2) 
        while(n%i == 0) fac.pb(i), n /= i;
    if(n > 1) fac.pb(n);
    return fac;
}

ll gcd(ll a, ll b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a*b) / gcd(a, b);
}

#define maxN 
ll b, q, y, c, r, z;
vll facts;
void divs(ll n)
{
    // Vector to store half of the divisors
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
 
            // check if divisors are equal
            if (n / i == i) facts.pb(i);
            else {
                facts.pb(i), facts.pb(n/i);
            }
        }
    }
    if(r%q) {
        cout << 0 << '\n';
        return;
    }
    ll one = c, two = c + ((z-1)*r);
    //cout << one << ' ' <<  two << '\n';
    if(((one-b)%q) || ((two-b)%q)) {
        cout << 0 << '\n';
        return;
    }
    ll onepos = ((one-b)/q)+1;
    ll twopos = ((two-b)/q)+1;

    if(onepos < 0 || onepos > y || twopos < 0 || twopos > y) {
        //Flag;
        cout << 0 << '\n';
        return;
    }
    //Get the inverval.
    ll bint = r/q;

    //Flag;
    ll ans = 0;
    forn(i, facts.sz()) {
        if((onepos-lcm(facts[i],bint)) < 0 || (twopos+lcm(facts[i], bint) > y)) {
            cout << 0 << '\n';
            return;
        }
        //We can walk at least 0, at most lcm(facts[i], bint) steps.
        ans += (binpow(lcm(facts[i],bint)%mod, 2));
        ans %= mod;
    }
    cout << ans << '\n';
}
void solve() {
    cin >> b >> q >> y >> c >> r >> z;
    facts = vll{};
    divs(z);
}

int main() {
    FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

