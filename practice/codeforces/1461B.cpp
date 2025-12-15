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

vii bel, sol;
int n, m;
//Get the below heights for each of the bnlock.
//For each of the blocks, see if it is valid, and expand it by calculating the minimum of the below lengths.
//Total answer iterating each of the block is your answer,

bool ok(vs& a, int l, int r, int row) {
    return (0 <= l) && (r < m) && (a[row][l] == '*') && (a[row][r] == '*');
}

int get(vs& a, int row, int col) {
    int p = row, q = col;
    //cout << "Reached here. " << p << ' ' << q << '\n';
    if(a[row][col] != '*') return 0;
    int ans = 0;
    int mn = MAX;
    int l = col, r = col;
    while(row < n && ok(a, l, r, row) && mn >= row) {
        mn = min({mn, row+bel[row][l]-1, row+bel[row][r]-1});
        ans++;
        l--, r++;
        row++;
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    vs a(n);
    forn(i, n) cin >> a[i];
    
    bel.rsz(n);
    sol.rsz(n);
    forn(i, n) bel[i].rsz(m), sol.rsz(m);

    forn(i, n) {
        forn(j, m) {
            if(a[i][j] == '*') {
                int k = i;
                int tm = 0;
                while(k != n && a[k][j] == '*') tm++, k++;
                bel[i][j] = tm;
            }
        }
    }
    int ans = 0;
    forn(i, n) {
        forn(j, m) {
            //cout <<  get(a, i, j) << ' ';
            ans += get(a, i, j);
        }
        //cout << '\n';
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while((t--)) {
        solve();
    }

}

