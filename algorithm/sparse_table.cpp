#include <bits/stdc++.h>
using namespace std;

void f(vector<int>& a) {
    int sparse[10001][20];
    int log[10001];

    cout << "Base array: ";
    for(auto x : a) cout << x << "  ";
    cout << "\n\n";

    for(int j = 0; j < a.size(); j++) sparse[j][0] = a[j];

    for(int j = 1; j < 20; j++) 
        for(int i = 0; i + (1 << j) < a.size(); i++)
            sparse[i][j] = min(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
    
    log[1] = 0;
    for(int i = 2; i <= 10000; i++) log[i] = log[i/2]+1;
    auto query = [&sparse, &log] (int l, int r) -> int {
        int lg = log[r-l+1];
        return min(sparse[l][lg], sparse[r - (1 << lg) + 1][lg]);
    };

    bool dec = true;
    while(dec) {
        cout << "Enter your range: ";
        int a, b;
        cin >> a >> b;
        if(a < 0 || b < 0) break;
        cout << "Range [" << a+1 << ", " << b+1 << ']' << " : " << query(a, b) << '\n';
    }
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    f(a);
}