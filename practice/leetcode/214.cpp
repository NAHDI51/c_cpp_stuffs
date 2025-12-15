#include <bits/stdc++.h>
using namespace std;

string shortestPalindrome(string s) {
    vector<int> d1(s.size()) , d2(s.size());
    int l = 0, r = -1;
    for(int i = 0; i < s.size(); i++) {
        int k = (r < i) ? 1 : min(d1[l+r-i], r-i+1);
        while(0 <= i-k && i+k < s.size() && s[i-k] == s[i+k]) k++;
        d1[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
    }
    l = 0, r = -1;
    for(int i = 0; i < s.size(); i++) {
        int k = (r < i) ? 0 : min(d2[l+r-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < s.size() && s[i-k-1] == s[i+k]) k++;
        d2[i] = k--;
        if(i+k > r) r = i+k, l = i-k-1;
    }
    int mx = 0;
    for(int i = 0; i < s.size(); i++) {
        if(i-d1[i]+1 == 0) mx = max(mx, 2*d1[i]-1);
        if(i-d2[i] == 0) mx = max(mx, 2*d2[i]);
    }
    string t = s.substr(mx);
    reverse(t.begin(), t.end());
    return t + s;
}

int main() {
    string s;
    cin >> s;
    cout << shortestPalindrome(s)  << '\n';
}