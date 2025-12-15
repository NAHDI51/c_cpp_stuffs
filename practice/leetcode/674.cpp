#include <bits/stdc++.h>
using namespace std;

int findLengthOfLCIS(vector<int>& a) {
    int mx = 1, rn = 1;
    for(int i = 1; i < a.size(); i++) {
        (a[i] > a[i-1]) ? rn++ : rn = 1;
        mx = max(mx, rn);
    }
    return mx;
}

int main() {

}