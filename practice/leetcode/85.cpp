#include <bits/stdc++.h>
using namespace std;

int histo(vector<int>& a) {
    int mx = 0;
    vector<int> m;

    for(int i = 0; i < a.size() ;i++ ) {
        while(!m.empty() && a[m.back()] > a[i]) {
            if(m.size() == 1) mx = max(mx, a[m.back()] * i);
            else mx = max(mx, a[m.back()] * (i-m[m.size()-2]-1));
            m.pop_back();
        }
        m.push_back(i);
    }
    while(!m.empty()) {
        if(m.size() == 1) mx = max(mx, (int) (a[m.back()] * (a.size())));
        else mx = max(mx, a[m.back()] * (int)((a.size()-m[m.size()-2]-1)));
        m.pop_back();
    }
    
    return mx;
}

int maximalRectangle(vector<vector<char>>& m) {
    vector<vector<int>> a(m.size(), (vector<int>(m[0].size())));
    cout << '\n';
    for(int j = 0; j < m[0].size(); j++) {
        a[0][j] = m[0][j]-48;
        for(int i = 1; i < m.size(); i++) 
            a[i][j] = (m[i][j] == '0') ? 0 : a[i-1][j]+1;
    }
    int mx = 0;
    for(int i = 0; i < m.size(); i++) mx = max(mx, histo(a[i]));
    return mx;
}

int main() {
    vector<vector<char>> a;
    int n, m;
    cin >> n >> m;
    while(n--) {
        int s = m;
        vector<char> g;
        while(s--) {
            char p;
            cin >> p;
            g.push_back(p);
        }
        a.push_back(g);
    }
    cout << maximalRectangle(a) << '\n'; 
} 