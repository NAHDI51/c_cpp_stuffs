#include <bits/stdc++.h>
using namespace std;

int bits[200002][32];
int main() {
//Let bit[i][j] be the number of bit j till bit i.
memset(bits, 0, sizeof(bits));

for(int i = 1; i < 200002; i++) {
    for(int k = 0; k < 32; k++) {
        if(i & (1<<k)) bits[i][k]++;
        bits[i][k] += bits[i-1][k];
    }
}

int t;
cin >> t;
while(t--) {
    int l, r;
    cin >> l >> r;
    int mx = 0;
    for(int i = 0; i < 32; i++) mx = max(mx, bits[r][i]-bits[l-1][i]);
    cout << r-l+1-mx << '\n';
}
}
