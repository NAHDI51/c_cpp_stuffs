/*
#include <bits/stdc++.h>
using namespace std;

#define MAX 500002
int main() {
    int q;
    cin >> q;
    vector<int> idx[MAX];
    int n = 0;

    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int a;
            cin >> a;
            idx[a].push_back(n++);
        } else {
            int a, b;
            cin >> a >> b;
            if(idx[a].size() > idx[b].size()) idx[a].swap(idx[b]);

            for(int i = idx[a].size()-1; i >= 0; i--) idx[b].push_back(idx[a][i]), idx[a].pop_back();
        }
    }
    vector<int> ans(n);
    for(int i = 0; i < MAX; i++) {
        for(auto w : idx[i])
            ans[w] = i;
    }
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
}

*/
#include <bits/stdc++.h>

using namespace std;

const int N = 500 * 1000 + 13;

int n, q;
vector<int> pos[N];

int main() {
  scanf("%d", &q);
  while (q--) {
    int t, x, y;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d", &x);
      pos[x].push_back(n++);
    } else {
      scanf("%d%d", &x, &y);
      if (x != y) {
        if (pos[x].size() > pos[y].size()) pos[x].swap(pos[y]);
        for (int &i : pos[x]) pos[y].push_back(i);
        pos[x].clear();
      }
    }
  }
  vector<int> ans(n);
  for (int x = 0; x < N; ++x)
    for (int &i : pos[x]) 
      ans[i] = x;
  for (int &x : ans) printf("%d ", x);
} 