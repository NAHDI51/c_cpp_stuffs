#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using vb = vector<bool>;
using ii = pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using table = unordered_map<unsigned long, int>;

#define f first
#define s second

#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, a, b) for(int i = a; i <= b; i++)
#define for1n(i, n) for(int i = 1; i <= n; i++)
#define rof(i, n) for(int i = n-1; i >= 0; i--)
#define rofe(i, a, b) for(int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
#define dsc(type) greater<type>

#define Flag cout << "Reached here.\n"

#define pb push_back
#define pbb pop_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert
#define maxN 

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 1000000000
#define MIN -MAX
ll mod = 1e9+7;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int hsh[128]{};

ll p(ll a, ll b)  {
    ll sm = 1;
    while(b) {
        if(b&1) sm *= a, sm %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return sm;
}

void solve(){
    forn(i, 10) hsh[i+48] = i;
    forn(i, 26) hsh[i+65] = i+10, hsh[i+97] = i+10+26;
    hsh['-'] = 62, hsh['_'] = 63;

    string s;
    cin >> s;

    ll b = 0;
    forn(i, s.sz()) b += 6-onec(hsh[s[i]]);
    cout << p(3LL, b) << '\n';
}

int main() {
    solve();
}