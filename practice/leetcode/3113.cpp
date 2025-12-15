#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// Maintain a range query max using fenwick or segment tree

/*
Clang is a very shitty compiler for competitive programming
And the error it flags, added with the shitty intellisense would make a
very horrible competitive programming experience.
*/
class seg {
private:
  vector<int> arr;
  static const long long MAX = 10e9 + 7;
  static const long long MIN = -MAX;
  int size;

public:
  seg(vector<int> array) {
    arr.resize(array.size() * 2 + 5, MIN);
    size = array.size();
    for (int i = 0; i < array.size(); i++)
      upd(i, array[i]);
  }
  int rng(int a, int b) {
    a += size, b += size;
    int ans = MIN;
    while (a <= b) {
      if (a % 2 == 1)
        ans = max(ans, arr[a++]);
      if (b % 2 == 0)
        ans = max(ans, arr[b--]);
      a /= 2, b /= 2;
    }
    return ans;
  }
  void upd(int ind, int a) {
    ind += size, arr[ind] = a;
    for (ind >>= 1; ind >= 1; ind >>= 1)
      arr[ind] = max(arr[ind * 2], arr[ind * 2 + 1]);
  }
};

long long numberOfSubarrays(vector<int> &nums) {
  seg fen(nums);
  long long ans = 0;
  map<int, queue<int>> occur;
  for (int i = 0; i < nums.size(); i++) {
    occur[nums[i]].push(i);
    while (fen.rng(occur[nums[i]].front(), i) > nums[i]) {
      occur[nums[i]].pop();
    }
    ans += occur[nums[i]].size();
  }
  return ans;
}

int main() {
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < nums.size(); i++)
    cin >> nums[i];
  cout << numberOfSubarrays(nums);
}