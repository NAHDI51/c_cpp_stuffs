#include <bits/stdc++.h>
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
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

#define pb push_back
#define pbb pop_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert

#define lb(a, val) lower_bound(all(a), val);
#define ub(a, val) upper_bound(all(a), val);

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 1000000000
#define MIN -MAX

#define mod 1000000007LL

#define clr(x, y) memset(x, y, sizeof(x))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

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

vi fct(ll n) {
    vi fac;
    while(n%2 == 0) n /= 2, fac.pb(2);
    for(int i = 3; i * i <= n; i += 2) 
        while(n%i == 0) fac.pb(i), n /= i;
    if(n > 1) fac.pb(n);
    return fac;
}

ll gcd(ll a, ll b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a*b) / gcd(a, b);
}

#define maxN 

int cnt(string& s) {
    int n = s.sz();
    set<string> st;
    forn(i, n) {
        int k = 0;
        while(0 <= i-k && i+k < n && s[i-k] == s[i+k]) {
            st.ins(string(s.begin()+i-k, s.begin()+i+k+1));
            k++;
        }
    }
    forn(i, n) {
        int k = 0;
        while(0 <= i-k && i+k+1 < n && s[i-k] == s[i+k+1]) {
            st.ins(string(s.begin()+i-k, s.begin()+i+k+2));
            k++;
        }
    }
    return st.sz();
}

struct Dsu {
private:
vi anc;
vi sz;
int n;
public:
Dsu(int n) {
    this->n = n;
    anc.rsz(n), sz.rsz(n);
    forn(i, n) anc[i] = i, sz[i] = 1;
}
int find(int u) {
    while(u != anc[u]) u = anc[u];
    return u;
}
void join(int a, int b) {
    a = find(a), b = find(b);
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    anc[b] = a;
}
};

void more_task(int n, vs s) {
    
}

void solve() {
    int n;
    cin >> n;   

    vs s(n);
    forn(i, s.sz()) {
        char c;
        cin >> c;
        s[i] += c;
    }
    if(n > 100) more_task(n, s);

    Dsu dsu(n);
    forn(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        string ns = s[dsu.find(a)] + s[dsu.find(b)];
        dsu.join(a, b);
        s[dsu.find(a)] = ns;
        cout << cnt(ns) << '\n';
    }
}

int main() {
    FASTIO;
    solve();
}

