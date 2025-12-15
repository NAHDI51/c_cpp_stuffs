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

using vvlll = vector<vlll>;

void solve() {
    ll n;
    cin >> n;
    vlll a(n+1);
    for1n(i, n) {
        ll c;
        cin >> c;
        a[i] = c;
    }
    auto det = [&](vector<vlll> m) -> lll {
        return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
            - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
            + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    };
    auto kramer = [&](vector<vlll> eqs) -> vlll {
        vvlll Dx = {
            {eqs[0][3], eqs[0][1], eqs[0][2]},
            {eqs[1][3], eqs[1][1], eqs[1][2]},
            {eqs[2][3], eqs[2][1], eqs[2][2]}
        };
        vvlll Dy = {
            {eqs[0][0], eqs[0][3], eqs[0][2]},
            {eqs[1][0], eqs[1][3], eqs[1][2]},
            {eqs[2][0], eqs[2][3], eqs[2][2]}
        };
        vvlll Dz = {
            {eqs[0][0], eqs[0][1], eqs[0][3]},
            {eqs[1][0], eqs[1][1], eqs[1][3]},
            {eqs[2][0], eqs[2][1], eqs[2][3]}
        };

        vvlll D = {
            {eqs[0][0], eqs[0][1], eqs[0][2]},
            {eqs[1][0], eqs[1][1], eqs[1][2]}, 
            {eqs[2][0], eqs[2][1], eqs[2][2]}  
        };
        lll denom = det(D);
        return {det(Dx), det(Dy), det(Dz), denom};
    };
    // auto calc = [&](lll a, lll b, lll c, lll x) -> lll {
    //     return (a * x * x) + (b * x) + c;
    // };

    int ans = 0;
    vvlll cur;
    vlll cope;
    for(lll i = 1; i <= n; i++) {
        if(cur.sz() == 3) {
            // cout << (ll) i << ' ';
            // for(auto x : cope) cout << (ll) x << ' ';
            // cout << '\n';

            if ((cope[0]*i*i + cope[1]*i + cope[2]) == (a[i]*cope[3])) {
                continue;
            } else {
                cur.clear(), cope.clear();
                ans++;
                cur.pb({i*i,i,1,a[i]});
            }
        } else {
            cur.pb({i*i, i, 1, a[i]});
            if(cur.sz() == 3){
                cope = kramer(cur);
                // for(auto x : cur) {
                //     for(auto y : x) {
                //         cout << (ll) y << ' ';
                //     }
                //     cout << '\n';
                // }
                // for(auto x : cope) cout << (ll) x << ' ';
                // cout << '\n';
            }
        }
    }
    cout << ans+1 << '\n';
}

int main() {
    //Sublime
    // init();
    // FASTIO;

    int t;
    cin >> t;
    while(t--) solve(); 
}

