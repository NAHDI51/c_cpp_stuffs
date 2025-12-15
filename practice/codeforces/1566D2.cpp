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

#define MAX 1000000009
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

//Segment Tree necessary? Probably not, the constraint is small enough, can be done in O(n * m^2).

//The answer lies in being able to order the eqwual elements optimally.
/*
What makes the ordering optimal?
let's consider the following example.

...P
PPPP
P...

A number can be within three types of rows. Beginning, whole row, ending.

The greedy invariant is that we need to fill the last seats as fast as possible, and the first seats as
late as possible.

For beginning, we want to fill em out as fast as possible. For the end, we want to fill out as late as possible.
Why will this work?

Because, if we add the last as fast, we will be able to minimize the succeeding elements' inconvenience.
Same reason, for being able to secure the first seats as late as possible.
*/

//We don't have to care about middle at all. Thus, we should only care about low or high.
void solve() {
    int n, m;
    cin >> n >> m;

    vi a(n*m);
    forn(i, n*m) cin >> a[i];
    if(m == 1) {
        cout << 0 << '\n';
        return;
    } 

    auto s = a;
    sort(all(s));
    s.pb(MAX);

    vbb seat(n, vb(m));
    map<int, array<array<int, 3>, 2>> pos;
    map<int, int> mc;

    //t = first el, i = last el.
    for(int i = 0; i < n*m; i++) {
        int t = i;
        while(i != n*m && s[i] == s[i+1]) i++;

        if(t/m != i/m) {
            pos[s[i]][0] = {t/m, m-1, m-(t%m)};
            pos[s[i]][1] = {i/m, i%m, (i%m)+1};
            mc[s[i]] = (i-t+1) - (pos[s[i]][0][2] + pos[s[i]][1][2]);
        } else {
            pos[s[i]][0] = {t/m, i%m, ((i-t)%m)+1};
            pos[s[i]][1] = {t/m, -1, 0};
        }
    }
    /*
    for(auto x : pos) {
        cout << x.f << '\n';
        cout << x.s[0][0] << ' ' << x.s[0][1] << ' ' << x.s[0][2] << '\n';
        cout << x.s[1][0] << ' ' << x.s[1][1] << ' ' << x.s[1][2] << '\n';
    }
    */
    
    int ans = 0;

    //First fill pos[a[i]][0], then pos[a[i]][1]
    forn(i, n*m) {
        auto p = pos[a[i]];
        if(p[0][2]) {

            for(int i = 0; i < p[0][1]; i++) if(seat[p[0][0]][i]) ans++;
            seat[p[0][0]][p[0][1]] = true;
            pos[a[i]][0][2]--, pos[a[i]][0][1]--;

        } else if(mc[a[i]]) mc[a[i]]--;
        else if(p[1][2]) {

            for(int i = 0; i < p[1][1]; i++) if(seat[p[1][0]][i]) ans++;
            seat[p[1][0]][p[1][1]] = true;
            pos[a[i]][1][2]--, pos[a[i]][1][1]--;

        }
        //Flag;
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

