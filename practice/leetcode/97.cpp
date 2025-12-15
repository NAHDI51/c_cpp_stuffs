 #include <bits/stdc++.h>
 using namespace std;

/*
class Solution {
int N, M;
int dp[101][101];

#define x 0
#define y 1

public:

bool possible(vector<string>& s, string& t, vector<int> ind) {
    if(dp[ind[x]][ind[y]] != -1) return dp[ind[x]][ind[y]];

    if(possible(s, t, {ind[x]-1, ind[y]})) {
        if(ind[y]+1 < M) 
        dp[ind[x]-1][ind[y]+1] = (s[y][ind[y]] == t[ind[x]+ind[y]-1]) ? true : false;
        if(dp[ind[x]][ind[y]] == -1 || dp[ind[x]][ind[y]] == false)
        dp[ind[x]][ind[y]] = (s[x][ind[x]-1] == t[ind[x]+ind[y]-1]) ? true : false;
    }
    else {
        if(ind[y]+1 < M) 
        dp[ind[x]-1][ind[y]+1] = false;
        if(dp[ind[x]][ind[y]] == -1 || dp[ind[x]][ind[y]] != true)
        dp[ind[x]][ind[y]] = false;
    }
    if(possible(s,t, {ind[x], ind[y]-1})) {
        if(ind[x]+1 < N)
        dp[ind[x]+1][ind[y]-1] = (s[x][ind[x]] == t[ind[x]+ind[y]-1]) ? true : false;
        if(dp[ind[x]][ind[y]] == -1 || dp[ind[x]][ind[y]] == false)
        dp[ind[x]][ind[y]] = (s[y][ind[y]-1] == t[ind[x]+ind[y]-1]) ? true : false;
    }
    else {
        if(ind[x]+1 < N)
        dp[ind[x]+1][ind[y]-1] = false;
        if(dp[ind[x]][ind[y]] == -1 || dp[ind[x]][ind[y]] != true)
        dp[ind[x]][ind[y]] = false;
    }
    return dp[ind[x]][ind[y]];
}

bool isInterleave(string s1, string s2, string s3) {
    if(s1.size() + s2.size() != s3.size()) return false;
    N = s1.size()+1, M = s2.size()+1;   
    for(int i = 0 ; i < N-1; i++) 
        for(int j = 0; j < M-1; j++)
            dp[i][j] = -1;

    bool trig = false;
    if(s1[0] == s3[0]) dp[1][0] = true, trig = true;
    if(s2[0] == s3[0]) dp[0][1] = true, trig = true;
    if(!trig) return false;
    vector<string> st = {s1, s2};
    return possible(st, s3, {N-1, M-1});
}
};
*/

class Solution {
public:
bool isInterleave(string s1, string s2, string s3) {
    if(s1.size()+s2.size() != s3.size()) return false;
    
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1));
    
    if(s1.size() > 0 && s1[0] == s3[0]) dp[1][0] = true;
    if(s2.size() > 0 && s2[0] == s3[0]) dp[0][1] = true;

    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[i].size(); j++) {
            if(dp[i-1][j]) if(j+1 < dp[i].size()) 
                dp[i-1][j+1] = (s2[j] == s3[i+j-1]) ? true : false;
            if(dp[i][j-1]) if(i+1 < dp.size())
                dp[i+1][j-1] = (s1[j] == s3[i+j-1]) ? true : false;
            
            if(dp[i-1][j] || dp[i][j-1])
                dp[i][j] = (s1[i-1] == s3[i+j-1] || s2[j-1] == s3[i+j-1]) ? true : false;
        }
    }
    return dp[dp.size()-1][dp[0].size()-1];
}
};


int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    Solution s;
    cout << s.isInterleave(s1, s2, s3) << '\n';
}