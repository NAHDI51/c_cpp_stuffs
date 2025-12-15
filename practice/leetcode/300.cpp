#include <bits/stdc++.h>
using namespace std;

/*
int lengthOfLIS(vector<int>& a) {
    vector<int> lis(a.size(), 1);
    int mx = 0;
    for(int i = 1; i < a.size(); i++) {
        for(int j = 0; j < i; j++)
            if(a[j] < a[i]) lis[i] = max(lis[j]+1, lis[i]);
        mx = max(lis[i], mx);
    }
    return mx;
}
*/
class segment_tree {
int seg[5005];
int size;

public:
segment_tree() : size{2500} {
    for(int i = 0; i < 5005; i++) seg[i] = 0;
}
void update(int i, int val) {
    i += size;
    seg[i] = val;
    for(i /= 2; i >= 1; i /= 2)
        seg[i] = max(seg[i*2], seg[i*2+1]);
}
int query(int r)

};

int lengthOfLIS(vector<int>& a) {

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
    cout << lengthOfLIS(v) << '\n';
}