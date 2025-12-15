#include <bits/stdc++.h>
using namespace std;

#pragma gcc optimize(0fast)

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
#define maxN 100001

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 100000000LL 
#define MIN -MAX

#define clr(x, y) memset(x, y, sizeof(x))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

//Expansion.
int mx[17][100001];
int mn[17][100001];
int lg[100001];
vi f, b;
int n, m, k, q;

void build() {
    forn(i, n) mx[0][i] = f[i], mn[0][i] = b[i];

    for(int j = 1; (1<<j) <= n; j++) {
        for(int i = 0; i+(1<<j) <= n; i++)
            mx[j][i] = max(mx[j-1][i], mx[j-1][i+(1<<(j-1))]), 
            mn[j][i] = min(mn[j-1][i], mn[j-1][i+(1<<(j-1))]);
    }

    lg[1] = 0;
    for(int i = 2; i < maxN; i++) lg[i] = lg[i/2]+1;
}

int minq(int l, int r) {
    int lgn = lg[r-l+1];
    return min(mn[lgn][l], mn[lgn][r-(1<<lgn)+1]);
}

int maxq(int l, int r) {
    int lgn = lg[r-l+1];
    return max(mx[lgn][l], mx[lgn][r-(1<<lgn)+1]);
}

int query(int s, int t, int k) {
    int l = s, r = s;

    int stp = 1;
    while(1) {
        int prev_l = l, prev_r = r;

        //cout << l << r << '\n';
        int one = maxq(max(0, prev_l-k), prev_r);
        if(one != MIN) r = one;

        int two = minq(prev_l, min(n-1, prev_r+k));
        if(two != MAX) l = two;
        //cout << l << r << '\n';

        //The current interval hasn't changed.
        if(prev_l == l && prev_r == r) return -1;
        if(l <= t && t <= r) return stp;
        stp++;
    }
}

void solve() {
    cin >> n >> k >> m;

    f.rsz(n, MIN), b.rsz(n, MAX);   

    forn(i, m) {
        int x, y;
        cin >> x >> y;
        //Get forward, get backward.
        if(x < y) f[x-1] = max(f[x-1], y-1);
        else b[x-1] = min(b[x-1], y-1);
    }

    build();
    int q;
    cin >> q;
    int p = 0;
    while(q--) {
        int s, t;
        cin >> s >> t;
        cout << query(s-1, t-1, p) << '\n';
        if(p < k-1) p++;
    }
}

int main() {
    solve();
}