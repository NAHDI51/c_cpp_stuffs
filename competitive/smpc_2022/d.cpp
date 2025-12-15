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

#define FLAG cout << "Reached here.\n"

#define pb push_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert
#define maxN 

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 10000000000
#define MIN -MAX

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int solve(int n){
    vii c(n, vi(3));
    forn(i, n) forn(j, 3) cin >> c[i][j];

    int arr[10001]{};
    forn(i, n) {
        int dif = c[i][2]-c[i][1];
        int save = c[i][0];
        while(c[i][0] >= 0) {
            arr[c[i][0]]++;
            c[i][0] -= dif;
        }
        c[i][0] = save+dif;
        while(c[i][0] <= 10000) {
            arr[c[i][0]]++;
            c[i][0] += dif;
        }
    }
    forn(i, 10001) {
        if(arr[i] == n) return i;
    }
    return -1;
}

int main() {
    int i = 0;
    while(1) {
        int n;
        cin >> n;
        if(n == 0) return 0;
        if(i != 0) cout << '\n';
        int ans = solve(n);
        cout << "Case #" << i+1 << ':' << '\n';
        if(ans != -1) cout << "The actual year is " << ans << ".\n";
        else cout << "Unknown bugs detected.\n";
        i++;
    }
}