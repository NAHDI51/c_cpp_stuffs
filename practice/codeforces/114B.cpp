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

int n, m;
int best = 0;
vs res;
vs names;

void go(int set, int i, vii& adj) {
    if(i == n) {
        if(best < onec(set)) {
            best = onec(set);
            res = vs();
            forn(i, n) if(set&(1<<i)) res.pb(names[i]);
        }
        return;
    }
    go(set, i+1, adj);
    for(auto e : adj[i]) {
        //see if any set is up, that is not compatible with the current element.
        if(set&(1<<e)) return;
    }
    //If not, we can simply add that set.
    set |= (1<<i);
    //cout << set << '\n';
    go(set, i+1, adj);
    //set &= !(1<<i);
}

void solve() {
    cin >> n >> m;
    map<string, int> ind;
    forn(i, n) {
        string s; 
        cin >> s;
        names.pb(s);
        ind[s] = i;
    }
    vii adj(n);
    forn(i, m) {
        string a, b;
        cin >> a >> b;
        auto ai = ind[a], bi = ind[b];
        adj[ai].pb(bi);
        adj[bi].pb(ai);
    }
    int set = 0;
    go(set, 0, adj);
    cout << best << '\n';
    sort(all(res));
    forn(i, res.sz())  cout << res[i] << '\n';
}   

int main() {
    solve();

}

