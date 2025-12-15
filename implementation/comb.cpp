#include <bits/stdc++.h>
using namespace std;

int times = 0;

void print(string s, int sz) {
    for(int i = 0; i < sz; i++) cout << s[i];
    cout << '\n';
    times++;
}

void go(string& s, string& t) {
    if(s.size() == t.size()) {
        print(s, s.size());
        return;
    }
    s.push_back(t[s.size()]);
    go(s, t);
    s.pop_back();

    if(isalpha(t[s.size()])) {
        s.push_back(t[s.size()]-32);
        go(s, t);
        s.pop_back();
    }
    return;
}

int main() {
    string t = "m5zfxmz9tt";
    string s;
    go(s, t);
    cout << "Total entries: " << times << '\n';
}