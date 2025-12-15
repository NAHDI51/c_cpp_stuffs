#include <bits/stdc++.h>
using namespace std;

//Algorithm
/*
WE will take two min values.
1. The value that always assume that the numbers are swapped.
2. The value that always assume that the numbers are not swapped.

//Finding the minimum of two of these stuffs will give us our answer.
*/
int minSwap(vector<int>& a, vector<int>& b) {
    int dp1 = 0, dp2 = 1;
    //a[i], b[i] = b[i], a[i];
    //There will be some cases where we'll be forced or forced not to swap.
    //There is only 4 cases to consider. -> if the previous was swapped (1) or not (2), if the current one is swapped (1) or not (2).
    for(int i = 1; i < a.size(); i++) {
        int tmp1 = dp1, tmp2 = dp2;
        //Both good
        if(a[i] > a[i-1] && b[i] > b[i-1] && a[i] > b[i-1] && b[i] > a[i-1]) {
            dp1 = min(tmp1, tmp2);
            dp2 = min(tmp1+1, tmp2+1);
            continue;
        }
        //Straight good
        if(a[i] > a[i-1] && b[i] > b[i-1]) dp1 = tmp1, dp2 = tmp2+1;
        else if(a[i] > b[i-1] && b[i] > a[i-1]) dp1 = tmp2, dp2 = tmp1+1;
    }
    return min(dp1, dp2);
}

int main() {
    vector<int> a, b;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        b.push_back(m);
    }
    cout << minSwap(a, b) << '\n';
}