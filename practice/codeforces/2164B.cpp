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
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) {
        cin >> a[i];
    }
    if(n == 2) {
        if((a[1] % a[0]) % 2 == 0) {
            cout << a[0] << ' ' << a[1] << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }
    vi even;
    forn(i, n) {
        if(a[i] % 2 == 0) even.pb(i);
    }
    if(even.sz() > 1) {
        cout << a[even[0]] << ' ' << a[even[1]] << '\n';
        return;
    }
    else if(even.sz() == 1) {
        forn(i, n) {
            if(i == even[0]) continue;
            int mn = min(a[i], a[even[0]]), mx = max(a[i], a[even[0]]);
            if((mx % mn) % 2 == 0) {
                cout << mn << ' ' << mx << '\n';
                return;
            }
        } 
    }
    if((a[1] % a[0]) % 2 == 0) {
        cout << a[0] << ' ' << a[1] << '\n';
        return;
    }
    for(int i = 2; i < n; i++) {
        if(a[i] % 2 == 0) continue;
        if(a[i-1] % 2 != 0 && a[i-1] * 2 >= a[i]) {
            cout << a[i-1] << ' ' << a[i] << '\n';
            return;
        }
        if(a[i-2] % 2 != 0 && a[i-2] * 2 >= a[i]) {
            cout << a[i-2] << ' ' << a[i] << '\n';
            return;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < min(n, i+32); j++) {
            if((a[j] % a[i]) % 2 == 0) {
                cout << a[i] << ' ' << a[j] << '\n';
                return;
            }
        } 
    }
    cout << -1 << '\n';
}

int main() {
    //Sublime
    // init();
    // FASTIO;

    int t;
    cin >> t;
    while(t--) solve();
}

