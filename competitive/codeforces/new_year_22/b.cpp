#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss =vector<vs>;
using vb = vector<bool>;
using ii = pair<int ,int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using ll = long long;

ll mx = 10000000000;

void solve(vector<vector<long long>>& a) {
    ll l = a[0][2], r = a[0][2];
    ll complete = a[0][2];
    pair<ll, ll> rng = {a[0][0], a[0][1]};
    cout << complete << '\n';

    for(int i = 1; i < a.size(); i++) {
        if(a[i][0] == rng.first && a[i][1] == rng.second) {
            l = min(l, a[i][2]), r = min(r, a[i][2]);
            complete = min(complete, a[i][2]);
        } else if(a[i][0] < rng.first && a[i][1] == rng.second) {
            rng = {a[i][0], a[i][1]};
            r = min({a[i][2], r, complete});
            l = a[i][2];
            complete = a[i][2];
        } else if(a[i][0] == rng.first && a[i][1] > rng.second) {
            rng = {a[i][0], a[i][1]};
            l = min({a[i][2], l, complete});
            r = a[i][2];
            complete = a[i][2];
        } else if(a[i][0] < rng.first && a[i][1] > rng.second) {
            rng = {a[i][0], a[i][1]};
            r = a[i][2], l = a[i][2];
            complete = a[i][2];
        } else if(a[i][0] < rng.first && a[i][1] < rng.second) {
            rng = {a[i][0], rng.second};
            l = a[i][2];
            r = min(r, complete);
            complete = mx;
        } else if(a[i][0] > rng.first && a[i][1] > rng.second) {
            rng = {rng.first, a[i][1]};
            r = a[i][2];
            l = min(l, complete);
            complete = mx;
        } else if(a[i][0] == rng.first && a[i][1] < rng.second) {
            l = min({l, a[i][2], complete});
        } else if(a[i][0] > rng.first && a[i][1] == rng.second) {
            r = min({r, a[i][2],complete});
        }
        //cout << r+l << '\t' << complete << '\n';
        cout << min(r+l, complete) << '\n';
    }
}

int main() {
int t;
cin >> t;
while(t--) {
    int n;
    cin >> n;
    vector<vector<long long>> a(n, vector<long long>(3));
    for(int i = 0; i < n ; i++) 
        for(int j = 0; j < 3; j++)
            cin>> a[i][j];
    
    solve(a);
}
}