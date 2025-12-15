#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& a, int k) {
    sort(a.begin(), a.end());
    int j = 0, mx = 1, sl = 0;

    for(int i = 1; i < a.size(); i++) {
        sl += (a[i] - a[i-1]) * (i-j);
        while(sl > k) sl -= a[i] - a[j++];
        mx = max(mx, i-j+1);
    }
    return mx;
}

int main() {

}