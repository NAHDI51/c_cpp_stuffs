#include <bits/stdc++.h>

using namespace std;

#define Flag cout << "Reached here.\n";

map<int, map<int,int>> seg;

int q(int l1, int r1, int l2, int r2) {
    l1 += sz, r1 += sz;
    l2 += sz, r2 += sz;
    int sm = 0;
    for(; l1 <= r1; l1 = (l1+1)>>1, r1 = (r1-1)>>1) {
        int l = l2, r = r2;
        for(; l <= r; l = (l+1)>>1, r = (r-1)>>1) {
            if(l1%2) {
                if(l%2) sm += seg[l1][l];
                if(r%2 == 0) sm += seg[l1][r];
            }
            if(r1%2 == 0) {
                if(l%2) sm += seg[r1][l];
                if(r%2 == 0) sm += seg[r1][r];
            }
        }
    }
    return sm;
}

void upd(int i1, int i2, int val) {
    int i = i2+sz;
    i1 += sz;
    seg[i1][i] = val;
    for(i>>=1; i >= 1; i>>=1) {
        seg[i1][i] = seg[i1][i*2] + seg[i1][i*2+1];
    }

    for(i1>>=1; i1 >= 1; i1>>=1) {
        int i = i2+sz;
        seg[i1][i] = seg[i1*2][i] + seg[i1*2+1][i];
        for(i>>=1; i >= 1; i>>=1) seg[i1][i] = seg[i1][i*2]+seg[i1][i*2+1];
    }
}

#define forn(i, n) for(int i = 0; i < n; i++) 

int main() {
    forn(i, 4) forn(j, 4) {
        int c;
        cin >> c; 
        upd(i, j, c); 
    }   
    forn(i, 4) {
        forn(j, 4) cout << q(i,i,j,j) << ' ';
        cout << '\n';
    }
}