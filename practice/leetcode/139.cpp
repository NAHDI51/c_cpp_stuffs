#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
typedef long long ll;
unordered_map<ll, bool> mp;
vector<ll> h, p;
#define maxN 301
int dp[maxN];
ll A = 9973, B = (int) 1e9+9;

public:

ll hash(int l, int r) {
    return (h[r+1] - (h[l] * p[r-l+1]) % B + B) % B;
}

bool dynamic(string& s, int r) {
    if(r == -1) return true;
    if(dp[r] != -1) return dp[r];

    for(int l = r; l >= 0; l--) {
        //cout << hash(l, r) << '\n';
        if(mp[hash(l, r)] && dynamic(s, l-1)) {
            dp[r] = true;
            return true;
        }
    }
    return false;
}

bool wordBreak(string s, vector<string>& wd) {
    for(int i =0 ;i < maxN; i++) dp[i] = -1;
    //cout << '\n';
    for(int i = 0; i < wd.size(); i++) {
        ll hsh = 0;
        for(int j = 0; j < wd[i].size(); j++) hsh = ((hsh * A) % B + wd[i][j]) % B;
        mp[hsh] = true;
        //cout << hsh << '\n';
    }
    //cout << '\n';

    h.resize(s.size()+1), p.resize(s.size()+3);
    p[0] = 1, h[0] = 1;
    for(int i = 1; i < p.size(); i++) p[i] = (p[i-1] * A) % B;
    for(int i = 1; i < h.size(); i++) h[i] = ((h[i-1] * A) % B + s[i-1]) % B;

    return dynamic(s,s.size()-1);
}
};
*/
class Solution {

typedef long long ll;
unordered_map<ll, bool> mp;
vector<ll> h, p;
ll A = 9973, B = (int) 1e9+9;

public:
bool wordBreak(string s, vector<string>& wd) {
    for(int i = 0; i < wd.size(); i++) {
        ll hsh = 0;
        for(int j = 0; j < wd[i].size(); j++) 
            hsh = ((hsh * A) % B + wd[i][j]) % B;
        mp[hsh] = true;
    }

    h.resize(s.size()+1), p.resize(s.size()+1);
    p[0] = 1, h[0] = 1;
    for(int i = 1; i < p.size(); i++) p[i] = (p[i-1] * A) % B;
    for(int i = 1; i < h.size(); i++) h[i] = ((h[i-1] * A) % B + s[i-1]) % B;

    auto hash = [&] (int l, int r) -> ll{
        return (h[r+1] - (h[l] * p[r-l+1]) % B + B) % B;
    };
    
    vector<bool> dp(s.size());
    for(int i = 0; i < s.size(); i++) {
        //cout<< "Happened at mp(hash(0, i))\n";
        if(mp[hash(0, i)]) {
            dp[i] = true;
            continue;
        }
        for(int j = 0; j < i; j++) {
            //cout << "Reached here.\n";
            //cout << "Happened at mp(hash(j+1, i))\n";
            if(mp[hash(j+1, i)] && dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}
};

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> vs;
    while(n--) {
        string t;
        cin >> t;
        vs.push_back(t);
    }
    Solution sol;
    cout << sol.wordBreak(s, vs) << '\n';
}