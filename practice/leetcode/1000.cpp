#include <bits/stdc++.h>
using namespace std;

//Let this map keep the minimum of the unique entries
map<vector<int>, int> dp;
#define MAX 1000000
int mergeStones(vector<int> s, int k) {
    //cout << "Reached heere.\n";
    if(s.size() < k) return -1;
    else if(s.size() == k) {
        int sm = 0;
        for(auto x : s) sm += 0;
        dp[s] = sm;
    }
    auto it = dp.find(s);
    if(it != dp.end()) return it->second;

    auto sum = dp[s];
    sum = MAX;
    for(int i = 0; i < s.size(); i++) {
        vector<int> v;
        int sm = 0;
        //cout << "Reached here.\n";
        if((i+k) <= s.size()) {
            for(int j = i; j < i+k; j++) sm += s[j];
            //cout << "reached here.\n";
            for(int l = 0; l < i; l++) v.push_back(s[l]);
            v.push_back(sm);
            for(int l = i+k; l < s.size(); l++) v.push_back(s[l]);

            for(auto x : v) cout << x << '\t';
            cout << '\n';

            int res = mergeStones(v, k);
            if(res != -1) sum = min(sum , res+sm);
        }
    }
    if(sum == MAX) sum = -1;
    return sum;
}

int main() {
    vector<int> a;
    int n, k;
    cin >> n >> k;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << mergeStones(a, k) << '\n';
}