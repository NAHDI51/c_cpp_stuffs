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
#include <cstring>

// #include <bits/stdc++.h>

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
#define all(x) x.begin(), x.end()

#define Flag cout << "Reached here.\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define pb push_back
#define pbb pop_back
#define sz size
#define rsz resize
#define ins insert

#define one_count(x) __builtin_popcount(x)
#define end_zero(x) __builtin_clz(x)
#define beg_zero(x) __builtin_ctz(x)

#define MAX 1000000000ll
#define MIN -MAX

#define mod 1000000007LL
#define clr(x, y) memset(x, y, sizeof(x))

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

#define maxN 


void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    vi a(n);
    forn(i, n) cin >> a[i];

    sort(all(a));
    // for(auto x : a) cout << x << ' ';
    // cout << '\n';

    auto construct = [&](int m, vi& ans) {
        for(int i = 0; i <= a[0]-m && ans.sz() < k; i++) {
            if(ans.sz() == 0 || ans.back() != i) {
                // cout << i << ' ' << a[0]-m << ' ' << m << '\n';
                ans.pb(i);
            }
        }

        for(int i = 0; i < n-1 && ans.sz() < k; i++) {
            // Flag;
            fore(j, a[i]+m, a[i+1]-m) {
                if(ans.sz() == 0 || ans.back() != j) {
                    ans.pb(j);
                }
                if(ans.sz() == k) break;
            }
        }
        for(int i = a[n-1]+m; i <= x && ans.sz() < k; i++) {
            // Flag;
            if(ans.sz() == 0 || ans.back() != i) {
                ans.pb(i);
            }
        }
        // cout << ans.sz() << '\n';
    };
    auto ok = [&](int m) -> bool{
        vi ans;
        construct(m, ans);
        if(ans.sz() >= k) return true;
        else return false;
    };

    int lo = 0, hi = x;
    int ans = 0;
    while(lo <= hi) {
        int m = lo + (hi-lo) / 2;
        // cout << lo << ' ' << hi <<  ' ' << m << '\n';
        if(ok(m)) {
            ans = m;
            lo = m+1;
        } else hi = m-1;
    }
    vi seq;
    construct(ans, seq);
    // cout << seq.sz() << '\n';
    // cout << '\n';
    // cout << ans << '\n';
    for(auto x : seq) cout << x << ' ';
    cout << '\n';
}

int main() {
    //Sublime
    // init();
    // FASTIO;

    int t;
    cin >> t;
    while(t--) solve();
}

