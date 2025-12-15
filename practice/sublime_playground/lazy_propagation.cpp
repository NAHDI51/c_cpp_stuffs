#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using vb = vector<bool>;
using vbb = vector<vb>;
using vss =vector<vs>;

#define forn(i, n) for(int i = 0; i < n; i++)
#define for1n(i, n) for(int i = 1; i <= n; i++)
#define rofn(i, n) for(int i = n-1; i >= 0; i--)
#define rof1n(i, n) for(int i = n; i >= 1; i--)
#define fore(i, a, b) for(int i = a; i <= b; i++)
#define rofe(i, a, b) for(int i = b; i >= a; i--);
#define all(x) x.begin(), x.end()

#define pb(x) push_back(x)
#define ins(x) insert(x)
#define sz(x) size(x)
#define rsz(x) resize(x)
#define pbb() pop_back() 

#define f first
#define s second

#define Flag cout << "Reached here.\n";
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define MAX 1000000000LL 
#define MIN -MAX;
#define mod 1000000007LL 

#define clr(x, y) memset(x, 0, sizeof(x));

//0001101100
#define end0(x) __builtin_clz(x) //3
#define beg0(x) __builtin_ctz(x) //2
#define onec(x) __builtin_popcount(x) // 4
#define end0ll(x) __builtin_clzll(x)
#define beg0ll(x) __builtin_ctzll(x) 
#define onecll(x) __builtin_popcountll(x)

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void init() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

ll binpow(ll a, ll b) {
	ll sm = 1;
	while(b) {
		if(b&1) sm *= a, sm %= mod;
		a *= a, a %= mod;
		b >>= 1;
	}
	return sm;
}


#define maxN 100001

/*
ll fact[maxN], finv[maxN];
build_ncr(int n) {
	fact[0] = 1, finv[0] = ll;	
	for1n(i, n-1) fact[i] = fact[i-1] * i, fact[i] %= mod;
	for1n(i, n-1) finv[i] = binpow(fact[i], mod-2);
}

ll ncr(ll n, ll k) {
	return ((fact[n] * finv[k]) % mod) * finv[n-k]) % mod;
}
*/

/*
int spf[maxN];
vi factor[maxN];
void sieve(int n) {
	spf[1] = 1;
	for(int i = n; i >= 2; i--)	
		for(int j = i; j <= n; j += i) 
			spf[j] = i;

	for(int i = 2; i <= n; i++)
		for(int j = i; j != 1; j /= spf[j])
			factor[i].pb(spf[j]);
}
*/

ll seg[maxN*4], lzy[maxN*4];
class lazy_propagation {
int n;

bool inrng(int a, int b, int x, int y) {return a > y || b < x;}
bool outrng(int a, int b, int x, int y) {return a <= x && y <= b;}
bool inv(int x, int y) {return x > y;}
void lzyupd(int k, int x, int y) {
	if(lzy[k]) {
		seg[k] = (y-x+1) * lzy[k];
		if(x != y) lzy[2*k] += lzy[k], lzy[2*k+1] += lzy[k] ;
		lzy[k] = 0;
	}
}
void prop(int k, int x, int y, int val) {
	seg[k] = (y-x+1) * val;
	if(x != y) lzy[2*k] = val, lzy[2*k+1] = val ;
}

public:
lazy_propagation(vi& a) {
	n = a.sz();
	forn(i, n) upd(i, a[i]);
}
void upd(int k, int a, int b, int x, int y, int val) {
	if(inv(x, y)) return;
	lzyupd(k, x, y);
	if(outrng(a, b, x, y)) return;
	if(inrng(a,b,x,y)) prop(k, x, y, val);

	int d = (x+y)/2;
	upd(2*k, a, b, x, d, val), upd(2*k+1, a, b, d+1, y, val);
	seg[k] = seg[2*k] + seg[2*k+1];
}
void upd(int l, int r, int val) {upd(1, l, r, 0, n-1, val)}
void upd(int i, int val) {upd(i, i, val)}

ll q(int k, int a, int b, int x, int y) {
	if(inv(x, y)) return 0;
	lzyupd(k, x, y);
	if(outrng(a,b,x,y)) return 0;
	if(inrng(a,b,x,y)) return seg[k];
	int d = (x+y)/2;
	return q(2*k,a,b,x,d)+q(2*k+1,a,b,d+1,y);
}
ll q(int l, int r) {return q(1, a, b, 0, n-1);}
ll q(int i) {return q(i, i);}
};


void solve() {
	cout << "Hello world.\n";
}

int main() {
	init();
	fastio;
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	//solve();
};