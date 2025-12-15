#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin >> t;
while(t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < a.size(); i++) cin >> a[i];

    sort(a.begin(), a.end());
    int sm = 0;
    for(int i = 0; i < (n - (2*k)); i++) sm += a[i];

    for(int i = 0; n-k+i != n; i++) 
        sm += (a[n-(2*k)+i] == a[n-k+i]) ? 1 : 0;
    cout << sm << '\n';
}
}