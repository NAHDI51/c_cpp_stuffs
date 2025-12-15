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

#define MAX 100000000000000000ll
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

#define maxN 200005

int spf[maxN];

void sieve() {
    memset(spf, -1, sizeof(spf));
    for(int i = 2; i < maxN; i++) {
        if(spf[i] == -1) {
            for(int j = i; j < maxN; j += i) {
                if(spf[j] == -1) spf[j] = i;
            }
        }
    }
}

void div(int n, vi& cnt) {  
    int N = n;
    while(n != 1) {
        int cur = spf[n];
        while(spf[n] == cur) n /= spf[n];
        cnt[cur]++;
        // cout << N << ' ' << cur << '\n';
    }
}

void solve() {
    int n;
    cin >> n;
    vll a(n), b(n);
    ll mx = 0;
    forn(i, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    forn(i, n) cin >> b[i];
    vi cnt((2*mx)+2);
    forn(i, n) div(a[i], cnt);
    for(int i = 2; i <= mx; i++) {
        if(cnt[i] > 1) {
            cout << 0 << '\n';
            return;
        }
    }
    
    ll ans = MAX;
    ll mn = MAX, mn2 = MAX;
    forn(i, n) {
        if(b[i] < mn) {
            mn2 = mn, mn = b[i];
        } else if(b[i] == mn) {
            mn2 = mn;
        } else if(b[i] < mn2) {
            mn2 = b[i];
        }
    }
    // cout << mn << ' ' << mn2 << '\n';
    ans = min(ans, (ll) mn+mn2);
    vi next((2*mx)+2);

    for(int i = 2; i < cnt.sz(); i++) {
        if(cnt[i] == 1) {
            cnt[i] = i;
            for(int j = i; j < cnt.sz(); j += i) {
                if(cnt[j] == 0) {
                    // cout << i << ' ' << j << '\n';
                    cnt[j] = i;
                }
            }
        }
    }
    int j = 0;
    stack<int> stk, nstk;
    for(int i = 1; i < cnt.sz(); i++) {
        // cout << i << ' ' << cnt[i] << '\n';
        if(cnt[i]) {
            nstk = stack<int>{};
            while(!stk.empty()) {
                int j = stk.top();
                stk.pop();
                if(cnt[j] == cnt[i]) {
                    nstk.push(j);
                }
                else {
                    next[j] = i;
                }
            }
            stk = nstk;
        }
        stk.push(i);
    }
    // forn(i, next.sz()) cout << cnt[i] << ' ';
    // cout << '\n';
    // forn(i, next.sz()) cout << next[i] << ' ';
    // cout << '\n';
    forn(i, n) {
        if(next[a[i]] == 0) continue;
        ans = min(ans, (ll) (next[a[i]] - a[i]) * (ll) b[i]);
    }
    cout << ans << '\n';
    return;

}

int main() {
    //Sublime
    // init();
    FASTIO;
    sieve();
    int t;
    cin >> t;
    while(t--) solve();
}

