#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isIsomorphic(string s, string t) {
  map<int, int> srec, trec;
  for (int i = 0; i < s.length(); i++)
    srec[s[i]]++, trec[t[i]]++;
  if (srec.size() != trec.size())
    return false;

  vector<int> socc, tocc;
  for (auto x : srec)
    socc.push_back(x.second);
  for (auto x : trec)
    tocc.push_back(x.second);

  if (socc != tocc) {
    cout << "Reached here.\n";
    return false;
  }
  return true;
}
int main() {
  string s, t;
  cin >> s >> t;
  cout << isIsomorphic(s, t) << endl;
}