#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <initializer_list>
#include <tuple>
using namespace std;
using ll = long long;

const ll MOD = 676767677;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Base case: only one wizard
        if (n == 1) {
            cout << (a[0] == 1 ? 2 : 0) % MOD << '\n';
            continue;
        }

        vector<int> d(n - 1);
        bool bad = false;
        for (int i = 0; i < n - 1; i++) {
            d[i] = a[i + 1] - a[i];
            if (abs(d[i]) > 1) bad = true;
        }
        if (bad) {
            cout << 0 << '\n';
            continue;
        }

        ll ans = 0;

        for (int start = 0; start <= 1; start++) {
            vector<int> x(n);
            x[0] = start;
            bool ok = true;
            for (int i = 0; i < n - 1; i++) {
                x[i + 1] = (d[i] + 1) - x[i];
                if (x[i + 1] != 0 && x[i + 1] != 1) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            // Verify that this x really generates array a
            vector<int> L(n), R(n), a2(n);
            for (int i = 0; i < n; i++) {
                L[i] = (i ? L[i - 1] : 0) + x[i];
            }
            R[n - 1] = (x[n - 1] == 0);
            for (int i = n - 2; i >= 0; i--) {
                R[i] = R[i + 1] + (x[i] == 0);
            }
            for (int i = 0; i < n; i++) {
                a2[i] = L[i] + R[i];
            }
            if (a2 == a) ans++;
        }

        cout << (ans % MOD) << '\n';
    }

    return 0;
}
