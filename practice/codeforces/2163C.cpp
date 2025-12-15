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
    vi a(n), b(n);
    vi pmn(n), pmx(n), smn(n), smx(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];

    vi best(2*n+1, MAX);
    pmn[0] = a[0], pmx[0] = a[0];
    for(int i = 1; i < n; i++) {
        pmn[i] = min(pmn[i-1], a[i]);
        pmx[i] = max(pmx[i-1], a[i]);
    }
    smn[n-1] = b[n-1], smx[n-1] = b[n-1];
    for(int i = n-2; i >= 0; i--) {
        smn[i] = min(smn[i+1], b[i]);
        smx[i] = max(smx[i+1], b[i]);
    }

    forn(i, n) {
        best[min(pmn[i], smn[i])] = min(best[min(pmn[i], smn[i])], max(pmx[i], smx[i]));
    }
    stack<ii> st;
    st.push({0, 0});
    for(int i = 1; i <= 2*n; i++) {
        while(st.top().f > best[i]) st.pop();
        if(best[i] != MAX) st.push({best[i], i});
    }
    auto cur = st.top();
    st.pop();
    int li = cur.s, l = cur.f;
    ll ans = 0;

    // for1n(i, 2*n) {
    //     if(best[i] == MAX) cout << -1 << ' ';
    //     else cout << best[i] << ' ';
    // }
    // cout << '\n';
    while(!st.empty()) {
        auto cur = st.top();
        st.pop();
        ans += (ll) (li - cur.s) * (ll) ((2*n) - l + 1);
        l = cur.f, li = cur.s;
        // cout << cur.f << ' ' << cur.s << ' ' << ans << '\n';
    }
    cout << ans << '\n';
    
}

int main() {
    //Sublime
    // init();
    // FASTIO;

    int t;
    cin >> t;
    while(t--) solve();
}

