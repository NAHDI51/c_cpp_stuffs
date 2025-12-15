#include <bits/stdc++.h>
using namespace std;

void table(vector<int>& v, vector<int>& s, int n) {
    while(n > 0)
        v.push_back(s[n]), n -= s[n];
}

vector<int> extended_rod_cutting(vector<int>& v) {
    vector<int> r(v.size()+1);
    vector<int> s(v.size()+1);  
    r[0] = 0;
    for(int i = 1; i < r.size(); i++) {
        int q = INT_MIN;
        for(int j = 1; j <= i; j++) 
            if(q < v[j-1] + r[i-j]) 
                q = v[j-1] + r[i-j], s[i] = j;
        r[i] = q;
    }
    vector<int> a;
    table(a, s, s.size()-1);
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    while(n--) {
        int m;
        cin >> m;
        v.push_back(m);
    }
    for(auto x : extended_rod_cutting(v))  
        cout << x << ' ';
    cout << '\n';
}