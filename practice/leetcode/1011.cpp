#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int>& w, int d) {

}    

int main() {
    vector<int> a;
    int n = 10;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    sort(a.begin(), a.end());
    for(auto x : a) 
        cout << x << "  ";
    cout << '\n';
}