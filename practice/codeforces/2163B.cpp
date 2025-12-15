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
    string s;
    forn(i, n) cin >> a[i];
    cin >> s;

    if(s[0] == '1' || s[n-1] == '1') {
        cout << -1 << '\n';
        return;
    }
    bool ok = false;
    forn(i, n) {
        if(s[i] == '1') ok = true;
        if((a[i] == 1 || a[i] == n) && s[i] == '1') {
            cout << -1 << '\n';
            return;
        }
    }
    if(!ok) {
        cout << 0 << '\n';
        return;
    }
    int lmn, lmni, lmx, lmxi;
    vpi ans;
    vector<char> seq(n, '0');

    auto stock = [&](int r) -> vi {
        int lmn = n+1, lmx = 0, lmni = 0, lmxi = 0;
        forn(i, r) {
            if(a[i] < lmn) {
                lmn = a[i], lmni = i;
            }
            if(a[i] > lmx) {
                lmx = a[i], lmxi = i;
            }
        }
        return {lmn, lmni, lmx, lmxi};
    };
    auto assign = [&](vi inds) {
        lmn = inds[0], lmni = inds[1], lmx = inds[2], lmxi = inds[3];
    };
    int ind;
    auto offset = [&]() {
        ind = 0;
        while(ind < n && s[ind] == '0') ind++;
        ind--;
    };
    offset();
    ok = false;

    auto verify = [&]() -> bool {
        forn(i, n)  {
            if(s[i] == '1' && seq[i] == '0') {
                return false;
            }
        }
        return true;
    };

    auto bruteforce = [&](int r) {
        assign(stock(r+1));
        int mn1 = n+1, mx1 = 0;

        ii cur;
        int good = -1;
        for(int i = r; i < n; i++) {
            if((lmn < mn1 && mx1 < a[i]) || (lmx > mx1 && mn1 > a[i])) {
                good = i;
                if(lmn < mn1 && mx1 < a[i]) cur = {lmni, i};
                if(lmx > mx1 && mn1 > a[i]) cur = {lmxi, i};
            }
            if(s[i] == '1') {
                mn1 = min(mn1, a[i]);
                mx1 = max(mx1, a[i]);
            }
        }
        for(int i = r+1; i < good; i++) {
            seq[i] = '1';
        }
        ans.pb(cur);
        ok = verify();
        ind = good-1;
    };
    ok = verify();
    forn(i, 5) {
        if(ok) break;
        bruteforce(ind);
    }

    if(!ok) {
        reverse(all(s)), reverse(all(a));
        seq = vector<char>(n, '0');
        forn(i, 5) {
            if(ok) break;
            bruteforce(ind);
        }

        if(!ok) {
            cout << -1 << '\n';
            return;
        }
        cout << ans.sz() << '\n';
        for(auto [x,y] : ans) {
            cout << n-y << ' ' << n-x << '\n';
        }

        return;
    }
    cout << ans.sz() << '\n';
    for(auto [x,y] : ans) {
        cout << x+1 << ' ' << y+1 << '\n';
    }


}

int main() {
    //Sublime
    // init();
    // FASTIO;

    int t;
    cin >> t;
    while(t--) solve();
}

