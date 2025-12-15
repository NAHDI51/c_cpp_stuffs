#include <bits/stdc++.h>
using namespace std;

string pushDominoes(string a) {
    string ans;
    ans.resize(a.size());
    int j = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == 'L') {
            if(a[j] == 'R') {
                int l = j;
                int k = (j+i+1) / 2;
                while(j != k) ans[j++] = 'R';
                if((i-l+1) % 2) ans[j++] = '.';
                while(j != i+1) ans[j++] = 'L';
            } else {
                while(j != i+1) ans[j++] = 'L';
            }
        } else if(a[i] == 'R') {
            if(a[j] == 'R') {
                while(j != i) ans[j++] = 'R'; }
            else {
                while(j != i) ans[j++] = '.'; }
        }
    }
    bool trig = (a[j] == 'R') ? true : false;
    while(j != a.size()) ans[j++] = (trig) ? 'R' : '.';
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << pushDominoes(s) << '\n';
}