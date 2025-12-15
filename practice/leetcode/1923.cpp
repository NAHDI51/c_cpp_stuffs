#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int longestCommonSubpath(int n, vector<vector<int>>& a) {
    if(a.size() == 1) return a.size();

    int mn = INT_MAX, mx = INT_MIN;
    for(int i = 0; i  < a.size(); i++)
        mn = min(mn, (int) a[i].size()), mx = max(mx, (int) a[i].size());

    ll A = 9973, B = (int) 1e9+9;

    vector<vector<ll>> h(a.size());
    vector<ll> p(100002);

    p[0] = 1;
    for(int i = 1; i < mx; i++) p[i] = (p[i-1] * A) % B;

    for(int i = 0 ; i < h.size(); i++) {
        h[i].resize(a[i].size()+1), h[i][0] = 1;

        for(int j = 1; j < h[i].size(); j++)
            h[i][j] = ((h[i][j-1] * A) % B + a[i][j-1]) % B;
    }
    auto hash = [&] (int i, int l, int r) -> ll {
        return (h[i][r+1] - (h[i][l] * p[r-l+1]) % B + B) % B;
    };

    int lft = 0, ryt = mn, ans;

    auto equals = [&](int i1, int i2, int j, int win) -> bool {
        for(int i = 0; i < win; i++)
            if(a[j-1][i1+i] != a[j][i2+i]) return false;
        return true;
    };

    auto exists = [&](int win) -> bool {
        unordered_map<ll, int> base;
        for(int j = 0, i = win-1; i < a[0].size(); i++, j++) base[hash(0, j, i)] = j;

        for(int x = 1; x < a.size() && !base.empty(); x++) {
            unordered_map<ll, int> temp;

            for(int j = 0, i = win-1; i < a[x].size(); i++, j++)
                if(base[hash(x, j, i)] != 0 && equals(base[hash(x, j, i)], j, x, win)) temp[hash(x, j, i)] = j;
            
            base = temp;
        }
        return !base.empty();
    };

    while(lft <= ryt) {
        if(ryt == 0) return 0;
        int m = (lft + ryt + 1) / 2;
        //cout << m << '\n';

        if(exists(m)) ans = m, lft = m+1;
        else ryt = m-1;
    }
    //cout << '\n';
    return ans;
}

int main() {
    vector<vector<int>> vv;
    int n, k;
    cin >> k >> n;
    while(n--) {
        int m;
        cin >> m;
        vector<int> v;
        while(m--) {
            int p;
            cin >> p;
            v.push_back(p);
        }
        vv.push_back(v);
    }
    cout << longestCommonSubpath(k, vv) << '\n';
}