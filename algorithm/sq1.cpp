#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class sq {
vi seg, base;
int root, size;
public:
sq(vi& a) {
    size = ceil(sqrt(a.size()));
    root = floor(sqrt(a.size()));

    seg.resize(size);
    base = a;
    int ind = -1;
    for(int i = 0; i < a.size(); i++) {
        if(i%root == 0) ind++;
        seg[ind] += a[i];
    }
}
void update(int i, int val) {
    int ind = i/root;
    seg[ind] -= base[i];
    base[i] = val;
    seg[ind] += base[i];
}
int query(int l,int r) {
    auto L = l/root, R = r/root;
    L++;
    int sm = 0;
    if(l >= r) for(int i = l ; i <= r; i++) sm += base[i];
    else {
    for(int i = L; i < R; i++) sm += seg[i];
    for(int i = l; i < L*root; i++) sm += base[i] ;
    for(int i = R*root; i <= r; i++) sm += base[i];
    }
    return sm;
}
};

void print(vi& a) {
    for(int i = 0; i < a.size(); i++) cout << a[i] << ' ';
    cout << '\n';
}

void solve() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vi a(n);
    cout << "Enter the elements of the array: \n";
    for(int i = 0; i < n; i++) cin >> a[i];

    sq q(a);
    while(1) {
        cout << "Current array: ";
        print(a);
        cout << '\n';
        cout << "Enter range (1) or update (2): ";
        int d;
        cin >> d;
        if(d == 1) {
            int l, r;
            cout << "Enter the range (l,r): ";
            cin >> l >> r;
        
            cout << "Range sum { ";
            for(int i = l; i <= r; i++) cout << a[i] << ' ';
            cout << "} : " << q.query(l, r) << '\n';
        } else {

            cout << "Enter the index and element: ";
            int i, el;
            cin >> i >> el;
            cout << "Replaced " << a[i] << " With " << el << '\n';
            a[i] = el;
            q.update(i, el);
        }
    }
}

int main() {
    solve();
}