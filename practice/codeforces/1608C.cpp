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
#define rof(i, n) for(int i = n-1; i >= 0; i--)
#define rofe(i, a, b) for(int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
#define dsc(type) greater<type>

#define pb push_back
#define sz size
#define maxN 

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void solve(){
	int n;
	cin >> n;
	vii a(n, vi(3));

	forn(i, n) cin >> a[i][0];
	forn(i, n) {
        cin >> a[i][1];
        a[i][2] = i;
    }

	sort(all(a));

	vi pref(n);
	forn(i, n){
		pref[i] = a[i][1];
		if(i)ckmax(pref[i],pref[i-1]);
	}

	string ans(n,'0');
	ans[a[n-1][2]] = '1';
	int sml = a[n-1][1];

	rof(i, n-1) {
		if(pref[i] < sml) break;
		ckmin(sml,a[i][1]);
		ans[a[i][2]] = '1';
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