#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main() {
    int t;
    cin >> t;

    while(t--) {
    ll s, a;
    cin >> a >> s;

    vector<int> ans;
    while(s) {
        int f;
        if(!a) f = 0;
        else f = a%10;
        int m = s%100;

        if(((m/10)%10) != 1 && m%10 < f) goto bad_end;
        else if(((m/10)%10) == 1 && m%10 < f) {
            ans.push_back(m-f);
            s /= 100;
        }
        else if(m%10 >= f) {
            ans.push_back((m%10)-f);
            s /= 10;
        }
        a /= 10;
    }
    int j = 0;
    while(ans[j] == 0) j++;
    for(int i = ans.size()-1; i >= j; i--) 
        cout << ans[i];
    cout << '\n';
    continue;
    
    bad_end:
    cout << -1 << '\n';
    }
}