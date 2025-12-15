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

#define MAX 1000000000ll
#define MIN -MAX
#define MAXX 1000000000000000000ll

// #define mod 1000000007LL


#define maxN 100005
#define WH 0
#define GR 1
#define BL 2

ll gcd(ll a, ll b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a*b) / gcd(a, b);
}

class ftree {
    int n;
    vi bit;

    public:
    ftree(int n) {
        this->n = n+2;
        bit.rsz(this->n);
    }
    ftree(vi& a) {
        this->n = a.sz()+2;
        bit.rsz(this->n);
        forn(i, n) upd(i, i, a[i]);
    }
    void upd(int l, int r, int val) {
        upd(l, val), upd(r+1, -val);
    }
    void upd(int i, int val) {
        for(++i; i < n; i += i&-i) bit[i] += val; 
    }
    int qu(int i) {
        int sm = 0;
        for(++i; i > 0; i -= i&-i) sm += bit[i];
        return sm;
    }
}; 

void solve() {
    int q;
    cin >> q;
    vii queries;
    queries.pb({-1});
    forn(i, q) {
        int t,a,b;
        cin >> t >> a;
        if(t == 3) {
            cin >> b;
            queries.pb({t,a,b});
        } else {
            queries.pb({t,a});
        }
    }   

    map<int,int> inds;
    int ind = 1;
    forn(i, q) {
        if(queries[i][0] == 1) inds[queries[i][1]] = ind++;
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

