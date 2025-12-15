#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> get_num(ll x, vector<ll>& bs) {
    x--;
    vector<ll> ans;
    for(int i = 0; i < bs.size(); i++) {
        ans.push_back(x % (bs[i]));
        x /= (bs[i]);
    }
    return ans;
}

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vector<ll> bs;
    ll t = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        while(i >= 0 && s[i] == '*') i--, t += k;
        if(t != 0) bs.push_back(t+1);
        t = 0;
    }
    //for(auto x : bs) cout << x << '\t';
    //cout << '\n';

    auto nm = get_num(x, bs);
    //for(auto x : nm) cout << x << '\t';
    //cout << '\n';
    reverse(nm.begin(), nm.end());

    string ans;
    int ind = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        if(s[i] == '*') {
            while(i >= 0 && s[i] == '*') i--; i++;
            if(!nm.empty()) {
                ans += string(nm.back(), 'b'); nm.pop_back();
            }
        } else {
            ans.push_back('a');
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}