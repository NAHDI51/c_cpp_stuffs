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
using lll = __int128;
using vlll = vector<__int128>;

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

#define one_count(x) __builtin_popcount(x)
#define end_0(x) __builtin_clz(x)
#define beg_0(x) __builtin_ctz(x)

#define MAX 1000000000
#define MIN -MAX

#define mod 1000000007LL

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

ll gcd(ll a, ll b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a*b) / gcd(a, b);
}

#define maxN 

int nthUglyNumber(ll n, ll a, ll b, ll c) {
    int lo = 1, hi = 2*1000000000;

    auto cnt = [&](int num) {
        // if(num == 7) cout << (num/lcm(a,b)) << ' ' << (num/lcm(b,c)) << ' ' << (num/lcm(c,a)) << ' ' << (num/lcm(lcm(a,b),c)) << '\n';
        int ans = (num / a) + (num / b) + (num / c) - 
               ((num / lcm(a,b)) + (num / lcm(b,c)) +
               (num / lcm(c,a))) + (num / lcm(lcm(a,b),c));
        // cout << ans << '\n';
        return ans;
    };
    while(lo < hi) {
        // Flag;
        int mid = lo + (hi - lo) / 2;
        int cur = cnt(mid);
        // cout << lo << ' ' << mid << ' ' << hi << ' ' << cur << '\n';
        if(cur <= (n-1)) lo = mid + 1;
        else hi = mid;
    }
    // cout << lo << '\n';
    // while(lo%a && lo%b && lo%c) lo--; 
    return lo;
}

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << nthUglyNumber(n, a, b, c) << '\n';
}


int main() {
    //Sublime
    // init();
    FASTIO;
    solve();
}