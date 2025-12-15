#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& a, int key) {
    int k = 0, n = a.size();
    for(int b = n/2; b >= 1; b /= 2) 
        while(k+b < n && a[k+b] <= key) k += b;
    return k;
}

int upper_bound(vector<int>& a, int key) {
    return f(a, key) + 1;
}
int lower_bound(vector<int>& a, int key) {
    return f(a, key-1) + 1;
}

int main() {
    vector<int> a{1,2,3,4,5, 5, 5, 6, 7,8,9,10};
    cout << a[upper_bound(a, 5)] << '\n';
    cout << a[lower_bound(a, 5)] << '\n';
}
//Lower bound = binary_search(a, key-1) + 1.
//Upper bound = binary_search(a, key) + 1.