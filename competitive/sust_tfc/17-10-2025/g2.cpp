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

#define MAX 1000000005
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

void solve() {
    int n;
    cin >> n;

    vi time(n);
    vi alice(n), bob(n), cod(n);
    vi bad = {-1,-1,-1};

    forn(i, n) cin >> time[i];
    forn(i, n) cin >> alice[i];
    forn(i, n) cin >> bob[i];
    forn(i, n) cin >> cod[i];

    auto distances = [n](vi& alice, vi& time, int start) -> pair<vi,vi> {
        // calculates the start & end times of each arrival
        int tm = 0;
        vi st(n), en(n);
        for(int i = 0; i < n; i++) {
            int idx = (i+start)%n;
            st[idx] = tm;
            en[idx] = tm + alice[idx];
            tm += alice[idx] + time[idx];
        }
        return {st, en};
    };

    auto overlap = [] (int s1, int e1, int s2, int e2) -> bool{
        return !(e1 <= s2 || e2 <= s1);
    };


    auto verify = [&](pair<vi,vi>& A, pair<vi,vi>& B) -> bool{
        // A.first = starts, A.second = ends
        for(int i = 0; i < n; i++) {
            if(overlap(A.first[i], A.second[i], B.first[i], B.second[i])) {
                return false;
            }
        }
        return true;
    };

    auto cycle = [&](vi& alice, vi& bob, vi& time, int start) {
        auto dalice = distances(alice, time, start);
        int idx = (start+1)%n;
        int start2 = -1;
        for(int steps = 1; steps < n; steps++) {
            auto dbob = distances(bob, time, idx);
            if(verify(dalice, dbob)) {
                start2 = idx;
                break;
            }
            idx = (idx+1)%n;
        }
        return start2;
    };

    // Calculate 
    auto cal = [&](vi& alice, vi& bob, vi& cod, int start) -> vi {
        vi bad = {-1,-1,-1};
        int start2 = cycle(alice, bob, time, start);
        if(start2 == -1) return bad;
        int start3 = cycle(bob, cod, time, start2);
        if(start3 == -1) return bad;
        // get full schedules
        auto da = distances(alice, time, start);
        auto db = distances(bob, time, start2);
        auto dc = distances(cod, time, start3);

        // ensure distinct starts
        if(start == start2 || start2 == start3 || start3 == start) return bad;

        // require all three pairwise non-overlapping
        if (verify(da, db) && verify(db, dc) && verify(dc, da)) {
            return {start, start2, start3};
        }
        return bad;
    };

    forn(i, n) {
        auto cur = cal(alice,bob,cod,i);
        if(cur != bad) {
            cout << cur[0]+1 << ' ' << cur[1]+1 << ' ' << cur[2]+1 << '\n';
            return;
        }
        cur = cal(alice,cod,bob,i);
        if(cur != bad) {
            cout << cur[0]+1 << ' ' << cur[2]+1 << ' ' << cur[1]+1 << '\n';
            return;
        }
        cur = cal(bob,alice,cod,i);
        if(cur != bad) {
            cout << cur[1]+1 << ' ' << cur[0]+1 << ' ' << cur[2]+1 << '\n';
            return;
        }
        cur = cal(bob,cod,alice,i);
        if(cur != bad) {
            cout << cur[1]+1 << ' ' << cur[2]+1 << ' ' << cur[0]+1 << '\n';
            return;
        }
        cur = cal(cod,alice,bob,i);
        if(cur != bad) {
            cout << cur[2]+1 << ' ' << cur[0]+1 << ' ' << cur[1]+1 << '\n';
            return;
        }
        cur = cal(cod,bob,alice,i);
        if(cur != bad) {
            cout << cur[2]+1 << ' ' << cur[1]+1 << ' ' << cur[0]+1 << '\n';
            return;
        }
        
    }
    cout << "impossible\n";
};

int main() {
    //Sublime
    // init();
    // FASTIO;
    solve();
}
