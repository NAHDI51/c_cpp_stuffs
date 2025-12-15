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
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

#define pb push_back
#define pbb pop_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 1000000000
#define MIN -MAX

#define clr(x, y) memset(x, y, sizeof(x))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

#define mod 1000000007LL

ll modpow(ll a, ll b) {
    ll sm = 1;
    while(b) {
        if(b&1) sm *= a, sm %= mod;
        a *= a, a &= mod;
        b >>= 1;
    }
    return sm;
}

ll nCr(ll n, ll r) {
    ll ans = 1;
    r = min(r, n-r);

    /*
    Formula used:
        nCr = (nPr / r!)
    */

    for(int j = 1; j <= r; j++, n--) {
        /*
        If n/j is an integer, we simply multiply it. 
        if ans/j is an integer, we do else if.
        Otherwise, (ans*n)/j must necessarily be an integer, because at any given circumstance
        in the loop, the result should be an integer.
        */
        if(!(n%j)) ans *= n/j;
        else if(!(ans%j)) ans = (ans/j) * n;
        else ans = (ans*n)/j;
        ans %= mod;
    }
    return ans;
}

vi fact(ll n) {
    vi fac;

    // Notice that all indices of i will be prime numbers. 
    // Once one prime number is added, we will remove it from the original number
    // using n = n/i. 

    while(n%2 == 0) n /= 2, fac.pb(2);
    for(int i = 3; i * i <= n; i += 2)
        //While is needed to record multiple occurrences of a single prime number 
        while(n%i == 0) fac.pb(i), n /= i;

    // Final cornercase
    if(n > 1) fac.pb(n);
    return fac;
}

#define maxN 300005

class ft {
int sz;
vll bit;
public:
ft(int n) {
    sz = n+3;
    bit = vll(sz, 0);
}
void upd(int i, ll val) {
    for(; i < bit.sz(); i += i&-i) bit[i] += val;
}
void upd(int l, int r, ll val) {
    upd(l, val), upd(r+1, -val);
}
ll get(int i) {
    ll sm = 0;
    for(; i > 0; i -= i&-i) sm += bit[i];
    return sm;
}

void clear() {
    forn(i, bit.sz()) bit[i] = 0;
}
};

ll lq[maxN], rq[maxN], vq[maxN];
vi sp[maxN];
int lv[maxN], rv[maxN];
vi mid[maxN];
unsigned long long req[maxN];

void solve() {
    int n, m;
    cin >> n >> m;
    
    for1n(i, n) sp[i] = vi{};
    for1n(i, m) {
        int bel;
        cin >> bel;
        sp[bel].pb(i);
    }
    for1n(i, n) cin >> req[i];
    int q;
    cin >> q; 
    for1n(i, q) cin >> lq[i] >> rq[i] >> vq[i];
    for1n(i, n) lv[i] = 1, rv[i] = q+1;
    bool dec = true;
    
    ft t(m+1);
    while(dec) {
        t.clear();
        dec = false;
        for1n(i, n) if(lv[i] != rv[i]) mid[(rv[i]+lv[i])/2].pb(i);

        for1n(i, q) {
            if(lq[i] > rq[i]) t.upd(lq[i], m, vq[i]), t.upd(1, rq[i], vq[i]);
            else t.upd(lq[i], rq[i], vq[i]);

            while(mid[i].sz()) {
                auto v = mid[i].back();
                mid[i].pbb();
                dec = true;
                unsigned long long sm = 0;
                for(auto st : sp[v]) sm += t.get(st);
                if(sm < req[v]) lv[v] = i+1;
                else rv[v] = i;
            }
        }
    }
    
    for1n(i, n) {
        assert(lv[i] == rv[i]);
        if(lv[i] > q) cout << "NIE\n";
        else cout << lv[i] << '\n';
    }
}

int main() {
    FASTIO;
    solve();
}

