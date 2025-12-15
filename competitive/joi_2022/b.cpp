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

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int n;
ll m;
vll a, b;
ll ans;
ll r = 1000000000000000000;
ll l = 0;

void task1() {
    ll mn = MAX;
    forn(i, n) mn = min(mn, max(a[i], b[i]));
    cout << mn << '\n';
}

bool ok(ll k) {
    ll c = n*m;
    forn(i, n) {
        c -= (k/a[i]);
        if(k%a[i]) c--;
        if(c < 0) return true;
    }
    return false;
}

void task2() {
    ll x = -1;
    for(ll b = r; b >= 1; b /= 2) {
        //cout << x+b << '\n';
        while(!ok(x+b)) x += b;
    }
    cout << x << '\n';
}

void task5() {
    task2();
}

bool ok2(ll k, vb swapped) {
    ll c = n*m;
    forn(i, n) {
        int ceil = k%a[i] ? 1 : 0;
        if(!swapped[i] && k/a[i]+ceil > m) {
            c -= (k-(m*a[i])) / b[i];
            if((k-(m*a[i])) % b[i]) c--;
            c -= m;
        } else {
            c -= (k/a[i]);
            if(k%a[i]) c--;    
        }
        if(c < 0) return true;
    }
    return false;
}

void task3(vb& swapped) {
    ll x = -1;
    for(ll b = r; b >= 1; b /= 2) {
        //cout << x+b << '\n';
        while(!ok2(x+b, swapped)) x += b;
    }
    cout << x << '\n';
}

void task6(vb& swapped) {
    task3(swapped);
}

void solve(){
    cin >> n >> m;
    ans = 0;
    a.rsz(n), b.rsz(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];

    if(m == 1) {
        task1();
        return;
    }
    bool istask2 = true;
    forn(i, n) if(a[i] != b[i]) istask2 = false;
    if(n*m <= 300000 && istask2) {
        task2();
        return;
    }
    else if(istask2) {
        task5();
        return;
    }
    vb swapped(n, 0);
    forn(i, n) if(a[i] <= b[i]) swapped[i] = true, a[i] = b[i];
    if(n*m <= 300000) {
        task3(swapped);
        return;
    }
    else {
        task6(swapped);
        return;
    }
}

int main() {
    //ll t = 1000000000000000000;
    //cout << t << '\n';
    solve();
}   