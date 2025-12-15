#include <bits/stdc++.h>
using namespace std;

int bin_search(vector<int>& a, int k) {
    int t = 0;
    for(int i = a.size()/2; i >= 1; i /= 2) {
        while(t+i < a.size() && a[t+i] <= k) t += i;
    }
    return t;
}

int lb(vector<int>& a, int k) {
    return bin_search(a, k-1)+1;
}
int ub(vector<int>& a, int k) {
    return bin_search(a, k)+1;
}

int main() {
    vector<int> a = {1,2,3,4,5, 5, 6,7,8,9,10};
    int k = 5;
    cout << a[bin_search(a, k)+1] << '\n';
}