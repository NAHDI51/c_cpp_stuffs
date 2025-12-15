#include <bits/stdc++.h>
using namespace std;

vector<int> rod_cutting(vector<int> v) {
    vector<int> r(v.size()+1);
    r[0] = 0;   //Base value;
    for(int i = 1; i < r.size(); i++) {
        int q = INT_MIN;
        for(int j = 1; j <= i; j++) 
            q = max(q, v[j-1] + r[i-j]);
        r[i] = q;
    }
    return r;
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
    for(auto x : rod_cutting(v))
        cout << x << ' ';
    cout << '\n';
}