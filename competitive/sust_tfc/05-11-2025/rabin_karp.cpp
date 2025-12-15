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

typedef long long ll;

//Rabin Karp #1
//Precomputes the value and then evaluates the table.
//Make h 1 based index and p 0 based index
//O(n)
vector<int> rabin_karp_1(string s, string t) {
    ll a = 538243, b = 101111111111;
    vector<ll> h(s.size()+1), p(s.size());
    h[0] = p[0] = 1;
    for(int i = 0 ; i < s.size(); i++) 
        h[i+1] = (((h[i] * a) % b) + s[i]) % b;
    for(int i = 1 ; i < s.size(); i++)
        p[i] = (p[i-1]* a) % b;
    
    //Returns the hashval of any range
    auto hashval = [&h, &p, &a, &b] (int l, int r) -> ll {
        return (h[r] - (h[l-1] * p[r-l+1]) % b + b) % b;
    };

    ll hash = 0;
    for(int i = 0 ; i < t.size(); i++)
        hash = ((hash * a) % b + t[i]) % b;
    
    vector<int> ans;
    for(int i = t.size()-1, j = 0; i < s.size(); i++, j++) {
        if(hash == hashval(j, i))
            ans.push_back(j-1);
        
        // cout << s.substr(j, t.size()) << '\t' << hashval(j, i) << '\n';
    }
    cout << '\n';
    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;
    for(auto x : rabin_karp_1(s, t))
        cout << s.substr(x, t.size()) << '\n';
}