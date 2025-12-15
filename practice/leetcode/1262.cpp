#include <bits/stdc++.h>
using namespace std;

//ALGORITH
/*
There are numerous ways to solve this problem.

1. Make an array of heap of size 3. Denote index by: a[i] % 3;
2. Make another array ai, that stores remainders. If a[i] % 3 == 3, make it negative modulo residue: e.g ai[i] -= a[i]%3 - 3;
3. Whilte going. heap[a[i]%3].push(a[i]);
3. If count(a[i], -1) > count(a[i], 1), two_c = count(a[i], 1) + ((count(a[i], -1) - count(a[i], 1)) % 3), one_c = count(a[i], 1),
    otherwise, reverse the values.
4. Take all the values of heap[0], one_c vals of heap[1], two_c values of heap[2].
5. Add them all and return.
*/

int maxSumDivThree(vector<int>& a) {
    vector<priority_queue<int>> pq(3);
    int sm = 0;
    for(int i = 0; i < a.size(); i++) {
        pq[a[i]%3].push(a[i]);
        if(a[i]%3 == 0) sm += a[i];
    }
    int grt;
    int ext = abs((int)(pq[1].size() - pq[2].size()));
    if(pq[1].size() >= pq[2].size()) grt = 1;
    else grt = 2;

    int c_one, c_two;
    if(grt == 2) c_one = pq[1].size();
    else c_two = pq[2].size();

    while((ext * grt) % 3 != 0) ext--;

    if(grt == 2) c_two = c_one+ext;
    else c_one = c_two + ext;
    
    int c1 = 0, c2 = 0;
    while(c1 != c_one) sm += pq[1].top(), pq[1].pop(), c1++;
    while(c2 != c_two) sm += pq[2].top(), pq[2].pop(), c2++;
x
    return sm;
}

int main() {
    int n;

    cin >> n;
    vector<int> a;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << maxSumDivThree(a) << '\n';
}