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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for(int i=0;i<n;i++) { cin >> a[i]; mx = max(mx,a[i]); }

    vector<vector<int>> pos(mx+2); // store positions of each value
    for(int i=0;i<n;i++) pos[a[i]].push_back(i);

    vector<int> dp(mx+2,0);
    dp[0]=0;
    dp[1]=pos[1].size();

    for(int v=2; v<=mx; v++) {
        int sz1 = pos[v-1].size();
        int sz2 = pos[v].size();
        int i=0,j=0;
        int keep=0; // max number of elements we can keep for value v without conflict

        // two pointers merge
        while(i<sz1 || j<sz2){
            int idx1 = (i<sz1? pos[v-1][i] : INT_MAX);
            int idx2 = (j<sz2? pos[v][j] : INT_MAX);
            if(idx2 < idx1){
                keep++;
                j++;
            } else {
                i++;
            }
        }
        dp[v] = dp[v-2] + keep; // best sequence keeping v
        dp[v] = max(dp[v], dp[v-1]); // or skip v entirely
    }

    cout << n - dp[mx] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
}
