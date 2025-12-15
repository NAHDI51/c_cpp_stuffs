#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vb = vector<bool>;
#define sz size
#define forn(i, n) for(int i = 0; i < n; i++)

struct trie {
vb end;
vii t;
int sz;

public: 
trie(int n) {
    sz = 1;
    t = vii(n, vi(27, -1));
    end = vb(n);
}
void ins(string s) {
    int v = 0;
    forn(i, s.sz()) {
        int c = s[i]-'a';
        if(t[v][c] == -1) t[v][c] = sz++;
        v = t[v][c];
    }
    end[v] = true;
}
bool search(string s) {
    int v = 0;
    forn(i, s.sz()) {
        int c = s[i]-'a';
        if(t[v][c] == -1) return false;
        v = t[v][c];
    }
    return end[v];
}
};

int main() {
    int n;
    cin >> n;

    vector<string> vs(n);
    int sm = 0;
    forn(i, n){
        cin >> vs[i];
        sm += vs[i].sz();
    } 
    cout << sm << '\n';
    trie t(sm+5);
    forn(i, n) t.ins(vs[i]);
    int m;
    cin >> m;
    forn(i, m)  {
        string s;
        cin >> s;
        if(t.search(s)) cout << "Found it.\n";
        else cout << "Didn't find it.\n";
    }
}