#include <bits/stdc++.h>
using namespace std;

/*
string naive_manacher(string s) {
    vector<int> d1(s.size()), d2(s.size());

    for(int i = 0 ; i < s.size(); i++) {
        d1[i] = 0, d2[i] = 0;
        while(0 <= i - d1[i] -1 && i + d1[i] + 1 < s.size() && s[i+d1[i]+1] == s[i-d1[i]-1]) d1[i]++;
        while(0 <= i - d2[i] -1 && i + d2[i] < s.size() && s[i+d2[i]-1] == s[i+d2[i]]) d2[i]++;
    }
    int mx = 0, ind;
    bool even;
    for(int i = 0; i < d1.size(); i++) {
        if(d1[i] * 2 + 1 > mx) mx = d1[i] * 2 + 1, ind = i - d1[i];
        if(d2[i] * 2 > mx) mx = d2[i] * 2, ind = i - d2[i] + 1;
        cout << d1[i] << '\t' << d2[i] << '\n';
    }
    cout << '\n';
    cout << "Reached here. " << mx << "\n";
    return s.substr(ind, mx);
}
*/

//Almost same
string naive_manacher(string s) {
    vector<int> d1(s.size()) , d2(s.size());
    for(int i = 0; i < s.size(); i++) {
        d1[i] = 1, d2[i] = 0;
        while(0 <= i-d1[i] && i+d1[i] < s.size() && s[i-d1[i]] == s[i+d1[i]]) d1[i]++;
        while(0 <= i-d2[i]-1 && i+d2[i] < s.size() && s[i-d2[i]-1] == s[i+d2[i]]) d2[i]++;
    }
    int mx = 0, ind;
    for(int i = 0; i < d1.size(); i++) {
        if(mx < d1[i] * 2 - 1) mx = d1[i] * 2 - 1, ind = i - d1[i] + 1;
        if(mx < d2[i] * 2) mx = d2[i] * 2, ind = i - d2[i];
    }
    return s.substr(ind, mx);
}

int main() {
    string s;
    cin >> s;
    cout << naive_manacher(s) << '\n';
}