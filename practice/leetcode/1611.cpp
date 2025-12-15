#include <bits/stdc++.h>
using namespace std;

//Keep two variables, one that always assumes that the prev bit is 1, the rest are 0 
//another that always assumes otherwise.
int minimumOneBitOperations(int n) {
    //Mins.first assumes 0, mins.second assumes 1.
    pair<int, int> m;
    m.first = (n & 1) ? 1 : 0;
    m.second = m.first ^ 1;

    int t = 31;
    while(!(n & (1 << t))) t--;

    for(int i = 1; i <= t; i++) {
        int tmp1 = m.first, tmp2 = m.second;
        //If by default, 1.
        if(n & (1 << i)) {
            m.second = tmp1;
            m.first = tmp2 + 1 + ((1 << i) - 1);
        } else {
            m.first = tmp1;
            m.second = tmp2 + 1 + ((1 << i) - 1);
        }
        //cout << m.first << '\t' << m.second << '\n';
    }
    return m.first;
}

int main() {
    int n;
    cin >> n;
    cout << minimumOneBitOperations(n) << '\n';
}