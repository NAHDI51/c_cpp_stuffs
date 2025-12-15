#include <bits/stdc++.h>
using namespace std;

#define maxN 20005
class segment_tree {
vector<int> seg;
int size; 
public:

segment_tree() : size(maxN), seg(vector<int>(maxN)) {}
void update(int val, int i) {
    i += size, seg[i] = val;
    for(i /= 2; i >= 1; i /= 2) seg[i] = max(seg[i*2], seg[i*2+1]);
}
int query(int l, int r) {
    l += size, r += size;
    int sm = INT_MIN;

    while(l <= r) {
        if(l % 2 == 1) sm = max(sm, seg[l++]);
        if(r % 2 == 0) sm = max(sm, seg[r--]);
        l /= 2, r /= 2;
    }
    return sm;
}
};

int lcs(vector<int>& a) {
    for(int i = 0; i < a.size(); i++) 
        a[i] += 10002;

    segment_tree seg;
    for(int i = 0 ;i < a.size(); i++) seg.update(seg.query(0, a[i]-1) + 1, a[i]);

    return seg.query(0, maxN-1);
}


int main() {

}