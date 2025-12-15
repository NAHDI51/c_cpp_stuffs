#include <bits/stdc++.h>
using namespace std;

//Abhorrently optimized (TLE)
/*
bool canCross(vector<int>& a) {
    if(a[1] != 1) return false;
    vector<vector<int>> dp(a.size());
    dp[1].push_back(1);

    for(int i = 1; i < a.size(); i++) {
        for(int j = 0; j < i; j++) {
            for(int k = 0; k < dp[j].size(); k++) {
                if((a[j] + dp[j][k]) == a[i])
                    dp[i].push_back(dp[j][k]);
                else if((a[j]+dp[j][k]+1) == a[i])
                    dp[i].push_back(dp[j][k]+1);
                else if((a[j]+dp[j][k]-1) == a[i])
                    dp[i].push_back(dp[j][k]-1);
            }
        }
        if(dp[i].empty()) return false;
    }
    return true;
}
*/

/* N^2 [Almost], Accepted
bool canCross(vector<int>& a) {
    if(a[1] != 1) return false;
    vector<unordered_map<int, bool>> dp(a.size());
    dp[1][1] = true;

    for(int i = 2; i < a.size(); i++) {
        for(int j = 1; j < i; j++) {
            if(dp[j].find(a[i]-a[j]) != dp[j].end()) dp[i][a[i]-a[j]] = true;
            else if(dp[j].find(a[i]-a[j]+1) != dp[j].end()) dp[i][a[i]-a[j]] = true;
            else if(dp[j].find(a[i]-a[j]-1) != dp[j].end()) dp[i][a[i]-a[j]] = true;
        }
    }
    return !dp[a.size()-1].empty();
}
*/

//N^2 [Best]
class Solution {
public:
    
    unordered_map<int,int> mp;
    
    int dp[2005][2005];
    vector<int> v;
    
    int ans(int pos,int lst)
    {
        
        if(pos==v.size()-1)
        {
            return 1;
        }
        if(dp[pos][lst]!=-1)
        {
            return dp[pos][lst];
        }
        
        int an=0;
        if((mp.find(v[pos]+lst)!=mp.end())&&(lst!=0))
        {
            an=max(an,ans(mp[v[pos]+lst],lst));
        }
        if((mp.find(v[pos]+lst-1)!=mp.end())&&(lst-1 !=0))
        {
            an=max(an,ans(mp[v[pos]+lst-1],lst-1));
        }
        if(mp.find(v[pos]+lst+1)!=mp.end())
        {
            an=max(an,ans(mp[v[pos]+lst+1],lst+1));
        }
        return (dp[pos][lst]=an);
    }
    
    bool canCross(vector<int>& stones) {
        v=stones;
        for(int i=0;i<v.size();i++)
        {
            mp[v[i]]=i;
        }
        memset(dp,-1,sizeof(dp));
        if(v[1]!=1)
        {
            return false;
        }
        return ans(1,1);
    }
};

int main() {
    vector<int> a;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << canCross(a) << '\n';
}