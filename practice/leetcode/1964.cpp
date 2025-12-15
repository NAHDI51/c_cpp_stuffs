#include <bits/stdc++.h>
using namespace std;

class segment_max {
vector<int> seg;
int size;
public:
segment_max(int sz) {
    size = sz+1, seg.resize(size*2+10);
}
void update(int i, int val) {
    i += size;
    seg[i] = val;
    for(i /= 2; i >= 1; i /= 2)
        seg[i] = max(seg[i*2], seg[i*2+1]);
}
int query(int l, int r) {
    l += size, r += size;
    int sm = 0;
    while(l <= r) {
        if(l % 2 == 1) sm = max(sm, seg[l++]);
        if(r % 2 == 0) sm = max(sm, seg[r--]);
        l /= 2, r /= 2;
    }
    return sm;
}
};

vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
    vector<int> ans;
    int mx = 0;
    for(auto x : obs)
        mx = max(mx, x);
    
    segment_max seg(mx);
    for(int i = 0 ; i < obs.size(); i++) {
        ans.push_back(seg.query(0, obs[i]) + 1);
        seg.update(obs[i], ans.back());
    }
    return ans;
}

int main() {
    vector<int> v;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        v.push_back(m);
    }
    for(auto x : longestObstacleCourseAtEachPosition(v))
        cout << x << ' ';
    cout << '\n';
}