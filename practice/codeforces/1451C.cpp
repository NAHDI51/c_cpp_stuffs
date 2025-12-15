
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

ll modpow(ll a, ll b) {
    ll sm = 1;
    while(b) {
        if(b&1) sm *= b, sm %= mod;
        a *= a, a &= mod;
        b >>= 1;
    }
    return sm;
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

/*
Firstly, we can move any elements to anywhere we want. That leaves us with only the 2nd option.

When we encounter an letter, we have some situations for the letter:
1. We just have the required amount of that letter. In that case, no 2nd operations shall be performed on
the letter.
2. We have more than required amount of that letter. Then we verify if we can pass that character
to the next one, that is, if count[c]-need[c] % k == 0 or not.
3. If we have less than required, we simply return false, that it is not opossible to format the string
according to the requirements.
*/

void solve() {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;

    int cnt[126]{}, req[126]{};
    forn(i,n) cnt[a[i]]++;
    forn(i,n) req[b[i]]++;

    forn(i, 26) {
        if(cnt[i+97] == req[i+97]) continue;
        else if(cnt[i+97] < req[i+97]) {
            cout << "NO\n";
            return;
        //Pass down to the next character.
        } else {
            if((i+97) == 'z') {
                cout << "NO\n";
                return;
            }
            if((cnt[i+97]-req[i+97]) % k) {
                cout << "NO\n";
                return;
            } else cnt[i+97+1] += (cnt[i+97]-req[i+97]);
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    int t;
    cin >> t;
    while((t--)) {
        solve();
    }

}

