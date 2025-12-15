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

#define maxN 100001
#define maxSM 2000002

int getc(char c) {
    if(c == 'A') return 0;
    else if(c == 'G') return 1;
    else if(c == 'C') return 2;
    else return 3;
}

vi Rng[maxSM][4];
int T[maxSM][4];
pair<int, int> rng[maxSM][4];
int t[maxSM][4];

class trie1 {
int sz;

public:
trie1() {
    forn(i, maxSM) forn(j, 4) rng[i][j] = {-1,-1}, t[i][j] = -1;
    sz = 1;
}
void ins(string& s, int ind) {
    int v = 0;
    forn(i, s.sz()) {
        int c = getc(s[i]);
        if(t[v][c] == -1) t[v][c] = sz++, rng[v][c] = {ind, ind-1};
        rng[v][c].s++;
        v = t[v][c];
    }
}
pair<int, int> q(string& s) {
    int v = 0; 
    forn(i, s.sz()) {
        int c = getc(s[i]);
        if(t[v][c] == -1) return {-1, -1};
        if(i == s.sz()-1) return rng[v][c];
        v = t[v][c];
    }
    //Not reachable
    return {-1, -1};
}
};

class trie2 {
int sz;

public:
trie2() {
    forn(i, maxSM)  forn(j, 4) Rng[i][j] = vi{}, T[i][j] = -1;
    sz = 1;
}

void ins(string& s, int ind) {
    int v = 0;
    forn(i, s.sz()) {
        int c = getc(s[i]);
        if(T[v][c] == -1) T[v][c] = sz++;
        Rng[v][c].pb(ind);
        v = T[v][c];
    }
}

int q(string& s, ii& q) {
    if(q.f == -1 && q.s == -1) return 0;
    int v = 0;
    forn(i, s.sz()) {
        int c = getc(s[i]);
        if(T[v][c] == -1) return 0;
        if(i == s.sz()-1) return upper_bound(all(Rng[v][c]), q.s) - lower_bound(all(Rng[v][c]), q.f);
        v = T[v][c];
    }
}
void srt() {
    forn(i, maxSM) forn(j, 4) if(Rng[i][j].sz()) sort(all(Rng[i][j]));
}
};

void task34(int n, int m, vs& s, vs& p, vs& q) {
    sort(all(s));
    trie1 t1;
    trie2 t2;

    forn(i, n) {
        t1.ins(s[i], i);
        reverse(all(s[i]));
        t2.ins(s[i], i);
    }
    t2.srt();
    
    forn(i, m) {
        auto one = t1.q(p[i]);
        auto two = t2.q(q[i], one);
        cout << two << '\n';
    }
}

using si = pair<string, int>; 
void task12(int n, int m, vs& s, vs& p, vs& q) {
    sort(all(s));
    vector<si> rev(n);
    forn(i, n) {
        rev[i].f = s[i], rev[i].s = i;
        reverse(all(rev[i].f));
    }
    sort(all(rev));

    vi t(n+2, -1);
    forn(i, m) {
        int cnt = 0;
        int l1 = lower_bound(all(s), p[i]) - s.begin();
        p[i].back()++;
        int r1 = lower_bound(all(s), p[i]) - s.begin();
        int l2 = lower_bound(all(rev), si{q[i], -1}) - rev.begin();
        q[i].back()++;
        int r2 = lower_bound(all(rev), si{q[i], -1}) - rev.begin();

        for(int j = l1; j < r1; j++) t[j] = i;
        for(int j = l2; j < r2; j++) if(t[rev[j].s] == i) cnt++;
        cout << cnt << '\n';
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vs s(n);
    forn(i, n) cin >> s[i];
    vs p(m), q(m);
    forn(i, m) {
        cin >> p[i] >> q[i];
        reverse(all(q[i]));
    }
    
    if(n <= 5000 && m <= 5000) {
        task12(n, m, s, p, q);
        return;
    }
    
    int sm = 0;
    forn(i, n) sm += s[i].sz();
    if(sm <= 2000002) {
        task34(n, m, s, p, q);
        return;
    }
}

int main() {
    FASTIO;
    solve();
}

