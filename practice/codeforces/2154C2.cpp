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

#define maxN 500005

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
        // cout << n << ' ';
        int cur = spf[n];
        while(spf[n] == cur) n /= spf[n];
        if(cur != 1) cnt[cur]++;
        // cout << N << ' ' << cur << '\n';
    }
    // cout << '\n';
}

bool verify(int n, vi& cnt) {
    int N = n;
    while(n != 1) {
        int cur = spf[n];
        while(spf[n] == cur) n /= spf[n];
        if(cnt[cur]) {
            // cout << "GOT: " << cur << '\n';
            return true;
        }
        // cout << N << ' ' << cur << '\n';
    }
    return false;
}

void minuss(int n, vi& cnt) {
    int N = n;
    while(n != 1) {
        int cur = spf[n];
        while(spf[n] == cur) n /= spf[n];
        cnt[cur]--;
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
    vi cnt(mx+2);

    // cout << "CNTS: ";
    // for(auto [x,y] : cnt) {
    //     cout << x << ' ' << y << ' ';
    // }
    forn(i, n) {
        div(a[i], cnt);
    }
    // cout << "CNTS: ";
    // for(auto [x,y] : cnt) {
    //     cout << x << ' ' << y << ' ';
    // }
    for(int i = 2; i <= mx; i++) {
        if(cnt[i] > 1) {
            cout << 0 << '\n';
            return;
        }
    }
    ll ans = MAX;

    // cout << "CNTS: ";
    // for(auto [x,y] : cnt) {
    //     cout << x << ' ' << y << ' ';
    // }
    // cout << '\n';
    forn(i, n) {
        if(verify(a[i]+1, cnt)) {
            // cout << i << ' ' << a[i]+1 << '\n';
            ans = min(ans, b[i]);
        }
    }
    // cout << ans << '\n';
    // Flag;
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
    // cout << ans << '\n';
    // cout << mn << ' ' << mn2 << '\n';
    ans = min(ans, mn+mn2);
    // cout << ans << '\n';
    // cout << mn << ' ' << mn2 << '\n';

    ll mnb = b[0], mni = 0;
    forn(i, n) {
        if(b[i] < mnb) {
            mnb = b[i], mni = i;
        }
    }
    int count = 0;
    forn(i, n) {
        if(b[i] == mnb) count++;
    }
    // cout << ans << '\n';
    if(count > 1) {
        ans = min(ans, mnb+mnb);
        cout << ans << '\n';
        return;
    }
    minuss(a[mni], cnt);
    // cout << "CNTS: ";
    // for(auto [x,y] : cnt) {
    //     cout << x << ' ' << y << ' ';
    // }
    // cout << '\n';
    vi cands;
    for(int i = 2; i < cnt.sz(); i++) {
        if(cnt[i]) cands.pb(i);
    }
    // cout << a[mni] << ' ' << mnb << '\n';
    for(auto x : cands) {
        // cout << x << ' ' << (((a[mni]/x)+1)*x)-a[mni] << '\n';
        ans = min(ans, (ll) mnb * ((((a[mni]/x)+1)*x)-a[mni]));
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

