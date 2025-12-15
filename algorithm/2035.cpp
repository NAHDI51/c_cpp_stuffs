#include <bits/stdc++.h>
using namespace std;

int sm = 0;
int sz = 0;
int mn = INT_MIN;
void back(vector<int>& a, int i, int s, int Sm) {
    if(s == sz) {
        mn = min(mn, abs(sm-Sm));
        return;
    }
    if(i == sz*2) return;
    back(a, i+1, s+1, Sm+a[i]);
    back(a, i+1, s, Sm);
}

int minimumDifference(vector<int>& a) {
    for(auto x : a) sm += x;
    sm /= 2;
    sz = a.size()/2;
    back(a, 0, 0, 0);
    return mn;
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
    cout << minimumDifference(v) << '\n';
}