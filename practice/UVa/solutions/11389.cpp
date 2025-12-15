#include <bits/stdc++.h>
using namespace std;

int main() {
while(1) {
    long n, d, r;
    cin >> n >> d >> r;
    if(n == 0 && d == 0 && r == 0) break;

    vector<long> st(n), ed(n);

    for(int i = 0; i < n; i++) cin >> st[i];
    for(int i = 0; i < n; i++) cin >> ed[i];

    sort(st.begin(), st.end());
    sort(ed.begin(), ed.end(), greater<int>{});

    long sm = 0;
    for(int i = 0; i < st.size(); i++) 
        if(st[i]+ed[i] > d) sm += (st[i]+ed[i]-d);

    cout << sm*r << '\n';
}
}