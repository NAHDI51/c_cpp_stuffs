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
    return a > y || b < x;
}
bool in_range(int a, int b, int x, int y) {
    return a <= x && y <= b;
}

public:
lazy_propagation(int s) {
    n = s;
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