#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

const int MAXA = 200000;

ull splitmix64(ull &x) {
    ull z = (x += 0x9e3779b97f4a7c15ULL);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    return z ^ (z >> 31);
}

vector<int> primes;
void sieve_primes() {
    vector<char> is(MAXA+1, true);
    is[0]=is[1]=false;
    for (int i=2;i<=MAXA;i++) if (is[i]) {
        primes.push_back(i);
        if ((ll)i*i <= MAXA)
            for (int j=i*i;j<=MAXA;j+=i) is[j]=false;
    }
}

struct Tag { ull a,b; };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve_primes();

    // assign random tag for every possible prime up to MAXA (sized by MAXA+1)
    vector<Tag> ptag(MAXA+1, {0,0});
    ull seed = 1234567891234567ULL;
    for (int p: primes) {
        ptag[p].a = splitmix64(seed);
        ptag[p].b = splitmix64(seed);
    }

    int n; cin >> n;
    vector<pair<int,int>> nodeval(n+1); // {abs(val), sign}
    for (int i=1;i<=n;i++) {
        int x; cin >> x;
        nodeval[i].first = abs(x);
        nodeval[i].second = (x<0);
    }
    vector<vector<int>> adj(n+1);
    for (int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // factor each node value to compute its tag (XOR of prime tags for odd exponents)
    vector<Tag> valtag(n+1, {0,0});
    for (int i=1;i<=n;i++){
        int x = nodeval[i].first;
        int tmp = x;
        for (int p: primes) {
            if ((ll)p * p > tmp) break;
            int cnt = 0;
            while (tmp % p == 0) { tmp /= p; cnt ^= 1; } // parity only
            if (cnt) {
                valtag[i].a ^= ptag[p].a;
                valtag[i].b ^= ptag[p].b;
            }
        }
        if (tmp > 1) { // remaining prime
            valtag[i].a ^= ptag[tmp].a;
            valtag[i].b ^= ptag[tmp].b;
        }
    }

    // LCA via Euler + RMQ (like your version)
    vector<int> euler, depth(n+1), first(n+1, -1);
    vector<Tag> prefTag(n+1, {0,0});
    vector<int> prefNeg(n+1, 0);

    function<void(int,int,int,Tag,int)> dfs = [&](int u, int p, int d, Tag cur, int negSum){
        depth[u] = d;
        // cur is prefix tag up to parent; include node u
        cur.a ^= valtag[u].a;
        cur.b ^= valtag[u].b;
        prefTag[u] = cur;
        prefNeg[u] = negSum + nodeval[u].second;
        first[u] = euler.size();
        euler.push_back(u);
        for (int v: adj[u]) if (v!=p) {
            dfs(v, u, d+1, cur, prefNeg[u]);
            euler.push_back(u);
        }
    };

    dfs(1, -1, 0, {0,0}, 0);

    int m = euler.size();
    vector<int> seg(4*m, -1);
    function<void(int,int,int)> build = [&](int node, int l, int r){
        if (l==r) seg[node]=euler[l];
        else {
            int mid=(l+r)/2;
            build(2*node,l,mid);
            build(2*node+1,mid+1,r);
            int L = seg[2*node], R=seg[2*node+1];
            seg[node] = (depth[L] < depth[R] ? L : R);
        }
    };
    build(1,0,m-1);

    function<int(int,int,int,int,int)> rmq = [&](int node,int l,int r,int ql,int qr)->int{
        if (ql>r || qr<l) return -1;
        if (ql<=l && r<=qr) return seg[node];
        int mid=(l+r)/2;
        int left = rmq(2*node,l,mid,ql,qr);
        int right = rmq(2*node+1,mid+1,r,ql,qr);
        if (left==-1) return right;
        if (right==-1) return left;
        return (depth[left] < depth[right]? left:right);
    };

    auto lca = [&](int u,int v)->int{
        int L = first[u], R = first[v];
        if (L>R) swap(L,R);
        return rmq(1,0,m-1,L,R);
    };

    int q; cin >> q;
    while (q--) {
        int u,v; cin >> u >> v;
        int a = lca(u,v);
        // path tag: pref[u] ^ pref[v] ^ valtag[a]  (pref stores inclusive XOR from root)
        Tag path;
        path.a = prefTag[u].a ^ prefTag[v].a ^ valtag[a].a;
        path.b = prefTag[u].b ^ prefTag[v].b ^ valtag[a].b;
        int negCount = prefNeg[u] + prefNeg[v] - 2*prefNeg[a] + nodeval[a].second;
        bool nonneg = (negCount % 2 == 0);
        if (path.a==0 && path.b==0 && nonneg) cout << "Yes\n"; else cout << "No\n";
    }
    return 0;
}
