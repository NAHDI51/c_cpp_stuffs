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

vi par, maxx, mex;
vector<set<int>> st;

int get_parent(int v) {
    if(v == par[v]) return v;
    return par[v] = get_parent(par[v]);
}

void solve() {
    int n, q;
    cin >> n >> q;

    par = vi(n), maxx = vi(n), mex = vi(n);
    st = vector<set<int>>(n);
    forn(i, n) par[i] = i, mex[i] = 1;

    auto adjust = [&] (set<int>& st, int& mex, int c) {
        if(c == mex) {
            auto it = st.lower_bound(c);
            while(*it == mex) {
                it++, mex++;
            }
        }
    };

    forn(i, n) {
        int m;
        cin >> m;

        forn(j, m) {
            int c;
            cin >> c;
            st[i].ins(c); maxx[i] = max(maxx[i], c);
            adjust(st[i], mex[i], c);
        }
    }

    while(q--) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            a = get_parent(a), b = get_parent(b);
            if(st[a].sz() < st[b].sz()) swap(a, b);
            for(auto x : st[b]) {
                st[a].ins(x), maxx[a] = max(maxx[a], x);
                adjust(st[a], mex[a], x);
            }
            par[b] = a;

        } else {
            int c;
            cin >> c;
            c--;
            c = get_parent(c);
            if(mex[c] > maxx[c]) {
                cout << "complete" << '\n';
            } else {
                cout << mex[c] << '\n';
            }
        }
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

