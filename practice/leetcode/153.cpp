#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& a) {
    int l = 0, r = a.size()-1;
    int pos = 0;
    while(l < r) {
        if(a[l] <= a[r]) return a[l];
        int m = (l+r)/2;
        if(a[l] < a[m]) l = m+1;
        else pos = m, r = m-1;
        //cout << a[m] << '\t';
    }
    return a[pos];
}

int main() {
    vector<int> a;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << findMin(a) << '\n';
}