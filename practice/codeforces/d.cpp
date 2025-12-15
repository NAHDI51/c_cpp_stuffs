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

#define mod 998244353LL
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

#define maxN 100005

ll fac[maxN];

void calc() {
    fac[0] = 1;
    for(ll i = 1; i < maxN; i++) {
        fac[i] = fac[i-1] * i;
        fac[i] %= mod;
    }
}


void solve() {
    int n, m;
    cin >> n >> m;

    vll ad, at, bd, bt;

    // Flag;
    forn(i, n) {
        ll a;
        char c;
        cin >> a >> c;
        if(c == 'D') ad.pb(a);
        else at.pb(a);
    }
    forn(i, m) {
        ll a;
        char c;
        cin >> a >> c;
        if(c == 'D') bd.pb(a);
        else bt.pb(a);
    }

    ll sma = 0, smb = 0;
    forn(i, ad.sz()) sma += ad[i];
    forn(i, bd.sz()) smb += bd[i];

    // Flag;
    // Ensures that a is always bigger
    if(sma < smb) {
        swap(sma,smb);
        swap(ad, bd);
        swap(at, bt); 
    }
    int cnt = 0;
    forn(i, bt.sz()) {
        if((bt[i] + smb) > sma)
            cnt++;
    }
    // Flag;
    ll ans;
    if(bt.sz() == 0) {
        ll ans1 = (fac[ad.sz()] * fac[at.sz()]) % mod;
        ll ans2 = (fac[bd.sz()] * fac[bt.sz()]) % mod;
        ans = (ans1 * ans2) % mod;
    } else {
        ll ans1 = (fac[ad.sz()] * fac[at.sz()]) % mod;
        ll ans2 = (ll)(((lll) fac[bd.sz()] * (lll)(cnt * fac[bt.sz()-1])) % mod);
        ans = (ans1 * ans2) % mod;
    }
    cout << ans << '\n';

}

int main() {
    //Sublime
    init();
    // FASTIO;

    calc();

    solve();
}

