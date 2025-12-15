#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int maxProduct(vector<int>& a) {
    ll ans = INT_MIN, slide = INT_MIN, total = 1, neg_slide = INT_MIN;
    bool activate = false, sl = false;
    for(int i = 0 ; i < a.size(); i++) {
        if(a[i] == 0) {
            activate = sl = false;
            slide = neg_slide = INT_MIN;
            total = 1;
            ans = max(ans, (ll)0);
            continue;
        }
        total *= a[i];
        if(activate) neg_slide *= a[i];
        if(sl) slide *= a[i];

        auto mx = max({slide, total, neg_slide});
        ans = max(ans, mx);

        if(a[i] < 0) {
            sl ^= true;
            if(sl == true) slide = 1;
            else slide = INT_MIN;
            if(!activate) activate = true, neg_slide = 1;
        }
    }
    return (int) ans;
}

int main() {
    vector<int> a;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << maxProduct(a) << '\n';
}