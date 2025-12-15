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

#define FLAG cout << "Reached here.\n"

#define pb push_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert
#define maxN 

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 10000000000
#define MIN -MAX

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void solve(){
    int n, m;
    cin >> n >> m;
    vii a(n, vi(m));
    forn(i, n) forn(j, m) cin >> a[i][j];

    if(n == 1) {
        forn(i, m) if(a[0][i] != 0) {
            cout << "TAK\n";
            cout << i+1 << '\n';                                                                                                                                                        
            return;
        }
        cout << "NIE\n";
        return;
    }

    vi dp(n), ind(n, 0), suf(n), pref(n);
    pref[0] = a[0][0];
    suf[n-1] = a[n-1][0];

    for(int i = 1; i < n; i++) pref[i] = pref[i-1] ^ a[i][0];
    for(int i = n-2; i >= 0; i--) suf[i] = a[i][0] ^ suf[i+1];

    dp[0] = suf[1], dp[n-1] = pref[n-2];
    
    for1n(i, n-2) dp[i] = pref[i-1] ^ suf[i+1];

    forn(i, n) {
        forn(j, m) {
            if(dp[i] ^ a[i][j]) {
                ind[i] = j;
                //cout << i << ' ' << ind[i] << ' ' << a[i][ind[i]] << '\n';
                goto good_end;
            }
        }
    }
    cout << "NIE\n";
    return;

    good_end:
    cout << "TAK\n";
    forn(i, n) cout << ind[i]+1 << ' ';
    cout << '\n';
}

int main() {
    solve();
}