#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define mod 998244353
#define N 200005
 
vector<pii> pf[N];
int p[N];
vector<pair<int, pii>> g[N];
int cnt[N];
int mx[N];
 ll val[N];
ll b[N];
ll up[N];
vector<int> used;
 
ll powerMod(ll x, ll y, ll p){
    ll res = 1 % p;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
ll inverseMod(ll a, ll x){
    return powerMod(a, x - 2, x);
}
 
void dfs(int u, int p){
    for(auto v: g[u]){
        if(v.ff==p) continue;
 
        ll x = v.ss.ff;
        ll y = v.ss.ss;
        
        for(auto p: pf[y]){
            up[p.ff] += p.ss;
        }
 
        map<int, int> mp;
 
        ll xx = x;
        for(auto p: pf[x]){
            int rem = min((ll) p.ss, up[p.ff]);
            up[p.ff] -= rem;
            mp[p.ff] = rem;
            while(rem--){
                xx /= p.ff;
            }
        }
 
        ll zz = (inverseMod(x, mod)*y)%mod;
        ll vvv = (zz*val[u])%mod;
        val[v.ff] = vvv;
        b[v.ff] = xx;
        dfs(v.ff, u);
 
        for(auto it: mp){
            up[it.ff] += it.ss;
        }
 
        for(auto p: pf[y]){
            up[p.ff] -= p.ss;
        }
    }
}
 
void dfs2(int u, int p){
    for(pii p: pf[b[u]]){
        cnt[p.ff] += p.ss;
        mx[p.ff] = max(mx[p.ff], cnt[p.ff]);
    }
 
    for(auto v: g[u]){
        if(v.ff==p) continue;
        dfs2(v.ff, u);
    }
 
    for(pii p: pf[b[u]]){
        cnt[p.ff] -= p.ss;
        used.pb(p.ff);
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    for(int i = 2; i < N; i++){
        if(p[i]) continue;
        for(int j = i; j < N; j+=i){
            p[j] = 1;
            ll z = j;
            int c = 0;
            while(z%i==0){
                c++;
                z /= i;
            }
            pf[j].pb({i, c});
        }
    }
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
 
        used.clear();
        for(int i = 0; i <= n; i++){
            g[i].clear();
            val[i] = 0;
            b[i] = 0;
        }
 
        for(int i = 0; i < n-1; i++){
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            int gcd = __gcd(x, y);
            x /= gcd;
            y /= gcd;
            g[u].pb({v, {x, y}});
            g[v].pb({u, {y, x}});
        }
 
        val[1] = 1;
        b[1] = 1;
 
        dfs(1, 0);
        dfs2(1, 0);
 
        ll res = 1;
 
        for(int z: used){
            if(mx[z]==-1) continue;
            res = (res * powerMod(z, mx[z], mod))%mod;
            mx[z] = -1;
        }
 
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            ans = (ans + (res*val[i])%mod)%mod;
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}