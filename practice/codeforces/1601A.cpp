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

#define pb push_back
#define sz size
#define maxN 

#define MAX 1000000000
#define MIN -MAX

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void solve(){
    int n;
    cin >> n;
    vi bit(31);
    forn(i, n) {
        int a;
        cin >> a;
        forn(j, 31) if(a&(1<<j)) bit[j]++;
    }
    for1n(i, n) {
        int pt = 0;
        forn(j, 31) if(!(bit[j]%i)) pt++;
        if(pt == 31) cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}