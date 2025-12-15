#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <initializer_list>
#include <tuple>

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
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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

#define MAX 100000000000000000ll
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

#define maxN 


void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vll ap(n+1), bp(m+1), tp(n+m+1);
    for1n(i, n) cin >> ap[i];
    for1n(i, m) cin >> bp[i];
    for1n(i, n) tp[i] = ap[i];
    for1n(i, m) tp[i+n] = bp[i];

    ap[0] = MAX; bp[0] = MAX; tp[0] = MAX;
    sort(all(ap), greater<ll>{});
    sort(all(bp), greater<ll>{});
    sort(all(tp), greater<ll>{});
    
    vpi rng(n+m+1);
    rng[0] = {0,0};

    int t = n+m;
    int l = 1, r = 1;
    for1n(i, n+m) {
        if(l <= n && r <= m) {
            if(ap[l] < bp[r]) {
                tp[i] = bp[r++];
            } else {
                tp[i] = ap[l++];
            }
        } else {
            if(l > n) tp[i] = bp[r++];
            else if(r > m) tp[i] = ap[l++];
        }
        rng[i] = {l-1,r-1};
    }
    // cout << l << ' ' << r << '\n';
    
    /*
    for1n(i, n) cout << ap[i] << ' ';
    cout << '\n';
    for1n(i, m) cout << bp[i] << ' ';
    cout << '\n';
    for1n(i, m+n) cout << tp[i] << ' ';
    cout << '\n';
    /*
    for1n(i, n+m) cout << arng[i].f << ' ';
    cout << '\n';
    for1n(i, n+m) cout << arng[i].s << ' ';
    cout << '\n';
    for1n(i, n+m) cout << brng[i].f << ' ';
    cout << '\n';
    for1n(i, n+m) cout << brng[i].s << ' ';
    cout << '\n';
    */

    // Make prefix sum
    ap[0] = 0, bp[0] = 0, tp[0] = 0;
    for1n(i, n) ap[i] += ap[i-1];
    for1n(i, m) bp[i] += bp[i-1];
    auto tr = tp;
    for1n(i, m+n) tp[i] += tp[i-1];
    
    /*
    for1n(i, n+m) cout << rng[i].f << ' ';
    cout << '\n';
    for1n(i, n+m) cout << rng[i].s << ' ';
    cout << '\n';
    for1n(i, m+n) cout << tp[i] << ' ';
    cout << '\n';
    */

    /*
    auto query = [&](int a, int b, int t) -> ll {
        if(t == 0) return 0;

        ll ans = 0;
        if(a <= t) 
            ans = max(ans, ap[a] + bp[t-a]);
        else 
            ans = max(ans, ap[t]);
        if(b <= t) 
            ans = max(ans, bp[b] + ap[t-b]);
        else 
            ans = max(ans, bp[t]);

        auto arg = arng[t], brg = brng[t];
        if(arg.f <= a && brg.f <= b) {
            // check for non unique elements.
            if((t > 0 && tr[t] == tr[t-1]) || (t < n+m && tr[t] == tr[t+1])) {
                // Flag;
                auto t1 = lower_bound(tr.begin()+1, tr.end(), tr[t], greater<ll>{}) - tr.begin();
                auto need = t - t1 + 1;
                // auto past1 = (t1 > 0 ? arng[t1-1].s : 0), past2 = (t1 > 0 ? brng[t1-1].s : 0);

                auto e1 = lower_bound(ap.begin()+1, ap.end(), tr[t], greater<ll>{}) - (ap.begin()+1);
                auto e2 = lower_bound(bp.begin()+1, bp.end(), tr[t], greater<ll>{}) - (bp.begin()+1);
                auto r1 = upper_bound(ap.begin()+1, ap.end(), tr[t], greater<ll>{}) - (ap.begin());
                auto r2 = upper_bound(bp.begin()+1, bp.end(), tr[t], greater<ll>{}) - (bp.begin());
                // cout << e1 << ' ' << e2 << ' ' << r1 << ' ' << r2 << '\n';
                auto can1 = min((int) r1, a) - e1 + 1, can2 = min((int) r2, b) - e2 + 1;
                /*
                    Ok the algorithm goes as following: 
                    can1: up - lo + 1 of a
                    can2: up - lo + 1 of b
                    if can1 and can2 makes it, then good, otherwise no
                
                // cout << t << ' ' << t1 << ' ' << tr[t1] << ' ' <<  can1 << ' ' << can2 << ' ' << need << ' ' << tr[t] << '\n';
                if(can1 + can2 >= need) {
                    // Flag;
                    ans = max(ans, tp[t]);
                }
                
            } else {
                ans = max(ans, tp[t]);
            }
        }
        return ans;
    };
    */

    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        l = rng[z].first, r = rng[z].second;
        if (l > x)
            cout << ap[x] + bp[z - x] << '\n';
        else if (r > y)
            cout << ap[z - y] + bp[y] << '\n';
        else
            cout << ap[l] + bp[r] << '\n';
    }

}

int main() {
    //Sublime
    // init();
    FASTIO;

    int t;
    cin >> t;
    while(t--) solve();
}

