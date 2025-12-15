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
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define pb push_back
#define pbb pop_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert

#define MAX 1000000000ll
#define MIN -MAX

#define mod 1000000007LL

#define maxN 1000005

int spf[maxN];

void sieve() {
    forn(i, maxN) spf[i] = -1;
    for(int i = 2; i < maxN; i++) {
        if(spf[i] == -1) {
            spf[i] = i;
            for(int j = i+i; j < maxN; j += i) {
                if(spf[j] == -1) spf[j] = i;
            }
        }
    }
}

void solve() {
    vi lo(maxN);
    vll ans(maxN);
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));

    auto fact = [&](int n) -> void{
        int num = n;
        map<int,bool> vis;
        while(n != 1) {
            int cur = spf[n];
            while(cur == spf[n]) n /= spf[n];
            if(!lo[cur]) lo[cur] = num;
            else {
                if(!vis[lo[cur]]) {
                    vis[lo[cur]] = true;
                    ans[lo[cur]] += num;
                }
            }
        }
    };
    ll sm = 0;
    forn(i, n) {
        sm += a[i];
        fact(a[i]);
    }

    ll mx = 0;
    for(int i = 2; i < maxN; i++) {
        // if(ans[i]) {
            // cout << i << ' ' << ans[i] << '\n';
        //}
        mx = max(mx, ans[i]);
    }
    cout << mx + sm << '\n';

}

int main() {
    //Sublime
    // init();
    // FASTIO;

    sieve();
    solve();
}

