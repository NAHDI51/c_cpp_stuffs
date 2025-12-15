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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    int sm = 0;
    forn(i, n) cin >> a[i];
    forn(i, n ) sm +=a[i];
    if(sm%2) {
        cout << 0 << '\n';
        return;
    }
    vb dp(sm/2+2);
    dp[0] = true;
    forn(i, n) rof(j, sm/2+2) if(j-a[i] >= 0 && dp[j-a[i]]) dp[j] = true;

    if(!dp[sm/2]) cout << 0 << '\n';
    else {
        cout << 1 << '\n';
        int mn = beg0(a[0]),midx = 0;
        forn(i, n) {
            if(mn > beg0(a[i])) mn = beg0(a[i]), midx = i;
        }
        cout << midx+1 << '\n';
    }
}

int main() {
    solve();
}