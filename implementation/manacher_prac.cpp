#include <bits/stdc++.h>
using namespace std;

string manacher(string s) {
    vector<int> d1(s.size()), d2(s.size());
    int n = s.size();

    int l = 0, r = -1;
    int hi = 0, hi_indx = 0;

    for(int i = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
        while(0 <= i-k && i+k < n && s[i+k] == s[i-k]) k++;
        d1[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
        //if(hi < 2*d1[i]-1) hi = 2*d1[i]-1, hi_indx = i - d1[i] + 1;
    }

    l = 0, r = -1;
    for(int i = 0; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < n && s[i-k-1] == s[i+k]) k++;
        d2[i] = k--;
        if(i+k > r) r = i+k, l = i-k-1;
        //if(hi < 2*d2[i]) hi  =2*d2[i], hi_indx = i-d2[i];
    }
    return s.substr(hi_indx, hi);
}

string reverse_manacher(string s) {
    vector<int> d1(s.size()), d2(s.size());
    int n = s.size();

    int l = s.size(), r= s.size()-1;
    int hi = 0, hi_indx = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        int k = (i < l) ? 1 : min(d1[l+r-i], i-l+1);
        while(0 <= i-k && i+k < s.size() && s[i-k] == s[i+k]) k++;
        d1[i] = k--;
        if(i-k < l) l = i-k, r = i+k;
        if(hi < 2*d1[i]-1) hi = 2*d1[i]-1, hi_indx = i-d1[i]+1;
    }

    l = s.size(), r = s.size()-1;
    for(int i = s.size()-1; i >= 0; i--) {
        int k = (i < l) ? 0 : min(d2[l+r-i-1], i-l+1);
        while(0 <= i-k && i+1+k < s.size() && s[i-k] == s[i+1+k]) k++;
        d2[i] = k--;
        if(i-k < l) l = i-k, r = i+k+1;
        if(hi < 2*d2[i]) hi = 2*d2[i], hi_indx = i-d2[i]+1;
    }
    
    return s.substr(hi_indx, hi);
}

int main() {
    string s;
    cin >> s;
    cout << reverse_manacher(s) << '\n';
}