#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <initializer_list>
#include <tuple>

using namespace std;


using vi = vector<int>;
using vii = vector<vi>;
// using vs = vector<string>;
// using vss = vector<vs>;
using vb = vector<bool>;
using vbb  = vector<vb>;
using ii = pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using table = unordered_map<unsigned long, int>;
using pll = pair<ll,ll>;
using vpl = vector<pll>;
using vpll = vector<vpl>;

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

#define lb(a, val) lower_bound(all(a), val);
#define ub(a, val) upper_bound(all(a), val);

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 1000000000ll
#define MIN -MAX

#define mod 1000000007LL

#define clr(x, y) memset(x, y, sizeof(x))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void init() {
    #ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    #endif
}

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

vi fct(ll n) {
    vi fac;
    while(n%2 == 0) n /= 2, fac.pb(2);
    for(int i = 3; i * i <= n; i += 2) 
        while(n%i == 0) fac.pb(i), n /= i;
    if(n > 1) fac.pb(n);
    return fac;
}

ll gcd(ll a, ll b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a*b) / gcd(a, b);
}

#define maxN 

using vss=vector<string>;
int n, m;
void dfs(int x, int y, vii& vis, vss& vs, vpi& cur) {
    vis[x][y] = true;
    cur.pb({x,y});
    forn(i, 4) {
        int nx = x+dx[i], ny = y+dy[i];
        if(nx >= 0 && nx <= n-1 && ny >= 0 && ny <= m-1 && 
            !vis[nx][ny] && vs[nx][ny] == '#') {
            dfs(nx,ny,vis,vs,cur);
        }
    }
}


void solve() {
    cin >> n >> m;
    vss vs(n);
    forn(i, n) cin >> vs[i];
    vii vis(n, vi(m)), cc(n, vi(m));

    int comp = 1;
    forn(i, n) {
        forn(j, m) {
            if(!vis[i][j] && vs[i][j] == '#') {
                vpi cur;
                dfs(i,j,vis,vs,cur);
                for(auto x : cur) {
                    vis[x.f][x.s] = cur.sz();
                    cc[x.f][x.s] = comp;
                }
                comp++;
            } 
        }
    }
    /*
    forn(i, n) {
        forn(j, m) {
            cout << cc[i][j] << "  ";
        }
        cout << '\n';
    }
    cout << '\n';
    forn(i, n) {
        forn(j, m) {
            cout << vis[i][j] << "  ";
        }
        cout << '\n';
    }
        */
    int mx = 0;
    ii con;
    forn(i, n) {
        int cur = 0;
        set<int> st;
        forn(j, m) {
            if(cc[i][j] != 0 && st.find(cc[i][j]) == st.end()) {
                st.ins(cc[i][j]);
                cur += vis[i][j];
            } else {
                if(cc[i][j] == 0) cur++;
            }
            /*
            if(j+1 <= m-1 && cc[i][j+1] != 0 && 
                st.find(cc[i][j+1]) == st.end()) {

                st.ins(cc[i][j+1]);
                cur += vis[i][j+1];
            }
            if(j-1 >= 0 && cc[i][j-1] != 0 &&
            st.find(cc[i][j-1]) == st.end()) {
                st.ins(cc[i][j-1]);
                cur += vis[i][j-1];
            }
            */
           if(i+1 <= n-1 && cc[i+1][j] != 0 &&
                st.find(cc[i+1][j]) == st.end()) {
                // cout << "two \n";
                st.ins(cc[i+1][j]);
                cur += vis[i+1][j];
            }
            if(i-1 >= 0 && cc[i-1][j] != 0 &&
            st.find(cc[i-1][j]) == st.end()) {
                // cout << "three\n";
                st.ins(cc[i-1][j]);
                cur += vis[i-1][j];
            }
            // cout << cur << ' ';
        }
        /*
        for(auto x : st) {
            cout << x << ' ';
        }*/
        // cout << i << ' ' << cur << '\n';
        
        if(mx < cur) {
            mx = cur;
            con = {0, i};
        }
    }
    forn(j, m) {
        int cur = 0;
        set<int> st;
        forn(i, n) {
            if(cc[i][j] != 0 && st.find(cc[i][j]) == st.end()) {
                // cout << "one \n";
                st.ins(cc[i][j]);
                cur += vis[i][j];
            } else {
                if(cc[i][j] == 0) cur++;
            }
            /*
            if(i+1 <= n-1 && cc[i+1][j] != 0 &&
                st.find(cc[i+1][j]) == st.end()) {
                // cout << "two \n";
                st.ins(cc[i+1][j]);
                cur += vis[i+1][j];
            }
            if(i-1 >= 0 && cc[i-1][j] != 0 &&
            st.find(cc[i-1][j]) == st.end()) {
                // cout << "three\n";
                st.ins(cc[i-1][j]);
                cur += vis[i-1][j];
            }
            */
           if(j+1 <= m-1 && cc[i][j+1] != 0 && 
                st.find(cc[i][j+1]) == st.end()) {

                st.ins(cc[i][j+1]);
                cur += vis[i][j+1];
            }
            if(j-1 >= 0 && cc[i][j-1] != 0 &&
            st.find(cc[i][j-1]) == st.end()) {
                st.ins(cc[i][j-1]);
                cur += vis[i][j-1];
            }
            // cout << cur << ' ';
        }
        /*
        for(auto x : st) {
            cout << x << ' ';
        }*/
        // cout << j << ' ' << cur << '\n';
        
        if(mx < cur) {
            mx = cur;
            con = {1, j};
        }
    }
    if(con.f == 0) forn(j, m) vs[con.s][j] = '#';
    else forn(i, n) vs[i][con.s] = '#';

    forn(i, n) {
        forn(j, m) {
            vis[i][j] = 0, cc[i][j] = 0;
        }
    }

    comp = 1;
    forn(i, n) {
        forn(j, m) {
            if(!vis[i][j] && vs[i][j] == '#') {
                vpi cur;
                dfs(i,j,vis,vs,cur);
                for(auto x : cur) {
                    vis[x.f][x.s] = cur.sz();
                    cc[x.f][x.s] = comp;
                }
                comp++;
            } 
        }
    }
    int mx2 = mx;
    // if(con.f == 0) {
        forn(j, m) {
            int cur = 0;
            set<int> st;
            forn(i, n) {
                if(cc[i][j] != 0 && st.find(cc[i][j]) == st.end()) {
                    // cout << "one \n";
                    st.ins(cc[i][j]);
                    cur += vis[i][j];
                } else {
                    if(cc[i][j] == 0) cur++;
                }
                /*
                if(i+1 <= n-1 && cc[i+1][j] != 0 &&
                    st.find(cc[i+1][j]) == st.end()) {
                    // cout << "two \n";
                    st.ins(cc[i+1][j]);
                    cur += vis[i+1][j];
                }
                if(i-1 >= 0 && cc[i-1][j] != 0 &&
                st.find(cc[i-1][j]) == st.end()) {
                    // cout << "three\n";
                    st.ins(cc[i-1][j]);
                    cur += vis[i-1][j];
                }
                */
            if(j+1 <= m-1 && cc[i][j+1] != 0 && 
                    st.find(cc[i][j+1]) == st.end()) {

                    st.ins(cc[i][j+1]);
                    cur += vis[i][j+1];
                }
                if(j-1 >= 0 && cc[i][j-1] != 0 &&
                st.find(cc[i][j-1]) == st.end()) {
                    st.ins(cc[i][j-1]);
                    cur += vis[i][j-1];
                }
                // cout << cur << ' ';
            }
            /*
            for(auto x : st) {
                cout << x << ' ';
            }*/
            // cout << j << ' ' << cur << '\n';
            
            if(mx < cur) {
                mx = cur;
                con = {1, j};
            }
        }
    // }
    // else {
        forn(i, n) {
            int cur = 0;
            set<int> st;
            forn(j, m) {
                if(cc[i][j] != 0 && st.find(cc[i][j]) == st.end()) {
                    st.ins(cc[i][j]);
                    cur += vis[i][j];
                } else {
                    if(cc[i][j] == 0) cur++;
                }
                /*
                if(j+1 <= m-1 && cc[i][j+1] != 0 && 
                    st.find(cc[i][j+1]) == st.end()) {

                    st.ins(cc[i][j+1]);
                    cur += vis[i][j+1];
                }
                if(j-1 >= 0 && cc[i][j-1] != 0 &&
                st.find(cc[i][j-1]) == st.end()) {
                    st.ins(cc[i][j-1]);
                    cur += vis[i][j-1];
                }
                */
            if(i+1 <= n-1 && cc[i+1][j] != 0 &&
                    st.find(cc[i+1][j]) == st.end()) {
                    // cout << "two \n";
                    st.ins(cc[i+1][j]);
                    cur += vis[i+1][j];
                }
                if(i-1 >= 0 && cc[i-1][j] != 0 &&
                st.find(cc[i-1][j]) == st.end()) {
                    // cout << "three\n";
                    st.ins(cc[i-1][j]);
                    cur += vis[i-1][j];
                }
                // cout << cur << ' ';
            }
            /*
            for(auto x : st) {
                cout << x << ' ';
            }*/
            // cout << i << ' ' << cur << '\n';
            
            if(mx < cur) {
                mx = cur;
                con = {0, i};
            }
        }
    // }
    /*
    forn(i, n) {
        forn(j, m) {
            cout << cc[i][j] << "  ";
        }
        cout << '\n';
    }
    cout << '\n';
    forn(i, n) {
        forn(j, m) {
            cout << vis[i][j] << "  ";
        }
        cout << '\n';
    }
        */
    cout << mx << '\n';
}

int main() {
    //Sublime
    // init();
    // FASTIO;

    int t;
    cin >> t;
    while(t--) solve();
}

