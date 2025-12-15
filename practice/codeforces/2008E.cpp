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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vii> sum(2, vii(26, vi(n+1)));
    forn(i, n) {
        forn(j, 26) {
            forn(k, 2)
                sum[k][j][i+1] = sum[k][j][i] + ((j == (s[i]-'a')) && (k == ((i+1)%2)));    
        }
    }
    if(n%2 == 0) {
        int emx = 0, omx = 0;
        forn(i, 26) emx = max(emx, sum[0][i][n]);
        forn(i, 26) omx = max(omx, sum[1][i][n]);
        // cout << emx << ' ' << omx << '\n';
        // cout << "EVen: ";
        cout << n - emx - omx << '\n';
        return;
    }
    // Returns maximum of one character 
    auto sm = [&](int l1, int r1, int l2, int r2) -> int{
        int emx = 0, omx = 0;
        forn(i, 26) {
            int ecur = 0, ocur = 0;
            if(l1 <= r1) {
                ecur += sum[0][i][r1] - sum[0][i][l1-1];
                ocur += sum[1][i][r1] - sum[1][i][l1-1]; 
            }
            if(l2 <= r2) {
                ecur += sum[1][i][r2] - sum[1][i][l2-1];
                ocur += sum[0][i][r2] - sum[0][i][l2-1];
            }
            emx = max(emx, ecur);
            omx = max(omx, ocur);
        }
        return emx + omx;
    };
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        mx = max(sm(1,i-1, i+1,n), mx);
    }
    cout << n-mx << '\n';

}

int main() {
    //Sublime
    // init();
    // FASTIO;
    
    int t;
    cin >> t;
    while(t--) solve();
}

