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

#define double long double

void solve() {
    ii co1, co2;
    cin >> co1.f >> co1.s >> co2.f >> co2.s;

    int xl = min(co1.f, co2.f), xr = max(co1.f, co2.f);
    int yl = min(co1.s, co2.s), yr = max(co1.s, co2.s);
    vpi ps = {{xl, yl}, {xr, yl}, {xr, yr}, {xl, yr}};


    // forn(i, 4) cout << ps[i].f << ' ' << ps[i].s << '\n';
    ii e1, e2;
    cin >> e1.f >> e1.s >> e2.f >> e2.s;
    double stapler_minx = min(e1.f, e2.f), stapler_maxx = max(e1.f, e2.f);
    double stapler_miny = min(e1.s, e2.s), stapler_maxy = max(e1.s, e2.s);
    
    auto equation = [&](double x1, double x2, double y1, double y2) -> vector<double> {
        if(x1 == x2) {
            return {1,  0, -x1};
        }
        if(y1 == y2) {
            return {0,1,-y1};
        }
        double one = (y1-y2) / (x1-x2);
        double two = -1;
        double three = y1 - ((y1-y2)*(x1)/(x1-x2));
        return {one,two,three};
    };
    /*
    auto value = [&](pair<double,double> co, vector<double>& eq) -> double {
        return co.f*eq[0] + co.s*eq[1] + eq[2];
    };
    */ 

    auto inrange_rect = [&](ii p) -> bool {
        return (co1.f <= p.f && p.f <= co2.f) && (co1.s <= p.s && p.s <= co2.s);
    };

    auto inrange_stapler = [&](ii p) -> bool {
        return (stapler_minx <= p.f && p.f <= stapler_maxx) &&
               (stapler_miny <= p.s && p.s <= stapler_maxy);
    };


    vector<double> ans;
    auto eqq = equation(e1.f, e2.f, e1.s, e2.s);

    vector<vector<double>> eqs;
    forn(i, 4) {
        eqs.pb(equation(ps[i].f, ps[(i+1)%4].f, ps[i].s, ps[(i+1)%4].s));
    }
    auto solve = [](double a1, double b1, double c1, double a2, double b2, double c2) -> vector<double> {
        double D  = a1 * b2 - a2 * b1;
        double Dx = -c1 * b2 + c2 * b1;
        double Dy = -a1 * c2 + a2 * c1;

        if (D != 0) {
            return {1, Dx / D, Dy / D};
        } else if (Dx == 0 && Dy == 0) {
            return {2, 0, 0}; 
        } else {
            return {0, 0, 0}; 
        }
    };

    if(inrange_rect(e1) || inrange_rect(e2)) {
        cout << "STOP\n";
        return;
    }

    forn(i,4) {
        auto cur = solve(eqq[0],eqq[1],eqq[2], eqs[i][0], eqs[i][1], eqs[i][2]);
        
        if(cur[0] == 2) {
            
            double rect_minx = min(ps[i].f, ps[(i+1)%4].f);
            double rect_maxx = max(ps[i].f, ps[(i+1)%4].f);
            double rect_miny = min(ps[i].s, ps[(i+1)%4].s);
            double rect_maxy = max(ps[i].s, ps[(i+1)%4].s);
            
            bool overlap_x = !(stapler_maxx < rect_minx || stapler_minx > rect_maxx);
            bool overlap_y = !(stapler_maxy < rect_miny || stapler_miny > rect_maxy);
            
            if(overlap_x && overlap_y) {
                cout << "STOP\n";
                return;
            }
        } 
        else if(cur[0] == 1) { 
            if(inrange_rect({cur[1],cur[2]}) && inrange_stapler({cur[1],cur[2]})) {
                cout << "STOP\n";
                return;
            }
        }
    }
    cout << "OK\n";
    return;
}

int main() {
    //Sublime
    // init();
    // FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
}

