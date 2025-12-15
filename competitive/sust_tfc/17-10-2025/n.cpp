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

#define MAX 1000000000
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

struct Fenwick {
    int n; 
    vector<long long> bit;
    Fenwick(int n): n(n), bit(n+1,0) {}
    void add(int i,long long v){ 
        for(++i;i<=n;i+=i&-i) bit[i]+=v; 
    }
    void rangeAdd(int l,int r,long long v){ 
        add(l,v); add(r+1,-v); 
    }
    long long sum(int i){ 
        long long s=0; for(++i;i>0;i-=i&-i) s+=bit[i]; 
        return s; 
    }
    long long rangeSum(int l,int r){ 
        return sum(r)-sum(l-1); 
    }
};

int timer = 0;
vi tin, tout, euler;

void dfs(int u, int p, vii &adj, vi &hel) {
    tin[u] = timer++;
    euler[tin[u]] = hel[u];
    for(int v : adj[u]) if(v != p) {
        dfs(v, u, adj, hel);
    }
    tout[u] = timer-1;
}

void solve() {
    int n;
    cin >> n;
    vi hel(n+1);
    vii adj(n+1);
    vi par(n+1);

    for1n(i, n) {
        int h, p;
        cin >> h >> p;
        hel[i] = h;
        par[i] = p;
    }
    for1n(i, n) adj[par[i]].pb(i);

    tin.assign(n+1,0);
    tout.assign(n+1,0);
    euler.assign(n+1,0);

    dfs(0,-1,adj,hel);
 

    Fenwick decBIT(n+2);   // track total decrements
    Fenwick aliveBIT(n+2); // track alive nodes

    for(int i=0;i<=n;i++) aliveBIT.add(tin[i],1);

    // min-heap (health, node)
    using P=pair<long long,int>;
    priority_queue<P,vector<P>,greater<P>> pq;
    for(int i=0;i<=n;i++) pq.push({hel[i],i});

    int q;cin>>q;
    while(q--){
        int type;cin>>type;
        if(type==1){
            int u,x;cin>>u>>x;
            if(tin[u]+1<=tout[u]){
                decBIT.rangeAdd(tin[u]+1,tout[u],x);

                // process deaths
                while(!pq.empty()){
                    auto [thr,v]=pq.top();
                    long long totalDec = decBIT.sum(tin[v]);
                    if(totalDec >= thr){ // node dies
                        pq.pop();
                        if(aliveBIT.rangeSum(tin[v],tin[v])==1){
                            aliveBIT.add(tin[v],-1);
                        }
                    } else {
                        break;
                    }
                }
            }
        } else {
            int u;cin>>u;
            int ans=0;
            if(tin[u]+1<=tout[u])
                ans = aliveBIT.rangeSum(tin[u]+1,tout[u]);
            cout<<ans<<"\n";
        }
    }
}

int main() {
    //Sublime
    // init();
    FASTIO;
    solve();
}

