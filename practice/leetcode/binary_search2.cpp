#include <bits/stdc++.h>
using namespace std;

void f(vector<int>& a, int key) {
    int k = 0, n = a.size();
    for(int b = n/2; b >= 1; b /= 2) {
        while(k+b < n && a[k+b] <= key) k += b;
    }
    cout << a[k] << '\n';
}

int main() {
    vector<int> a{1,2,3,4,5,6,7,8,9,10};
    f(a, 5);
}