#include <bits/stdc++.h>
using namespace std;

//BEST COMPLEXITY O(N)
/*
int uniqueLetterString(string s) {
    vector<vector<int>> tab(91);
    for(int i = 0; i < tab.size(); i++) tab[i].push_back(-1);
    vector<int> dp(s.size());
    dp[0] = 1, tab[s[0]].push_back(0);

    for(int i = 1; i < dp.size(); i++) {
        if(tab[s[i]].size() == 1) dp[i] = dp[i-1] + (i+1); 
        else dp[i] = dp[i-1] + (i - tab[s[i]].back()) - (tab[s[i]].back() - tab[s[i]][tab[s[i]].size()-2]); 
        tab[s[i]].push_back(i);
    }
    int cnt = 0;
    for(auto x : dp) cnt += x;
    return cnt;
}
*/

//SPACE OPTIMIZATION (O(N) time & space)
int uniqueLetterString(string s) {
    vector<pair<int, int>> tab(91);
    for(int i = 0; i < tab.size(); i++) tab[i] = {-1, -1};
    vector<int> dp(s.size());
    dp[0] = 1, tab[s[0]] = {tab[s[0]].second, 0};

    for(int i = 1; i < dp.size(); i++) {
        if(tab[s[i]].second == -1) dp[i] = dp[i-1] + (i+1);
        else dp[i] = dp[i-1] + (i- tab[s[i]].second) - (tab[s[i]].second - tab[s[i]].first);
        tab[s[i]] = {tab[s[i]].second, i};
    }
    int cnt = 0;
    for(auto x : dp) cnt += x;
    return cnt;
}

int main() {
    string s;
    cin >> s;
    cout << uniqueLetterString(s) << '\n';
}