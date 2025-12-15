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

#define lb lower_bound
#define ub upper_bound

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void solve(){
    ll n;
    cin >> n; 
    vll a(n);
    forn(i, n) cin >> a[i];
    vll nums, pref(n);

    forn(i, n) {
        ll t = 0, tmp = a[i];
        while(tmp%2 == 0) tmp /= 2, t++;
        nums.pb((ll)pow(2LL, t));
    }
    pref[0] = nums[0];
    for(int i = 1; i < pref.sz(); i++) pref[i] = pref[i-1] + nums[i];

    int q;
    cin >> q;
    forn(i, q) {
        ll x;
        cin >> x;
        auto ind = lb(all(pref), x) - pref.begin();
        cout << a[ind] / nums[ind] << '\n';
    }
}

int main() {
    solve();
}