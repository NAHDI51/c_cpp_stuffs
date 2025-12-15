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

int dp[101][101];
int tot[101][101];

int mex(vi& a, int l, int r) {
    map<int ,int> mp;
    fore(i, l, r) mp[a[i]]++;
    for(int i = 0; i < 1e9; i++) if(mp.find(i) == mp.end()) return i;
}

void solve(){
    memset(dp, 0, sizeof(dp));
    //memset(tot, 0, sizeof(tot));
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >>a[i];

    
    forn(i, n) dp[i][i] = mex(a, i, i)+1;
    for(int i = 1; i < n; i++) {
        for(int j = i-1; j >= 0; j--) {
            dp[j][i] = mex(a, j, i)+1;
            for(int k = j; k < i; k++) {
                if(dp[j][i] < dp[j][k]+dp[k+1][i])
                    dp[j][i] = dp[j][k]+dp[k+1][i];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) ans += dp[i][j];
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}