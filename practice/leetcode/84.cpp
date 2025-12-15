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

int largestRectangleArea(vector<int>& a) {
    vector<int> st;
    int mx = 0;
    for(int i = 0; i < a.size(); i++) {
        while(!st.empty() && a[st.back()] > a[i]) {
            int cur = st.back();
            st.pop_back();
            if(!st.empty()) mx = max(mx, a[cur] * ((i-1) - (st.back()+1) + 1));
            else mx = max(mx, a[cur] * (i));
        }
        st.push_back(i);
    }
    while(!st.empty()) {
        int cur = st.back();
        st.pop_back();
        if(!st.empty()) mx = max(mx, (int) (a[cur] * ((a.size()-1) - (st.back()+1) + 1)));
        else mx = max(mx, (int) (a[cur] * (a.size())));
    }
    return mx;
}

int main() {
    vector<int> a;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << largestRectangleArea(a) << '\n';
}