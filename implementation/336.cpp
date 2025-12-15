#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

int max(vector<string>& w) {
    int mx = 0;
    for(int i = 0; i < w.size(); i++)
        mx = max(mx, (int) w[i].size());
    return mx;
}

bool is_palindrome(string s) {
    for(int i = 0; i < s.size()/2; i++) {
        if(s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& w) {
    vector<int> p(max(w)+1);
    ll A = 9973, B = (int) 1e9+9;
    //Power
    p[0] = 1;
    for(int i = 1; i < p.size(); i++) p[i] = (p[i-1] * A) % B;

    //Hashing
    vector<vector<int>> h(w.size());
    for(int i = 0; i < h.size(); i++) {
        h[i].resize(w[i].size()+1), h[i][0] = 1;
        for(int j = 1; j < h[i].size(); j++) h[i][j] = ((h[i][j-1] * A) + w[i][j-1]) % B;
    }

    auto hash = [&] (int i, int l, int r) -> ll {
        return (h[i][r+1] - (h[i][l] * p[r-l+1]) % B + B) % B;
    };

    //Reverse hashing
    auto rw = w;
    vector<vector<int>> rh(w.size());
    for(int i = 0; i < w.size(); i++) reverse(rw[i].begin(), rw[i].end());

    for(int i = 0; i < rh.size(); i++) {
        rh[i].resize(rw[i].size()+1), rh[i][0] = 1;
        for(int j = 1; j < rh[i].size(); j++) rh[i][j] = ((rh[i][j-1] * A) + rw[i][j-1]) % B;
    }

    auto rhash = [&] (int i, int l, int r) -> ll {
        return (rh[i][r+1] - (rh[i][l] * p[r-l+1]) % B + B) % B;
    };

    vector<vector<int>> ans;
    //Procedure
    for(int i = 0; i < w.size()-1; i++) {
        for(int j = i+1; j < w.size(); j++) {
            if(w[i].size() == w[j].size()) {
                if(hash(i, 0, w[i].size()-1) == rhash(j, 0, w[j].size()-1)) ans.push_back({i, j}), ans.push_back({j, i});
            } 
            else if(w[i].empty() || w[j].empty()) {
                if(w[i].size() == w[j].size()) 
                    ans.push_back({i, j}), ans.push_back({j, i});
                else 
                    if(is_palindrome(w[i]+w[j])) 
                        ans.push_back({i, j}), ans.push_back({j, i});
            }
            else {
                int smol = (w[i].size() > w[j].size()) ? j : i;
                int big = (smol == i) ? j : i;

                if(hash(smol, 0, w[smol].size()-1) == rhash(big, 0, w[smol].size()-1))
                    if(is_palindrome(w[smol]+w[big])) ans.push_back({smol, big});
                if(hash(smol, 0, w[smol].size()-1) == rhash(big, w[big].size()-w[smol].size(), w[big].size()-1))
                    if(is_palindrome(w[big]+w[smol])) ans.push_back({big, smol});
            }
        }
    }
    return ans;
}

int main() {
    vector<string> s;
    int n;
    cin >> n;
    while(n--) {
        string st;
        cin >> st;
        s.push_back(st);
    }
    for(auto x : palindromePairs(s))
        cout << x[0] << '\t' << x[1] << '\n';
}