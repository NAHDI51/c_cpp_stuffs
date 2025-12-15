#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n=nums.size();
    int res=INT_MIN;
    int cur= 0 ;
    for(int i=0; i <n ; i++){
        cur+=nums[i];
        res = max(res ,cur);
        if(cur<0) cur=0;
    }
    return res;
}

int main() {
    vector<int> a;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << maxSubArray(a) << '\n';
}