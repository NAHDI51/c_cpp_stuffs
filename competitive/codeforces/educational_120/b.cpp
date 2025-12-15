#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using vb = vector<bool>;
using ii = pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;

int main() {
int t;
cin >> t;
while(t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> hsh;
    for(int i = 0; i < n; i++) hsh[a[i]] = i;

    set<int> st0, st1;
    for(int i = 0 ;i < n; i++) {
        char s;
        cin >> s;
        if(s == '0') st0.insert(a[i]);
        else st1.insert(a[i]);
    }

    vi ans(n);
    int c = 1;
    for(auto i = st0.begin() ; i != st0.end(); i++)
        ans[hsh[*i]] = c++;
    for(auto i = st1.begin(); i != st1.end(); i++)
        ans[hsh[*i]] = c++;
    
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
}
}