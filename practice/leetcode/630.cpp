#include <bits/stdc++.h>
using namespace std;

//TLE
class comp {
bool operator()(pair<int, int>& a, pair<int, int>& b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
};
/*
int scheduleCourse(vector<vector<int>>& a) {
    vector<priority_queue<int, vector<int>, greater<int>>> pq(10001);
    sort(a.begin(), a.end(), comp{});

    pq[0].push(0);
    int mx_el = 0;

    for(int i = 0; i < a.size(); i++) {
        int k;
        for(k = mx_el; k >= 0; k--) {
            if(pq[k].top()+a[i][0] <= a[i][1]) {
                pq[k+1].push(pq[k].top()+a[i][0]);
                if(k+1 > mx_el) mx_el = k+1;
            }
        }
    }
    return mx_el;
}
*/

/*
//A little optimized previous body (WA)
int scheduleCourse(vector<vector<int>>& a) {
    vector<priority_queue<int, vector<int>, greater<int>>> pq(10001);
    sort(a.begin(), a.end(), comp{});

    pq[0].push(0);
    int mx_el = 0;

    for(int i = 0; i < a.size(); i++) {
        int k;
        for(k = mx_el; k >= 0; k--) 
            if(pq[k].top()+a[i][0] <= a[i][1]) break;
        
        if(k != -1) pq[k+1].push(pq[k].top()+a[i][0]);
        if(k+1 > mx_el) mx_el = k+1;
    }
    return mx_el;
}
*/

/*
Now if it reduces time, but apparently the time still exceeds, what are you gonna do?
Well, first of all, let's observe. If we sort the array according to their finishing time,
this is going to be one lasting invariant.

We gonna try two ways.
1. Keep popping until the latest element becomes valid
2. pop iff the top element is bigger than the highest element, and removing it reduces the total cost.
*/

/*
The idea is to keep the largest subset possible with minimum sum, that does not exceed the time 
limit which is increasing strictly and monotonically. That is why, when we encounter a exceed,
we can remove the largest element and the total element remains same with the sum decreasing. Else if,
we have an encounter that doesn't exceed, we can straight pick it up, because it causes no other harms.
*/
int scheduleCourse(vector<vector<int>>& a) {
    sort(a.begin(), a.end(), comp{});
    priority_queue<int> pq;
    int sm = 0;

    for(int i = 0; i < a.size(); i++) {
        sm += a[i][0];
        pq.push(a[i][0]);
        if(sm > a[i][1]) sm -= pq.top(), pq.pop();
    }
    return pq.size();
}
/*
My thought process was like what the fuck the whole time. 
Firstly, I got a gist that this one is solvable using dynamic programming, as a 
variant of knapsack prbolem, but implementing such algorithm would yield TLE. Thus,
I was constantly looking for a Greedy Approach. How did I derive such algorithm finally?

The key idea is the fact that for each of the deadline, we need the HIGHEST sized set of elements,
thus, we need a way to CONSTANTLY SWAP THE highest element over and over. why would that work?
Because, if we swap the highet element with some other elements, we are simply shrinking our
sum, with the cost of losing no elements, and keeping our constraints clean, and valid.


*/


int main() {
    vector<vector<int>> v;
    int n;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    cout << scheduleCourse(v) << '\n';
}