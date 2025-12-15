#include <bits/stdc++.h>
using namespace std;;

#define maxN 100000
int dp1[maxN], dp2[maxN];
void f(string s) {
    int mx_odd = 0, mx_even = 0;
    for(int i = 0, l = 0, r = -1; i < s.size(); i++) {
        int k = (i > r) ? 1 : min(dp1[l+r-i], r-i+1);
        while(0 <= i-k && i+k < s.size() && s[i+k] == s[i-k]) k++;
        dp1[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
        if(r == s.size()-1) {
            mx_odd = r-l+1;
            break;
        }
    }
    for(int i = 0, l = 0, r = -1; i < s.size(); i++) {
        int k = (i > r) ? 0 : min(dp2[l+r-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < s.size() && s[i-k-1] == s[i+k]) k++;
        dp2[i] = k--;
        if(i+k > r) l = i-k-1, r = i+k;
        if(r == s.size()-1) {
            mx_even = r-l+1;
            break;
        }
    }
    string st = s.substr(0, s.size()-max(mx_odd, mx_even));
    reverse(st.begin(), st.end());
    cout << s << st << '\n';
}

int main() {
    int c;
    string s;
    while(c != EOF) {
        c = fgetc(stdin);
        if(c == '\n') f(s), s = "";
        else s.push_back(c);
    }
    f(s);
}