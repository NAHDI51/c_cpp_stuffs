#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& a, int l, int r) {
    if(l == r) return a[l];
    while(l < r) {
        if(a[l])
    }
}

int findMin(vector<int>& a) {
    if(a.front() < a.back()) return a.front();  //The array is sorted.
    int l = 0, r = a.size()-1;
    int pos;
    while(l <= r) {
        int m = (l+r) / 2;
        if(a[m] >= a[l]) l = m+1, pos = m;
        else r = m-1;
    }
    return pos;
}

int main() {

}