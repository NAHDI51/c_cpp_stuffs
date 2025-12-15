#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;
using ii = pair<int , int>;
using vll= vector<ll>;
using vvll = vector<vll>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using vb = vector<bool>;
using vbb = vector<vb>;
using vs = vector<string>;
using vss = vector<vs>;
using table = unordered_map<ll, int>;

/*
The square root algorithm divides the main array in segments of square roots of n, each one of the 
roots storing some sort of information about the segment.
It supports query in root N time and update in O(1) time.
*/

class square_root {
vi seg;
vi base;
int size;

public:
square_root(vi& a) {
    //Seg represents each one of the segments.
    size = (int)(ceil(sqrt(a.size())));
    seg.resize(size);
    //Base is the original array.
    base = a;
    int ind = 0;
    for(int i = 0; i < a.size(); i++) {
        seg[ind] += a[i];
        if((i+1)%size == 0) ind++;
    }
}

void update(int i, int val) {
    int ind = i/size;
    seg[ind]-= base[i];
    base[i] = val;
    seg[ind] += base[i];
}

int query(int l, int r) {
    int L = (l+1)/size+1, R = (r+1)/size;
    L--, R--;
    int sm = 0;

    for(int i = L; i <= R; i++) sm += seg[i];

    for(int i = l; i <= L*size-1; i++) sm += base[i];
    for(int i = (R+1)*size; i <= r; i++) sm += base[i];
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

    square_root q(a);
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