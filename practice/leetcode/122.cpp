#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& p) {
    int ans = 0;
    for(int i = 0 ;i < p.size(); i++) {
        int bs = i;
        while(i+1 < p.size() && p[i] < p[i+1]) i++;
        if(bs != i) ans += p[i]-p[bs];
    }
    return ans;
}

int main() {

}
