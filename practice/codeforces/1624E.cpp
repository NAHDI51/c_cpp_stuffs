#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0 ;i < n; i++)
#define fore(i, a, b) for(int i = a; i <= b; i++)
#define rof(i, n) for(int i = n; i >= 0; i--)
#define rofe(i, a, b) for(int i = a; i >= b; i--)

#define maxN 1001

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> vs(n);
    string s;
    
    forn(i, n) cin >> vs[i];
    cin >> s;
    map<string, vector<int>> mp;

    forn(i, n) {
        forn(j, m-1) {
            mp[vs[i].substr(j, 2)] = {j+1, j+2, i+1};
        }
        forn(j, m-2) {
            mp[vs[i].substr(j, 3)] = {j+1, j+3, i+1};
        }
    }

    int dp[maxN];
    int sol[maxN];
    memset(dp, 0, sizeof(dp));
    memset(sol, 0, sizeof(sol));

    if(mp.find(s.substr(0, 2)) != mp.end()) {
        dp[1] = true;
        sol[1] = -1;
    }
    if(mp.find(s.substr(0, 3)) != mp.end()) {
        dp[2] = true;
        sol[2] = -1;
    }
    for(int i = 3; i < m; i++) {
        if(dp[i-2] && (mp.find(s.substr(i-1, 2)) != mp.end())) {
            dp[i] = true, sol[i] = i-2;
        } else if(dp[i-3] && (mp.find(s.substr(i-2, 3)) != mp.end())) {
            dp[i] = true, sol[i] = i-3;
        }
    }

    if(!dp[m-1]) {
        cout << "-1" << '\n';
        return;
    }

    int ind = m-1;
    stack<vector<int>> st;
    while(ind != -1) {
        string word;
        if(ind-sol[ind] == 2) {
            word = s.substr(ind-1, 2);
        } else if(ind-sol[ind] == 3) {
            word = s.substr(ind-2, 3);
        }
        st.push(mp[word]);
        ind = sol[ind];
    }
    cout << st.size() << '\n';
    while(!st.empty()) {
        for(auto x : st.top()) cout << x << ' ';
        cout << '\n';
        st.pop();
    }


    return;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}