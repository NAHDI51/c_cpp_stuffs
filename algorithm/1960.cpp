#include <bits/stdc++.h>
using namespace std;

vector<int> dp1, dp2, dp3, dp4;

void manacher(string s) {
    vector<int> d1(s.size()), d2(s.size());
    int n = s.size();

    int l = 0, r = -1;
    int hi = 0;

    for(int i = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
        while(0 <= i-k && i+k < n && s[i+k] == s[i-k]) {
            k++;
            hi = max(2*k-1, hi);
            if(dp1[i] == -1) dp1[i] = hi;
        }
        d1[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
    }

    l = 0, r = -1, hi = 0;
    for(int i = 0; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l+r-i-1], r-i+1);
        while(0 <= i-k-1 && i+k < n && s[i-k-1] == s[i+k]) {
            k++;
            hi = max(2*k, hi);
            if(dp2[i] == -1) dp2[i] = hi;
        }
        d2[i] = k--;
        if(i+k > r) r = i+k, l = i-k-1;
    }
}

void reverse_manacher(string s) {
    vector<int> d1(s.size()), d2(s.size());
    int n = s.size();

    int l = s.size(), r= s.size()-1;
    int hi = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        int k = (i < l) ? 1 : min(d1[l+r-i], i-l+1);
        while(0 <= i-k && i+k < s.size() && s[i-k] == s[i+k]) {
            k++;
            hi = max(hi, 2*k-1);
            if(dp3[i] == -1) dp3[i] = hi;
        }
        d1[i] = k--;
        if(i-k < l) l = i-k, r = i+k;
    }

    l = s.size(), r = s.size()-1, hi = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        int k = (i < l) ? 0 : min(d2[l+r-i-1], i-l+1);
        while(0 <= i-k && i+1+k < s.size() && s[i-k] == s[i+1+k]) {
            k++;
            hi = max(hi, 2*k);
            if(dp4[i] == -1) dp4[i] = hi;
        }
        d2[i] = k--;
        if(i-k < l) l = i-k, r = i+k+1;
    }
}
long long maxProduct(string s) {
    dp1.resize(s.size(), -1), dp2.resize(s.size()-1), dp3.resize(s.size()-1), dp4.resize(s.size()-1);
    manacher(s), reverse_manacher(s);
    int hi = 0;
    for(int i = 1; i < s.size()-2; i++)
        hi = max(hi, max(dp1[i], dp2[i]) * max(dp3[s.size()-1-i], dp4[s.size()-1-i]));
}

int main() {
    string s;
    cin >> s;
    cout << maxProduct(s) << '\n';
}