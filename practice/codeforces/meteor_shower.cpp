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
#define uvll = vector<unsigned long long>;

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
#define maxN 

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

void init() {
   FASTIO;
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
}

//Range udpate and point query.

struct ftree {
int sz;
vll f;

public:
//Size will always be equal to m.
ftree(int n) {
    sz = n+1;
    f.rsz(sz);
}   
int query(int i) {
    int sm = 0;
    for(; i > 0; i -= (i&-i)) sm += f[i];
    return sm;
}
void update(int i, int val) {
    for(; i < sz; i += (i&-i)) f[i] += val;
}

void update(int l, int r, int val) {
    update(l, val);
    update(r+1, -val);
}
};

/*
A good insight on parallel bs (or on binarysearch in general): Always start with the ranges, (1, Q+1),
And Piece it into two such that if it satisfies the following criteria, mid = r, otherwise mid = l-1.

*/

bool chk(vii& mid) {
    for1n(i, mid.sz()) if(!mid[i].empty()) return false;
    return true;
}

//Parallel bs

void solve() {
    int n,m;
    cin >> n >> m;

    vii adj(n+1);
    for1n(i, m) {
        int a;
        cin >> a;
        adj[a].pb(i);
    }

    vll req(n+1);
    for1n(i, n) cin >> req[i];

    //Queries
    int q;
    cin >> q;
    vll lq(q+1), rq(q+1), vq(q+1);

    for1n(i, q) cin >> lq[i] >> rq[i] >> vq[i];

    vi L(n+1, 1), R(n+1, q+1);

    bool ok = true;
    while(ok) {
        vii mid(q+1);
        ftree tree(n+1);

        for1n(i, n) if(L[i] != R[i]) mid[(L[i]+R[i])/2].pb(i);
        if(!chk(mid)) break;

        for1n(i, q) {
            if(lq[i] > rq[i]) tree.update(lq[i], m, vq[i]), tree.update(1, rq[i], vq[i]);
            else tree.update(lq[i], rq[i], vq[i]);

            for(auto e : mid[i]) {
                int sm = 0;
                for(auto v : adj[e])
                    sm += tree.query(v);

                if(sm >= req[e]) R[e] = i;
                else L[e] = i+1;
            }
        }
    }
    for1n(i, n) {
        if(L[i] > q) cout << "NIE" << '\n';
        else cout << L[i] << '\n';
    }
}

int main() {
   init();

    int t;
    cin >> t;
    while((t--)) {
        solve();
    }

}

