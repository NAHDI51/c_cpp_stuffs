#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin >> t;
while(t--) {

    int n;
    cin >> n;

    vector<int> a;
    while(n--) {
        int m;
        cin >>m;
        a.push_back(m);
    }

    if(a.size() == 1) {
        cout << 1 << '\n';
        break;
    }

    int sm = 0, sz = 0;
    for(int i = 1; i < a.size(); i++) {
        if(sm + a[i-1] < a[i]) {
            sm += a[i-1]; 
            sz++;
        }
    }
    if(sm < a.back()) sz++;

    cout << sz << '\n';
}
}