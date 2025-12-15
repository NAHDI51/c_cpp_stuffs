#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int p, int q, int r) {
    vector<int> lft(a.begin()+p, a.begin()+q+1);
    vector<int> ryt(a.begin()+q+1, a.begin()+r+1);

    int lnd = 0, rnd = 0;
    for(int i = p; i <= r; i++) {
        if(lnd == lft.size())      a[i] = ryt[rnd++];
        else if(rnd == ryt.size()) a[i] = lft[lnd++];
        else a[i] = (lft[lnd] <= ryt[rnd]) ? lft[lnd++] : ryt[rnd++];
    }
}
void merge_sort(vector<int>& a, int p, int r) {
    if(p == r) return;
    
    int q = (p+r) / 2;
    merge_sort(a, p, q), merge_sort(a, q+1, r);
    merge(a, p, q, r);
}

int main() {
    vector<int> a{12,4,2,4,23,52,2,3,4,5,23,45,23,4,5,3,53,45,34,53,45};
    merge_sort(a, 0, a.size()-1);
    for(auto x : a)
        cout << x << ' ';
    cout << '\n';
}