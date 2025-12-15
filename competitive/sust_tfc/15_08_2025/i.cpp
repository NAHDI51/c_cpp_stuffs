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

#define PI 3.14159

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

using pdd = pair<double,double>;

void solve() {
    int n;
    double r;
    cin >> n >> r;
    vector<pdd> co(n);
    forn(i, n) cin >> co[i].f >> co[i].s;

    auto angle = [](pdd x, pdd y) -> double {
        if(x.f == y.f) return PI/2;
        auto c = atan2(x.s-y.s, x.f-y.f);
        if(c < 0.0) return PI - abs(c);
        return c;
    };

    auto dist = [](pdd x, pdd y) -> double {
        return sqrt(pow(x.f - y.f,2) + pow(x.s - y.s, 2));
    };

    auto ang_dist = [&](double angle) -> double {
        return r * angle;
    };
    auto get_small = [](double ang1, double ang2) -> double{
        auto ang = max(ang1,ang2) - min(ang1, ang2);
        if(ang > PI) ang = 2 * PI - ang;
        return ang;
    };

    if(n == 1) {
        printf("%.2lf", ang_dist(2.00 * PI));
        return;
    }
    if(n == 2) {
        printf("%.2lf", 2*(dist(co[0], co[1]) + ang_dist(PI)));
        return;
    }
    double ans = 0.0;
    for(int i = 1; i < n; i++) {
        auto one = co[i-1];
        auto two = co[i];
        auto three = co[(i+1) % n];

        auto ang = get_small(angle(one, two), angle(two, three));
        // cout << one.f << ' ' << one.s << ' ' << two.f << ' ' << two.s <<  ' ' << angle(one, two) << '\n';
        // cout << two.f << ' ' << two.s << ' ' << three.f << ' ' << three.s << ' ' << angle(two, three) << '\n';
        ans += ang_dist(ang);
        ans += dist(one, two);
        // cout << ans << '\n'; 
    }
    ans += dist(co[0], co[n-1]);
    ans += ang_dist(get_small(angle(co[0], co[n-1]), angle(co[n-1], co[n-2])));
    // ans += ang_dist(2*PI);
    printf("%.2lf", ans);
}

int main() {
    //Sublime
    // init();
    // FASTIO;
    solve();
}

