#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& a, int p, int q, int r) {
    vector<int> lft(a.begin()+p, a.begin()+q+1);
    vector<int> ryt(a.begin()+q+1, a.begin()+r+1);

    int sm = 0;
    for(auto x : ryt) sm += ryt.end() - upper_bound(lft.begin(), lft.end(), 2*x);
    
    int lnd = 0, rnd = 0;
    for(int i = p; i <= r; i++) {
        if(lnd == lft.size())               a[i] = ryt[rnd++];
        else if(rnd == ryt.size())          a[i] = lft[lnd++];
        else a[i] = (lft[lnd] < ryt[rnd]) ? lft[lnd++] : ryt[rnd++];
    }
    return sm;
}

int merge_procedure(vector<int>& a, int p, int r) {
    if(p == r) return 0;
    else {
        int q = (p+r) / 2;
        int one = merge_procedure(a, p, q);
        int two = merge_procedure(a, q+1, r);
        int three = merge(a, p, q, r);
        return one+two+three;
    }
    return 0;
}

int reversePairs(vector<int>& a) {
    return merge_procedure(a, 0, a.size()-1)    ;
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
    cout << reversePairs(v);
}