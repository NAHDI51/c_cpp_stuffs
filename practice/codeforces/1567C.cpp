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
    string n;
    cin >> n;
    int n1 = 0, n2 = 0;
    int i;

    string s1, s2;
    forn(i, n.size()) {
        if(i%2) s1.pb(n[i]);
        else s2.pb(n[i]);
    }
    n1 = atoi(s1.c_str()), n2 = atoi(s2.c_str());

    cout << ((n1+1)*(n2+1)-2) << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}