#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
/* 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/
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

#define MAX 2000000000
#define MIN -MAX

#define mod 1000000007LL

#define clr(x, y) memset(x, y, sizeof(x))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void init() {
    #ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    #endif
}

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

#define maxN 200005

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    vi pref(m+1);
    vi suf(m+1);
    forn(i, n) cin >> a[i];
    forn(i, m) cin >> b[i];

    int cur = 0;
    forn(i, n) {   
        if(a[i] >= b[cur]) {
            pref[cur] = i;
            cur++;
        }
        if(cur == m) break;
    }
    fore(i, cur, m) pref[i] = -1;

    cur = m-1;
    for(int i = n-1; i >= 0; i--) {
        if(a[i] >= b[cur]) {
            suf[cur] = i;
            cur--;
        }
        if(cur == -1) break;
    }
    for(int i = cur; i >= 0; i--) suf[i] = -1;
    /*
    forn(i, m) cout << pref[i] << ' ';
    cout << '\n';
    forn(i, m) cout << suf[i] << ' ';
    cout << '\n';
    */

    if(m == 1) {
        if(pref[0] == -1) {
            cout << b[0] << '\n';
        } else {
            cout << 0 << '\n';
        }
        return;
    }
    for(int k = 0; k < m-1; k++) {
        // cout << "left: " << pref[k-1] << ' ' << "right: " << suf[k+1] << '\n';
        if(pref[k] < suf[k+1] && pref[k] != -1 && suf[k+1] != -1) {
            // cout << "left: " << pref[k] << ' ' << "right: " << suf[k+1] << '\n';
            cout << 0 << '\n';
            return;
        }
    }
    if(m == 2) {
        if(pref[0] != -1 && pref[1] != -1) {
            cout << 0 << '\n';
            return;
        }
        if(pref[0] == -1 && pref[1] == -1 && suf[0] == -1 && suf[1] == -1) {
            cout << -1 << '\n';
            return;
        }
        int mn = MAX;
        if(suf[1] != -1) mn = min(mn, b[0]);
        if(pref[m-2] != -1) mn = min(mn, b[m-1]);    

        cout << mn << '\n';
        return;
    }
 
    //If we use the operation
    int mn = MAX;
    if(suf[1] != -1) mn = min(mn, b[0]);
    if(pref[m-2] != -1) mn = min(mn, b[m-1]);
    for(int k = 1; k < m-1; k++) {
        // cout << "left: " << pref[k-1] << ' ' << "right: " << suf[k+1] << '\n';
        if(pref[k-1] < suf[k+1] && pref[k-1] != -1 && suf[k+1] != -1) {
            mn = min(mn, b[k]);
        }
    }
    if(mn == MAX) {
        cout << -1 << '\n';
    } else {
        cout << mn << '\n';
    }
}

int main() {
    //Sublime
    // init();
    // FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

















