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
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

#define pb push_back
#define pbb pop_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert
#define maxN 100000

#define lb(a, val) lower_bound(all(a), val);
#define ub(a, val) upper_bound(all(a), val);

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 1000000000000000001LL
#define MIN -MAX

#define clr(x, y) memset(x, y, sizeof(x))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

#define mod 1000000007LL

ll binpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a, res %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return res;
}


ll nCr(ll n, ll r) {
    ll ans = 1;
    r = min(r, n-r);

    for(int j = 1; j <= r; j++, n--) {
        if(!(n%j)) ans *= n/j;
        else if(!(ans%j)) ans = (ans/j) * n;
        else ans = (ans*n)/j;
        ans %= mod;
    }
    return ans;
}

vi fact(ll n) {
    vi fac;
    while(n%2 == 0) n /= 2, fac.pb(2);
    for(int i = 3; i * i <= n; i += 2) 
        while(n%i == 0) fac.pb(i), n /= i;
    if(n > 1) fac.pb(n);
    return fac;
}

int gcd(int a, int b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

/*
Keep a set of disjoint set. When we add an interval, keep the highest l interval, ans see if it merges
Keep the lowest r interval, and see it merges. Then, delete everything in between.

Now, if it falls within an interval, in otherwords, if 1.l <= 2.l and 2.r <= 1.r, then we don't add

for query, iterate through the set, and for each of the sub interval, (r-l+1)(r-l+2)/2 + (r-l+1)
*/

ll mult(ll a, ll b) {
    return ((a%mod) * (b%mod)) % mod;
}

using pll= pair<ll, ll>;

void add(set<pll>& st) {
    ll l, r;
    cin >> l >> r;

    //Strictly bigger than l
    auto one = upper_bound(all(st), pll{l-1, MAX});
    //interval equal or smaller than current l.

    one--;
    if(one->f <= l && one->s <= r) return;
    //Otherwise, mergable

    //We need something equal smaller than r.
    auto two = upper_bound(all(st), pll{r+1, MIN});
    two--;

    //If they are equal, we can merge and be done with it
    if(one == two) {
        if(one->s >= (l-1)) st.ins({min(l, one->f), max(one->s, r)});
        st.erase(one);
        return;
    }

    //Otherwise, merge  if possible, and erase everything in between.
    if(one->s >= (l-1)) l = min(l, one->f);
    if(two->f <= (r+1)) r = max(r, two->s);

    auto del = vector<_Rb_tree_const_iterator<pll>> {one, two}; 
    for(++one; one != two; one++) {
        if(l <= one->f && one->s <= r) del.pb(one);
    }

    for(auto x = del.begin(); x != del.end(); x++) {
        if((*x)->f == MAX && (*x)->s == MAX) continue;
        if((*x)->f == MIN && (*x)->s == MIN) continue;
        st.erase(*x);
    }
    st.ins({l, r});
}

void solve() {
    int n;
    cin >> n;

    set<pair<ll, ll>> st;
    st.ins({MIN, MIN});
    st.ins({MAX, MAX});

    forn(i, n) {
        int c;
        cin >> c;
        if(c == 1) {
            add(st);
        }
        else {
            Flag;
            ll l, r;
            cin >> l >> r;
            ll ans = 0;
            for(auto x : st) {
                if(x.f == MAX && x.s == MAX) continue;
                if(x.f == MIN && x.s == MIN) continue;
                if(x.f < l || x.s > r) continue;

                auto t = (mult(x.s-x.f+1LL, x.s-x.f+2LL) / 2LL) + ((x.s-x.f+1LL)%mod);
                ans += t, ans %= mod;
            }
            cout << ans << '\n';
        }
    }
}

int main() {
    solve();
}

