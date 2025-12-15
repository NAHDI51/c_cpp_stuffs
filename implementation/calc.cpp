#include <bits/stdc++.h>
using namespace std;



int main() {
    vector<int> a = {8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309};
    int sm = 0;
    for(auto x : a) sm += x;
    cout << sm << '\n';
}