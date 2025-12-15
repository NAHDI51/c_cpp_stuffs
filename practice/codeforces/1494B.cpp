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

//So if we have corner cases, then we need to consider it in terms of that number.
bool solve(){
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;

    table opp;
    opp[u] = d, opp[d] = u, opp[l] = r, opp[r] = l;

    if(n == 2) {
        
    }

    if(u >= 2 && r >= 2 && d >= 2 && l >= 2) return true;
    else {
        if(u == 0 && opp[u] == 0) {
            if(l > n-2 || r > n-2) return false;
        }
        if((u == 1 && opp[u] == 0) || (d == 1 && opp[d] == 0)) {
            if(l == n-1 && r > n-2) return false;
            if(r == n-1 && l > n-2) return false;
            if(l == n || r == n) return false;
        }
        if(u == 1 && opp[u] == 1) {
            if(l == n && r > n-2) return false;
            if(r == n && l > n-2) return false;
        }
        if(l == 0 && opp[l] == 0) {
            if(u > n-2 || opp[u] > n-2) return false;
        }
        if((l == 1 && opp[l] == 0) || (opp[l] == 1 && l == 0)) {
            if(u == n-1 && opp[u] > n-2) return false;
            if(opp[u] == n-1 && u > n-2) return false;
            if(opp[u] == n || u == n) return false;
        }
        if(l == 1 && opp[l] == 1) {
            if(u == n && opp[u] > n-2) return false;
            if(opp[u] == n && u > n-2) return false;
        }
        return true;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        if(solve()) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}