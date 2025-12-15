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

#define Flag cout << "Reached here.\n";
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

#define MAX 100000000
#define MIN -MAX

#define mod 1000000007LL

#define clr(x, y) memset(x, y, sizeof(x))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

#define N 302
#define H 202

int dp[H][H][N];
int h[N];
int n;

int memo(int last, int cur, int i) {
    if(last < 0 || cur < 0) return MAX;
    if(i == 1) {
        int mx = max(last, cur), mn = min(last, cur);
        return dp[last][cur][i] = (mn * 5) + ((mx-mn) * 3);
    }
    if(dp[last][cur][i] != -1) return dp[last][cur][i];

    dp[last][cur][i] = MAX;

    //take full
    int v = min({last, h[i-2], cur});
    if(v == cur) dp[last][cur][i] = min(dp[last][cur][i], memo(h[i-2]-v, last-v, i-1) + (7*v));

    dp[last][cur][i] = min({
        dp[last][cur][i],
        memo(last-1, cur-1, i) + 5,
        memo(last, cur-1, i) + 3,
    });
    return dp[last][cur][i];
}

void solve() {
    cin >> n;
    forn(i, n) cin >> h[i];

    if(n == 1) {    
        cout << (h[0] * 3) << '\n'; 
        return;
    }
    clr(dp, -1);
    cout << memo(h[n-2], h[n-1], n-1) << '\n';
}

int main() {
    FASTIO;
    solve();
}

/*
Let dp[last][cur][i] denote the ith element with current height and last height.
Obviously, we would want our cur to be h[i], and last to be h[i-1] in the final
answer. now, we select the minimum of the three following options: 

dp[last][cur-1][i] + 3, we are doing first operation.
dp[last-1][cur-1][i] + 5, we are doing second operation.

we don't have the third parameter. in this case, we must look at the total 
number of possible third operations we can do. Let v denote that.

Let's consider i-1. last-v will be our cur element, and maximum possible 
from i-2 will be h[i-2]-v. Thus, our candidate: 

dp[h[i-2]-v][last-v][i-1] + (7*v)
*/
