#include <bits/stdc++.h>
using namespace std;

void manacher(const string &s, vector<int> &d1, vector<int> &d2) {
    int n = s.size();
    d1.assign(n, 0);
    d2.assign(n, 0);

    // Odd-length palindromes
    int l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
        d1[i] = k;
        if (i + k - 1 > r) l = i - k + 1, r = i + k - 1;
    }

    // Even-length palindromes
    l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) k++;
        d2[i] = k;
        if (i + k - 1 > r) l = i - k, r = i + k - 1;
    }
}


int main() {
    string s;
    cin >> s;
    cout << manacher(s) << '\n';
}