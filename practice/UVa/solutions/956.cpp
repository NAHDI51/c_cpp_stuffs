#include <bits/stdc++.h>
using namespace std;

int mx = 0;
void backtrack(vector<int>& v, int one, int two, int el) {
    if(el == v.size()) return;
    if(one == two) mx = max(mx, one);
    backtrack(v, one+v[el], two, el+1), backtrack(v, one, two+v[el], el+1), backtrack(v, one, two, el+1);
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
    backtrack(v, 0, 0, 0);
    cout << mx << '\n';
}