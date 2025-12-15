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

string dectoalpha(long long num) {
    if (num == 0) return "a";
    
    string result;
    while (num) {
        int rem = num % 26;
        result.push_back('a' + rem);
        num /= 26;
    }
    reverse(result.begin(), result.end());
    return result;
}

long long alphatodec(string s) {
    long long num = 0;
    for (char c : s) {
        num = num * 26 + (c - 'a');
    }
    return num;
}

void encode() {
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    string ans;
    forn(i, n) {
        auto cur = dectoalpha(a[i]);
        ans += cur.sz()+'a';
        ans += cur;
    }
    cout << ans << '\n';
}

void decode() {
    string s;
    cin >> s;
    vll ans;
    // cout << s << '\n';

    forn(i, s.sz()) {
        int cur = (int) s[i]-'a';
        ans.pb(alphatodec(s.substr(i+1, cur)));
        i += cur;
    }
    cout << ans.sz() << '\n';
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
}

void solve() {
    string s;
    cin >> s;

    if(s == "first") encode();
    else decode();
}

int main() {
    //Sublime
    // init();
    // FASTIO;

    solve();
}

