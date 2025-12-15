#include <bits/stdc++.h>
using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int>& a, int k) {
    vector<int> pref(a.size()+1);
    pref[0] = 0;
    for(int i = 1; i < pref.size(); i++) pref[i] = pref[i-1] + a[i-1];
    vector<pair<int, int>> dp1(pref.size()), dp2(pref.size());

    dp1[k].first = 0, dp1[k].second = k;
    for(int i = 1, j = k+1; j < pref.size(); j++, i++) {
        if((pref[j] - pref[i]) > (pref[dp1[j-1].second] - pref[dp1[j-1].first]))
            dp1[j].first = i, dp1[j].second = j;
        else 
            dp1[j].first = dp1[j-1].first, dp1[j].second = dp1[j-1].second;
    }
    dp2[dp2.size()-1].second = pref.size()-1, dp2[dp2.size()-1].first = pref.size()-1-k;
    for(int j = dp2.size()-2, i = j-k; i >= 0; i--, j--) {
        if((pref[j] - pref[i]) >= (pref[dp2[j+1].second] - pref[dp2[j+1].first]))
            dp2[j].first = i, dp2[j].second = j;
        else
            dp2[j].first = dp2[j+1].first, dp2[j].second = dp2[j+1].second;
    }

    int mx_val = 0;
    vector<int> ans;
    for(int i = 0; i+(3*k) < pref.size() ; i++) {
        int cand = ((pref[dp1[i+k].second] - pref[dp1[i+k].first]) + (pref[i+(2*k)] - pref[i+k]) + (pref[dp2[i+(3*k)].second] - pref[dp2[i+(3*k)].first]));
        if(mx_val < cand) {
            mx_val = cand;
            ans = {dp1[i+k].first, i+k, dp2[i+(3*k)].first};
        }
    }
    return ans;
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
    for(auto x : maxSumOfThreeSubarrays(a, k))
        cout << x << "  ";
    cout << '\n';
}