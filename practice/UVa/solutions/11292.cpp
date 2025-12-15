#include <bits/stdc++.h>
using namespace std;

//Greedy ivnariant: The fact that sorting the time and then solving directly for the minimum possible wage is the best answer.
//Line sweep after sorting.

int main() {
while(1) {
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    if(n > m) {
        cout << "Loowater is doomed!\n";
        continue;
    }

    vector<int> drag(n), knight(m);
    for(int i = 0; i < n; i++) cin >> drag[i];
    for(int i = 0; i < m; i++) cin >> knight[i];

    sort(drag.begin(), drag.end());
    sort(knight.begin(), knight.end());

    int j = 0;
    int gold = 0;
    for(int i = 0; i < knight.size(); i++) {
        if(j == drag.size()) break;
        if(knight[i] >= drag[j]) gold += knight[i], j++;
    }
    if(j == drag.size()) cout << gold << '\n';
    else cout << "Loowater is doomed!\n";
}
}