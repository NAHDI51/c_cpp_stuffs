#include <bits/stdc++.h>
using namespace std;

//Practice manacher like fuck

/*
string manacher(string s) {
    vector<int> d1(s.size()), d2(s.size());
    int l = 0, r = -1;

    for(int i = 0 ;i < s.size(); i++) {
        int k = (r > i) ? 1 : min(d1[l+r-i], r-i+1);
        while(0 <= i - k && i+k < s.size() && s[i-k] == s[i+k]) k++;
        d1[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
    }
    l = 0, r = -1;
    for(int i = 0; i < s.size(); i++) {
        int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < s.size() && s[i-k-1] == s[i+k]) k++;
        d2[i] = k--;
        if(i+k > r) r = i+k, l = i-k-1;
    }
    int hi = 0, hi_indx = 0;
    for(int i = 0; i < s.size(); i++) {
        if(hi < d1[i]*2-1) hi = d1[i]*2-1, hi_indx = i-d1[i]+1;
        if(hi < d2[i]*2) hi = d2[i]*2, hi_indx = i-d2[i];
    }
    return s.substr(hi_indx, hi);
}
*/

/*
string manacher(string s) {
    vector<int> d1(s.size()), d2(s.size());

    int l = 0, r = -1;
    for(int i = 0; i < s.size(); i++) {
        int k  = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
        while(0 <= i-k && i+k < s.size() && s[i-k] == s[i+k]) k++;
        d1[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
    }
    l = 0, r = -1;
    for(int i = 0; i < s.size(); i++) {
        int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < s.size() && s[i-k-1] == s[i+k]) k++;
        d2[i] = k--;
        if(i+k > r) r = i+k, l = i-k-1;
    }
    int hi = 0, hi_indx = 0;
    for(int i = 0; i < s.size(); i++) {
        if(hi < 2*d1[i]-1) hi = 2*d1[i]-1, hi_indx = i-d1[i]+1;
        if(hi < 2*d2[i]) hi = 2*d2[i], hi_indx = i-d2[i];
    }
    return s.substr(hi_indx, hi);
}
*/

/*
string manacher(string s) {
    vector<int> d1(s.size()), d2(s.size());
    int l = 0, r = -1;

    for(int i = 0; i < s.size(); i++) {
        int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
        while(0 <= i-k && i+k < s.size() && s[i+k] == s[i-k]) k++;
        d1[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
    }
    int l = 0, r = -1;
    for(int i = 0 ; i< s.size(); i++) {
        int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < s.size() && s[i-k-1] == s[i+k]) k++;
        d2[i] = k--;
        if(i+k > r) r = i+k, l = i-k-1;
    }
    int hi = 0, hi_indx = 0;
    for(int i = 0; i < s.size(); i++){
        if(hi < d1[i]*2-1) hi = d1[i]*2-1, hi_indx = i-d1[i]+1;
        if(hi < d2[i]*2) hi = d2[i]*2, hi_indx = i-d2[i];
    }
    return s.substr(hi_indx, hi);
}
*/

/*
string manacher(string s) {
    vector<int> d1(s.size()), d2(s.size());
    int l = 0, r = -1;

    for(int i = 0; i < s.size(); i++) {
        int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
        while(0 <= i-k && i+k < s.size() && s[i-k] == s[i+k]) k++;
        d1[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
    }
    l = 0, r = -1;
    for(int i = 0; i < s.size(); i++) {
        int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < s.size() && s[i-k-1] == s[i+k]) k++;
        d2[i] = k--;
        if(i+k > r) r = i+k, l = i-k-1;
    }
    int hi = 0, hi_indx = 0;
    for(int i = 0; i < s.size(); i++) {
        if(hi < d1[i] * 2 - 1) hi = d1[i]*2-1, hi_indx = i-d1[i]+1;
        if(hi < d2[i] * 2) hi = d2[i]*2, hi_indx = i-d2[i];
    }
    return s.substr(hi_indx, hi);
}
*/

/*
string manacher(string s) {
    vector<int> d1(s.size()), d2(s.size());

    int l = 0, r = -1;
    for(int i = 0 ; i < s.size(); i++) {
        int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
        while(0 <= i-k && i+k < s.size() && s[i+k] == s[i-k]) k++;
        d1[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
    }
    l = 0, r = -1;
    for(int i = 0; i < s.size(); i++) {
        int k = (i > r) ? 0 : min(d2[l+r-i+1] , r-i+1);
        while(0 <= i-k-1 && i+k < s.size() && s[i-k-1] == s[i+k]) k++;
        d2[i] = k--;
        if(i+k > r) r = i+k, l = i-k-1;
    }
    int hi = 1, hi_indx = 0;
    for(int i = 0; i < s.size(); i++ {
        if(hi < 2*d1[i]-1) hi = 2*d1[i]-1, hi_indx = i-d1[i]+1;
        if(hi < 2*d2[i]) hi = 2*d2[i], hi_indx = i-d2[i];
    }
    return s.substr(hi_indx, hi);
}
*/

/*
string manacher(string s) {
    vector<int> d1(s.size()), d2(s.size());
    int l = 0, r= -1;
    for(int i = 0; i < s.size(); i++) {
        int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
        while(0 <= i-k && i+k < s.size() && s[i-k] == s[i+k]) k++;
        d1[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
    }
    l = 0, r = -1;
    for(int i = 0;  i < s.size(); i++) {
        int k = (i>r) ? 0 : min(d2[l+r-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < s.size() && s[i-k-1] == s[i+k]) k++;
        d2[i] = k--;
        if(i+k > r) r = i+k, l = i-k-1;
    }
    int hi = 0, hi_indx = 0;
    for(int i = 0 ;i < s.size(); i++) {
        if(hi < 2*d1[i]-1) hi = 2*d1[i]-1, hi_indx = i-d1[i]+1;
        if(hi < 2*d2[i]) hi = 2*d2[i], hi_indx = i-d2[i];
    }k = 0;urn s.substr(hi_indx, hi);
}
*/

/*
string manacher(string s) {
    vector<int> d1(s.size()), d2(s.size());
    int l = 0, r = -1;

    for(int i = 0 ; i < s.size(); i++) {
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
    int hi = 0, hi_indx = 0;
    for(int i = 0; i < s.size(); i++) {
        if(hi < d1[i]*2-1) hi = d1[i]*2-1, hi_indx = i-d1[i]+1;
        if(hi < d2[i]*2) hi = d2[i]*2, hi_indx = i-d2[i];
    }
    return s.substr(hi_indx, hi);
}
*/
/*
string manacher(string s) 
    int l = 0, r = -1;
    vector<int> d1(s.size()), d2(s.size());

    for(int i=0; i < s.size(); i++) {
        int k = (i>r) ? 1 : min(d1[l+r-i], r-i+1);
        while(0 <= i-k && i+k < s.size() && s[i-k] == s[i+k]) k++;
        d1[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
    }
    l = 0, r = -1;
    for(int i = 0 ; i < s.size(); i++) {
        int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < s.size() && s[i-k-1] == s[i+k]) k++;
        d2[i] = k--;
        if(i+k > r) r = i+k, l = i-k-1;
    }
    int hi = 0, hi_indx = 0;
    for(int i =  0; i < s.size(); i++) {
        if(hi < d1[i]*2-1) hi = d1[i]*2-1, hi_indx = i-d1[i]+1;
        if(hi < d2[i]*2) hi = d2[i]*2, hi_indx = i-d2[i];
    }
    return s.substr(hi_indx, hi);
}
*/

string manacher(string s) {
    int l = 0, r= -1;
    vector<int> d1(s.size()), d2(s.size());

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
    int hi = 1, hi_indx = 0;
    for(int i = 0; i < s.size(); i++) {
        if(hi < d1[i]*2-1) hi = d1[i]*2-1, hi_indx = i-d1[i]+1;
        if(hi < d2[i]*2) hi = d2[i]*2, hi_indx = i-d2[i];
    }
    return s.substr(hi_indx, hi);
}

int main() {
    string s;
    cin>> s;
    cout << manacher(s) << '\n';
}