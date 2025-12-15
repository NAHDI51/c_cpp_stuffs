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

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

#define mod 1000000007LL

class lazy {
vi seg, lzy;
int size;

bool in_range(int a, int b, int x, int y) {
    return a <= x && y <= b;
}

bool out_range(int  a, int b, int x, int y) {
    return y < a || x > b;
}

bool invalid(int x, int y) {
    return x > y;
}

void lazy_update(int k, int x, int y) {
    if(lzy[k]) {
        seg[k] = (y-x+1) * lzy[k];
        if(x != y) lzy[2*k] += lzy[k], lzy[2*k+1] += lzy[k];
        lzy[k] = 0;
    }
}

void propagate(int k, int x, int y, int val) {
    seg[k] = (y-x+1) * val;
    if(x != y) lzy[2*k] = val, lzy[2*k+1] = val;
}

public:
lazy(vi& a) {
    size = a.sz();
    seg.rsz(4*size), lzy.rsz(4*size);
    forn(i, a.sz()) update(i, a[i]);
}

void update(int a, int b, int k, int x, int y, int val) {
    if(invalid(x, y)) return;
    lazy_update(k, x, y);
    if(out_range(a, b, x, y)) return;
    if(in_range(a, b, x, y)) propagate(k, x, y, val);
    int d = (x+y)/2;
    update(a, b, 2*k, x, d, val), update(a, b, 2*k+1, d+1, y, val);
    seg[k] = seg[2*k] + seg[2*k+1];
}

int query(int a, int b, int k, int x, int y) {
    if(invalid(x, y)) return 0;
    lazy_update(k, x, y);
    if(out_range(a, b, x, y)) return 0;
    if(in_range(a, b, x, y)) return seg[k];
    int d = (x+y)/2;
    return query(a, b, 2*k, x, d) + query(a, b, 2*k+1, d+1, y);
}

int query(int l, int r) {
    return query(l, r, 1, 0, size-1);
}

void update(int l, int r, int val) {
    update(l, r, 1, 0, size-1, val);
}
void update(int i, int val) {
    update(i, i, val);
}
};