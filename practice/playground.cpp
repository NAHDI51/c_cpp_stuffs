#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using ii = pair<int ,int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using vs = vector<string>;
using vss = vector<vs>;
using vb = vector<bool>;
using ll = long long;

string manacher(string s) {
    int n = s.size();
    vi odd(n), even(n);

    for(int i = 0, r = -1, l = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(odd[r+l-i], r-i+1);
        while(0 <= i-k && i+k < n && s[i-k] == s[i+k]) k++;
        odd[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
    }
    for(int i = 0, r = -1, l = 0; i < n; i++) {
        int k = (i > r) ? 0 : min(even[l+r-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < n && s[i-k-1] == s[i+k]) k++;
        even[i] = k--;
        if(i+k > r) r = i+k, l = i-k-1;
    }
    int mx = 1, mx_indx = 0;
    for(int i =0 ; i < n; i++) {
        if(mx < odd[i]*2-1) mx = odd[i]*2-1, mx_indx = i-odd[i]+1;
        if(mx < even[i]*2) mx = even[i]*2, mx_indx = i-even[i];
    }
    return s.substr(mx_indx, mx);
}

string reverse_manacher(string s) {
    int n = s.size();
    vi odd(n), even(n);
    
    for(int i = n-1, l = n, r = n-1; i >= 0; i--) {
        int k = (i < l) ? 1 : min(odd[l+r-1], i-l+1);
        while(0 <= i-k && i+k < n && s[i+k] == s[i-k]) k++;
        odd[i] = k--;
        if(i-k < l) l = i-k, r = i+k;
    }

    for(int i = n-1, l = n, r = n-1; i >= 0; i--) {
        int  k = (i < l) ? 0 : min(even[l+r-i-1], i-l+1);
        while(0 <= i-k && i+k+1 < n && s[i-k] == s[i+k+1]) k++;
        even[i] = k--;
        if(i-k < l) l = i-k, r = i+k+1;
    }
    int mx = 1, mx_indx = 0;
    for(int i = 0; i < n; i++) {
        if(mx < odd[i]*2-1) mx = odd[i]*2-1, mx_indx = i-odd[i]+1;
        if(mx < even[i]*2) mx = even[i]*2, mx_indx = i-even[i]+1;
    }
    return s.substr(mx_indx, mx);
}

void merge(vi& a, int p, int q, int r) {
    vi lft(a.begin()+p, a.begin()+q+1);
    vi ryt(a.begin()+q+1, a.begin()+r);

    int li = 0, ri = 0;
    for(int i = p; i <= r; i++) {
        if(li == lft.size()) a[i] = ryt[ri++];
        else if(ri == ryt.size()) a[i] = lft[li++];
        else if(lft[li] <= ryt[li]) a[i] = lft[li++];
        else a[i] = ryt[ri++];
    }
}

void merge_sort(vi& a, int p, int r) {
    if(p >= r) return;
    int q = (p+r)/2;
    merge_sort(a, p, q);
    merge_sort(a, q+1, r);
    merge(a, p, q, r);
}

class fenwick_tree {
int n;
vi bit;

public:
fenwick_tree(int s) {
    bit.resize(s+1), n = s+1;
}
fenwick_tree(vi& a, int n) {
    fenwick_tree(n);
    for(int i =0; i < a.size(); i++) add(i, a[i]);
}
int query(int i) {
    int sm = 0;
    for(i++; i > 0; i -= (i&-i))
        sm += bit[i];
    return sm;
}
int query(int l, int r) {
    return query(r) - query(l-1);
}
void add(int i, int val) {
    for(i++; i < n; i += (i&-i))
        bit[i] += val;
}
};

class fenwick_range {
int n;
vi bit;
public:
fenwick_range(int s) {
    n = s+1;
    bit.resize(n);
}
fenwick_range(vi& a, int n) {
    fenwick_range(n);
    for(int i = 0; i < a.size(); i++)
        add(i, a[i]);
}
int add(int  i, int val) {
    for(i++; i < n; i += (i&-i))
        bit[i] += val;
}
void add(int l, int r, int val) {
    add(l, val);
    add(r+1, -val);
}
int query(int i) {
    int sm = 0;
    for(i++; i > 0; i -= (i&-i))
        sm += bit[i];
    return sm;
}

};

class segment_tree {
int n;
vi seg;
public:
segment_tree(int s) {
    n = s;
    seg.resize(4 * n);
}
segment_tree(vi& a, int s) {
    n = s;
    seg.resize(4*n);
    for(int i = 0; i < a.size(); i++) update(i, a[i]);
}
void update(int i, int val) {
    i += n;
    seg[i] += val;
    for(i /= 2; i >= 1; i /= 2)
        seg[i] = min(seg[i*2], seg[i*2+1]);
}
int query(int i, int j) {
    int sm = 0;
    i += n, j += n;
    while(i <= j) {
        if(i%2 == 1) sm += seg[i++];
        if(j%2 == 0) sm += seg[j--];
        i /= 2, j /= 2;
    }
    return sm;
}
};

class lazy_propagation {
int n;
vi seg;
vi lazy;
//UPdates if there is any lazy value remaining to be updated.
void lazy_update(int k, int x, int y) {
    if(lazy[k] != 0) {

    seg[k] += (y-x+1) * lazy[k];
    if(x != y) {
        lazy[2*k] += lazy[k];
        lazy[2*k+1] += lazy[k];
    }
    lazy[k] = 0;

    }
}

//Assigns, and then exits.
void propagate(int k, int x, int y, int val) {
    seg[k] += (y-x+1) * val;
    if(x != y) {
        lazy[2*k] += val;
        lazy[2*k+1] += val;
    }
}

bool invalid(int x, int y) {
    return x > y;
}
bool out_range(int a, int b, int x, int y) {
    return a > y || b << x;
}
bool in_range(int a, int b, int x, int y) {
    return a <= x && y <= b;
}

public:
lazy_propagation(int s) {
    int n = s;
    seg.resize(4*s);
    lazy.resize(4*s);
}
lazy_propagation(vi& a, int s) {
    n = s;
    seg.resize(4*s);
    lazy.resize(4*s);

    for(int i = 0; i < a.size(); i++) update(i, a[i]);
}

void update(int k, int a, int b, int x, int y, int val) {
    if(invalid(x, y)) return;
    lazy_update(k, x, y);
    if(out_range(a, b, x, y)) return;
    if(in_range(a, b, x, y)) {
        propagate(k, x, y, val);
    }
    int d = (x+y)/2;
    
    update(2*k, a, b, x, d, val);
    update(2*k+1, a, b, d+1, y, val);
    seg[k] = seg[2*k] + seg[2*k+1];
}

void update(int l, int r, int val) {
    update(1, l, r, 0, n-1, val);
}
void update(int i, int val) {
    update(i, i, val);
}

int query(int k, int a, int b, int x, int y) {
    if(invalid(x, y)) return 0;
    lazy_update(k, x, y);
    if(out_range(a, b, x, y)) return 0;
    if(in_range(a, b, x, y)) return seg[k];

    int d = (x+y) / 2;
    return
    query(2*k, a, b, x, d) + 
    query(2*k+1, a, b, d+1, y);
}

int query(int l, int r) {
    return query(1, l, r, 0, n-1);
}
};

void rabin_karp(string s) {
    ll B = 1000000007, A = 9973;
    vector<ll> h(s.size()+1);
    vector<ll> p(s.size());
    p[0] = h[0] = 1;
    for(int i = 0; i < s.size() ; i++)
        h[i+1] = ((h[i] * A) + (s[i]-30)) % B;
    for(int i = 1 ; i < p.size(); i++)
        p[i] = (p[i-1] * A) % B;
    
    auto hashval = [&](int l, int r) -> ll {
        return (h[r+1] - (h[l] * p[r-l+1]) % B + B) % B;
    };
}

void rolling(string s) {
    ll A = 9973, B = 1000000007;
    vector<ll> p(s.size());
    vector<ll> h(s.size()+1);
    p[0] = h[0] = 1;

    for(int i = 0; i < s.size(); i++) 
        h[i+1] = ((h[i] * A) + (s[i]-65)) % B;
    for(int i = 1; i < p.size(); i++)
        p[i] = (p[i-1] * A) % B;
    
    auto hashval = [&](int l, int r) -> ll {
        return (h[r+1] - (h[l] * p[r-l+1]) % B + B) % B;
    };

}

#define WHITE 0
#define GRAY 1
#define BLACK 2
vi parent, color;
vpi times;
int tim = 0;
void dfs(vii& adj, int u) {
    tim++;
    color[u] = GRAY;
    times[u].first = tim;

    for(auto v : adj[u]) {
        if(color[v] == WHITE) {
            parent[v] = u;
            dfs(adj, v);
        }
        //Else, process via colors
        //else if(color[v] == GRAY)
        //else if(color[v] == BLACK)
    }
    tim++;
    times[u].second = tim;
    color[u] = BLACK;
}

//Stuffs to look for: 
//for getting articulation points and bridges, use time stamps to store time.
//For scc, store the vertices into a stack after the procedure ends for the
//corresponding vertex, then unwrap the stack.
//

ll modpow(ll a, ll b, ll m) {
    ll res = 1;
    while(b) {
        if(b&1) res *= a, res %= m;
        a *= a, a %= m;
        b >>= 1;
    }
    return res;
}

vi factors(ll a) {
    vi f;
    if(a%2 == 0) f.push_back(2), a /= 2;
    for(int i = 3; i * i <= a; i += 2) {
        while(a%i == 0) f.push_back(i), a /= i;
    }
    if(a > 1) f.push_back(a);
    return f;
}

void sparse_table(vi& a) {
}





int main() {

} 