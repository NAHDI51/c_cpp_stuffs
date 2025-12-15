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

int count(string& s, int p, int r, char c) {
    int cnt = 0;
    fore(i, p-1, r-1) if(s[i] == c) cnt++;
    return ((r-p+1) - cnt);
}

int go(string& s, int p, int r, char c) {
    if(p == r) return (s[p-1] != c);
    else {
        int q = p+((r-p)/2);
        int lft = count(s, p, q, c) + go(s, q+1, r, c+1);
        int ryt = count(s, q+1, r, c) + go(s, p, q, c+1);
        return min(lft, ryt);
    }
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << go(s, 1, n, 'a') << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}