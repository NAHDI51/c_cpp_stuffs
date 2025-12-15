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

#define SF cout << "Reached here.\n"

#define pb push_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert
#define maxN 

#define MAX 10000000000
#define MIN -MAX

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int solve(){
    int n, p;
    cin >> n >> p;

    bool dec, inc;
    dec = inc = 0;

    int i = 1;
    if(p <= 0) dec = true;
    else inc = 0;
    while(1) {
        int q = n-(i*p);
        if(q <= 0) return -1; //we can't make negative adding power 2.
        if(dec && (q < i)) return -1;
        if(__builtin_popcount(q) <= i && i <= q) return i;
        i++;
    }
    
    cout << -1 << '\n';
}

int main() {
    cout << solve() << '\n';
}