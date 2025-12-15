#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int tar;
  vector<vector<int>> ans;

public:
  void backtrack(int ind, int sum, vector<int> &cur, vector<int> &cand) {
    // cout << sum << '\n';
    if (sum == tar) {
      ans.push_back(cur);
      return;
    }
    if (sum > tar) {
      return;
    }
    if (ind == cand.size())
      return;
    for (int i = 0; i < 30; i++) {
      backtrack(ind + 1, sum + cand[ind] * i, cur, cand);
      cur.push_back(cand[ind]);
    }
    for (int i = 0; i < 30; i++) {
      cur.pop_back();
    }
    return;
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    tar = target;
    vector<int> cur;
    backtrack(0, 0, cur, candidates);
    return ans;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> cand(n);
  for (int i = 0; i < n; i++)
    cin >> cand[i];
  int target;
  cin >> target;
  Solution solve;

  vector<vector<int>> sol = solve.combinationSum(cand, target);
  for (auto x : sol) {
    for (auto y : x)
      cout << y << ' ';
    cout << '\n';
  }
}