#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool solve() {
  string str1, str2;

  cin >> str1 >> str2;

  vector<int> occ(128, 0); // Number of times each char appears in s1
  for (int i = 0; i < str1.length(); i++)
    occ[str1[i]]++;

  vector<int> found(128, 0);
  for (int i = 0, j = 0; i < str2.length(); i++) {
    found[str2[i]]++;
    while (j <= i && found[str2[i]] > occ[str2[i]])
      found[str2[j]]--, j++;
    if (found == occ)
      return true;
  }
  queue<int> q;
}

int main() { solve() ? cout << "true" << endl : cout << "false" << endl; }